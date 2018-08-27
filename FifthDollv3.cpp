#include "FifthDollv3.h"
#include "UpdateMenu.h"
#include "GameManager.h"
#include "BaseLevel.h"
#include "WaterBall.h"

bool FifthDollv3::init() {
	if (!Sprite::init()) {
		return false;
	}
	setDollType(FIFTHDOLL_3);
	setLv(2);
	addGourd();
	initDoll(3);
	setScope(180.0f);
	setUpdateGourd(230);
	setFosterGourd(500);
	isUpdateMenuShown = false;
	schedule(schedule_selector(FifthDollv3::shoot), 2.0f);
	//该音效可要可不要
	SoundManager::playDollUpdate();
	return true;
}

BaseBullet* FifthDollv3::FifthDollBullet()
{
	auto fifthDollBullet = WaterBall::create();
	fifthDollBullet->setPosition(Point(10, 45));
	fifthDollBullet->setMaxForce(45);
	this->getParent()->addChild(fifthDollBullet);
	return fifthDollBullet;
}

void FifthDollv3::shoot(float dt) {
	auto instance = GameManager::getInstance();
	checkNearestMonster();
	if (nearestMonster != NULL && nearestMonster->getCurHp() > 0) {
		auto curBullet = FifthDollBullet();
		//五娃娃的游戏音效SoundManager::

		Point shootVector = nearestMonster->monsterSprite->getPosition() - this->getParent()->getPosition();

		auto position = curBullet->getPosition() - shootVector;
		auto rotation = atan2(position.y, position.x);
		float angle = CC_RADIANS_TO_DEGREES(rotation);
		curBullet->setRotation(180.0f - angle);

		dollBase->runAction(Animate::create(AnimationCache::getInstance()->getAnimation(String::createWithFormat(" ", lv)->getCString())));
		//动画需加
		auto move = MoveTo::create(0.25f, shootVector);
		auto action = Spawn::create(move, NULL);
		curBullet->setBulletAction(action);
		curBullet->shoot();
		curBullet = NULL;
	}
}