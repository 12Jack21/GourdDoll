#include "FourthDollv2.h"
#include "FourthDollv3.h"
#include "UpdateMenu.h"
#include "GameManager.h"
#include "BaseLevel.h"
#include "FireBall.h"

bool FourthDollv2::init() {
	if (!Sprite::init()) {
		return false;
	}
	setDollType(FOURTHDOLL_2);
	setLv(2);
	addGourd();
	initDoll(2);
	setScope(180.0f);
	setUpdateGourd(240);
	setFosterGourd(260);
	isUpdateMenuShown = false;
	schedule(schedule_selector(FourthDollv2::shoot), 2.0f);
	//该音效可要可不要
	SoundManager::playDollUpdate();
	return true;
}

void FourthDollv2::updateDoll() {
	auto fourthDollv3 = FourthDollv3::create();
	fourthDollv3->setMyGourd(myGourd);
	fourthDollv3->setTag(myGourd->getTag());
	fourthDollv3->setPosition(Point(0, 20));
	myGourd->addChild(fourthDollv3);
	this->removeDoll();
}

void FourthDollv2::showUpdateMenu() {
	auto updateMenu = UpdateMenu::create();
	updateMenu->setTag(myGourd->getTag() + 100);
	updateMenu->setDoll(this);
	updateMenu->setPosition(this->getParent()->getPosition());
	static_cast<BaseLevel*>(this->getParent()->getParent())->mTouchLayer->addChild(updateMenu);
	if (GameManager::getInstance()->LEVEL <= 0) {
		updateMenu->canUpdate = false;
	}
	updateMenu->inAnimation();
	isUpdateMenuShown = true;
}

BaseBullet * FourthDollv2::FourthDollBullet() {
	auto fourthDollBullet = FireBall::create();
	fourthDollBullet->setPosition(Point(10, 45));
	fourthDollBullet->setMaxForce(40);
	this->getParent()->addChild(fourthDollBullet);
	return fourthDollBullet;

}

void FourthDollv2::shoot(float dt) {
	auto instance = GameManager::getInstance();
	checkNearestMonster();
	if (nearestMonster != NULL && nearestMonster->getCurHp() > 0) {
		auto curBullet = FourthDollBullet();
		//四娃娃的游戏音效SoundManager::

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