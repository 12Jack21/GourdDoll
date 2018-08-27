#include "FirstDollv2.h"
#include "FirstDollv3.h"
#include "UpdateMenu.h"
#include "GameManager.h"
#include "BaseLevel.h"
#include "Stone.h"

bool FirstDollv2::init() {
	if (!Sprite::init()) {
		return false;
	}
	setDollType(FIRSTDOLL_2);
	setLevel(2);
	addGourd();
	initDoll(2);
	setScope(180.0f);
	setUpdateGourd(240);
	setFosterGourd(260);
	isUpdateMenuShown = false;
	schedule(schedule_selector(FirstDollv2::shoot), 2.0f);
	//该音效可要可不要
	SoundManager::playDollUpdate();
	return true;
}

void FirstDollv2::updateDoll() {
	auto firstDollv3 = FirstDollv3::create();
	firstDollv3->setMyGourd(myGourd);
	firstDollv3->setTag(myGourd->getTag());
	firstDollv3->setPosition(Point(0,20));
	myGourd->addChild(firstDollv3);
	this->removeDoll();
}

void FirstDollv2::showUpdateMenu() {
	auto updateMenu = UpdateMenu::create();
	updateMenu->setTag(myGourd->getTag() + 100);
	updateMenu->setDoll(this);
	updateMenu->setPosition(this->getParent()->getPosition());
	static_cast<BaseLevel*>(this->getParent()->mTouchLayer->addChild(updateMenu));
	if (GameManager::getInstance()->LEVEL <= 0) {
		updateMenu->canUpdate = false;
	}
	updateMenu->playAnimation();
	isUpdateMenuShown = true;
}

BaseBullet * FirstDollv2::FirstDollBullet() {
	auto firstDollBullet = Stone::create();
	firstDollBullet->setPosition(Point(10, 45));
	firstDollBullet->setMaxForce(30);
	this->getParent()->addChild(firstDollBullet);
	return firstDollBullet;

}