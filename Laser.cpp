#pragma once
#include "Laser.h"
#include "BaseMonster.h"
#include "GameManager.h"

bool Laser::init() {
	if (!Sprite::init()) {
		return false;
	}
	bulletSprite = Sprite::createWithSpriteFrameName(".png");
	addChild(bulletSprite);
	return true;
}

BaseBullet::BaseBullet() :bulletSprite(NULL), maxForce(0), bulletScope(0)
{
}

void Laser::shoot()
{
	runAction(Sequence::create(bulletAction,
		CallFuncN::create(CC_CALLBACK_0(Laser::removeBullet, this)),
		NULL));
}

void Laser::removeLaser() {
	GameManager * instance = GameManager::getInstance();
	auto LaserRect = Rect(this->getPositionX() + this->getParent()->getPositionX() - this->getContentSize().width / 2,
		this->getPositionY() + this->getParent()->getPositionY() - this->getContentSize().height / 2,
		this->bulletSprite->getContentSize().width,
		this->bulletSprite->getContentSize().height);


	auto monsterVector = instance->monsterVector;
	for (int i = 0; i < monsterVector.size(); i++) {
		auto monster = monsterVector.at(i);
		auto monsterRect = monster->monsterSprite->getBoundingBox();

		if (monster != NULL && monsterRect.intersectsRect(LaserRect) && monster->getAttackByDoll()) {
			auto curHp = monster->getCurHp();
			curHp = curHp - this->getMaxForce();
			if (curHp <= 0) {
				curHp = 0;
			}
			monster->setCurHP(curHp);
			monster->getHpBar()->setPercentage((curHp / monster->getMaxHp()) * 100);
			if (curHp == 0) {
				monster->death();
			}
			continue;
		}
	}
	this->removeFromParent();
}
