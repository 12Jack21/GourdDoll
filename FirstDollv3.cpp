#include "FirstDollv3.h"
#include "UpdateMenu.h"
#include "GameManager.h"
#include "BaseLevel.h"
#include "Stone.h"

bool FirstDollv3::init() {
	if (!Sprite::init()) {
		return false;
	}
	setDollType(FIRSTDOLL_3);
	setLevel(2);
	addGourd();
	initDoll(3);
	setScope(180.0f);
	setUpdateGourd(230);
	setFosterGourd(500);
	isUpdateMenuShown = false;
	schedule(schedule_selector(FirstDollv3::shoot), 2.0f);
	//需要添加音效
	return true;
}

BaseBullet* FirstDollv3::FirstDollBullet()
{
	auto firstDollBullet = Stone::create();
	firstDollBullet->setPosition(Point(10, 45));
	firstDollBullet->setMaxForce(50);
	this->getParent()->addChild(firstDollBullet);
	return firstDollBullet;
}