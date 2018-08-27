#include "FireBall.h"
#include "GameManager.h"
#include "BaseMonster.h"

bool FireBall::init() {
	if (!Sprite::init()) {
		return false;
	}
	bulletSprite = Sprite::createWithSpriteFrameName(".png");
	addChild(bulletSprite);
	this->setMaxForce(250);
	return true;
}
void FireBall::shoot() {
	runAction(Sequence::create(bulletAction, CallFuncN::create(CC_CALLBACK_0(FireBall::removeFireBall, this)), NULL));
}

void FireBall::removeFireBall() {
	GameManager * instance = GameManager::getInstance();
	auto fireballRect = Rect(this->getPositionX() + this->getParent()->getPositionX() - this->getContentSize().width / 2,
		this->getPositionY() + this->getParent()->getPositionY() - this->getContentSize().height / 2,
		this->bulletSprite->getContentSize().width,
		this->bulletSprite->getContentSize().height);


	auto monsterVector = instance->monsterVector;
	for (int i = 0; i < monsterVector.size(); i++) {
		auto monster = monsterVector.at(i);
		auto monsterRect = monster->monsterSprite->getBoundingBox();
		
		if (monster != NULL && monsterRect.intersectsRect(fireballRect) && monster->getAttackByTower()) {
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
			break;
		}
	}
	this->removeFromParent();
}