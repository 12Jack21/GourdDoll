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
	setLevel(2);
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
	static_cast<BaseLevel*>(this->getParent()->mTouchLayer->addChild(updateMenu));
	if (GameManager::getInstance()->LEVEL <= 0) {
		updateMenu->canUpdate = false;
	}
	updateMenu->playAnimation();
	isUpdateMenuShown = true;
}

BaseBullet * FourthDollv2::FourthDollBullet() {
	auto fourthDollBullet = FireBall::create();
	fourthDollBullet->setPosition(Point(10, 45));
	fourthDollBullet->setMaxForce(40);
	this->getParent()->addChild(fourthDollBullet);
	return fourthDollBullet;

}