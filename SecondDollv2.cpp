#include "SecondDollv2.h"
#include "SecondDollv3.h"
#include "UpdateMenu.h"
#include "GameManager.h"
#include "BaseLevel.h"
#include "Laser.h"

bool SecondDollv2::init() {
	if (!Sprite::init()) {
		return false;
	}
	setDollType(SECONDDOLL_2);
	setLv(2);
	addGourd();
	initDoll(2);
	setScope(180.0f);
	setUpdateGourd(240);
	setFosterGourd(260);
	isUpdateMenuShown = false;
	schedule(schedule_selector(SecondDollv2::shoot), 2.0f);
	//该音效可要可不要
	SoundManager::playDollUpdate();
	return true;
}

void SecondDollv2::updateDoll() {
	auto secondDollv3 = SecondDollv3::create();
	secondDollv3->setMyGourd(myGourd);
	secondDollv3->setTag(myGourd->getTag());
	secondDollv3->setPosition(Point(0, 20));
	myGourd->addChild(secondDollv3);
	this->removeDoll();
}

void SecondDollv2::showUpdateMenu() {
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

BaseBullet * SecondDollv2::SecondDollBullet() {
	auto secondDollBullet = Laser::create();
	secondDollBullet->setPosition(Point(10, 45));
	secondDollBullet->setMaxForce(30);
	this->getParent()->addChild(secondDollBullet);
	return secondDollBullet;

}
void SecondDollv2::shoot(float dt) {
	auto instance = GameManager::getInstance();
	checkNearestMonster();
	if (nearestMonster != NULL && nearestMonster->getCurHp() > 0) {
		auto curBullet = SecondDollBullet();
		//二娃的游戏音效SoundManager::

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