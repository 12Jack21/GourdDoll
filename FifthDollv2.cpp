#include "FifthDollv2.h"
#include "FifthDollv3.h"
#include "UpdateMenu.h"
#include "GameManager.h"
#include "BaseLevel.h"
#include "WaterBall.h"

bool FifthDollv2::init() {
	if (!Sprite::init()) {
		return false;
	}
	setDollType(FIFTHDOLL_2);
	setLv(2);
	addGourd();
	initDoll(2);
	setScope(180.0f);
	setUpdateGourd(240);
	setFosterGourd(260);
	isUpdateMenuShown = false;
	schedule(schedule_selector(FifthDollv2::shoot), 2.0f);
	//该音效可要可不要
	SoundManager::playDollUpdate();
	return true;
}

void FifthDollv2::updateDoll() {
	auto fifthDollv3 = FifthDollv3::create();
	fifthDollv3->setMyGourd(myGourd);
	fifthDollv3->setTag(myGourd->getTag());
	fifthDollv3->setPosition(Point(0, 20));
	myGourd->addChild(fifthDollv3);
	this->removeDoll();
}

void FifthDollv2::showUpdateMenu() {
	auto updateMenu = UpdateMenu::create();
	updateMenu->setTag(myGourd->getTag() + 100);
	updateMenu->setDoll(this);
	updateMenu->setPosition(this->getParent()->getPosition());
	static_cast<BaseLevel *>(this->getParent()->getParent())->mTouchLayer->addChild(updateMenu);
	if (GameManager::getInstance()->LEVEL <= 0) {
		updateMenu->canUpdate = false;
	}
	updateMenu->inAnimation();
	isUpdateMenuShown = true;
}

BaseBullet * FifthDollv2::FifthDollBullet() {
	auto fifthDollBullet = WaterBall::create();
	fifthDollBullet->setPosition(Point(10, 45));
	fifthDollBullet->setMaxForce(25);
	this->getParent()->addChild(fifthDollBullet);
	return fifthDollBullet;

}