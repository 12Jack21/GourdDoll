#include "WaterBall.h"
#include "GameManager.h"
#include "BaseMonster.h"

bool WaterBall::init() {
	if (!Sprite::init()) {
		return false;
	}
	bulletSprite = Sprite::createWithSpriteFrameName(".png");
	addChild(bulletSprite);
	this->setMaxForce(200);
	return true;
}

void WaterBall::shoot() {
	runAction(Sequence::create(bulletAction, CallFuncN::create(CC_CALLBACK_0(WaterBall::removeWaterBall, this)), NULL));
}

void WaterBall::removeWaterBall() {
	GameManager * instance = GameManager::getInstance();
	auto waterballRect = Rect(this->getPositionX() + this->getParent()->getPositionX() - this->getContentSize().width / 2,
		this->getPositionY() + this->getParent()->getPositionY() - this->getContentSize().height / 2,
		this->bulletSprite->getContentSize().width,
		this->bulletSprite->getContentSize().height);

	auto monsterVector = instance->monsterVector;
	for (int i = 0; i < monsterVector.size(); i++) {
		auto monster = monsterVector.at(i);
		auto monsterRect = monster->monsterSprite->getBoundingBox();

		if (monster != NULL && monsterRect.intersectsRect(waterballRect) && monster->getAttackByDoll()) {
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