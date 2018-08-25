#include "SecondDollv3.h"
#include "UpdateMenu.h"
#include "GameManager.h"
#include "BaseLevel.h"
#include "Laser.h"

bool SecondDollv3::init() {
	if (!Sprite::init()) {
		return false;
	}
	setDollType(SECONDDOLL_3);
	setLevel(2);
	addGourd();
	initDoll(3);
	setScope(180.0f);
	setUpdateGourd(230);
	setFosterGourd(500);
	isUpdateMenuShown = false;
	schedule(schedule_selector(SecondDollv3::shoot), 2.0f);
	//该音效可要可不要
	SoundManager::playDollUpdate();
	return true;
}

BaseBullet* SecondDollv3::SecondDollBullet()
{
	auto secondDollBullet = Laser::create();
	secondDollBullet->setPosition(Point(10, 45));
	secondDollBullet->setMaxForce(50);
	this->getParent()->addChild(secondDollBullet);
	return secondDollBullet;
}