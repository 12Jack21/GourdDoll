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
	setLevel(2);
	addGourd();
	initDoll(3);
	setScope(180.0f);
	setUpdateGourd(230);
	setFosterGourd(500);
	isUpdateMenuShown = false;
	schedule(schedule_selector(FifthDollv3::shoot), 2.0f);
	//需要添加音效
	return true;
}

BaseBullet* FifthDollv3::FifthDollBullet()
{
	auto fifthDollBullet = Stone::create();
	fifthDollBullet->setPosition(Point(10, 45));
	fifthDollBullet->setMaxForce(45);
	this->getParent()->addChild(fifthDollBullet);
	return fifthDollBullet;
}