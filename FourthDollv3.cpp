#include "FourthDollv3.h"
#include "UpdateMenu.h"
#include "GameManager.h"
#include "BaseLevel.h"
#include "FireBall.h"

bool FourthDollv3::init() {
	if (!Sprite::init()) {
		return false;
	}
	setDollType(FOURTHDOLL_3);
	setLevel(2);
	addGourd();
	initDoll(3);
	setScope(180.0f);
	setUpdateGourd(230);
	setFosterGourd(500);
	isUpdateMenuShown = false;
	schedule(schedule_selector(FourthDollv3::shoot), 2.0f);
	//该音效可要可不要
	SoundManager::playDollUpdate();
	return true;
}

BaseBullet* FourthDollv3::FourthDollBullet()
{
	auto fourthDollBullet = FireBall::create();
	fourthDollBullet->setPosition(Point(10, 45));
	fourthDollBullet->setMaxForce(65);
	this->getParent()->addChild(fourthDollBullet);
	return fourthDollBullet;
}