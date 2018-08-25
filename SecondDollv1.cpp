#include "SecondDollv1.h"
#include "SecondDollv2.h"
#include "GameManager.h"
#include "UpdateMenu.h"
#include "BaseLevel.h"
#include "Laser.h"


bool SecondDollv1::init() {
	if (!Sprite::init()) {
		return false;
	}
	setDollType(SECONDDOLL_1);
	setLevel(1);
	addGourd();
	updateAnimation();

	setScope(160.0f);
	setUpdateGourd(150);
	setFosterGourd(120);
	isUpdateMenuShown = false;
	return true;
}

void SecondDollv1::updateAnimation() {
	auto update = Sprite::create();
	auto shape = Sprite::createWithSpriteFrameName(".png");
	update->addChild(shape);
	addChild(update);
	scheduleOnce(schedule_selector(SecondDollv1::updateEffectAnimation), 0.5f);
}

void SecondDollv1::updateEffectAnimation(float dt) {
	auto effect = Sprite::createWithSpriteFrameName(".png");
	addChild(effect, 99);
	effect->runAction(Sequence::create(Animate::create(AnimationCache::getInstance()->getAnimation(" ")), CallFuncN::create(CC_CALLBACK_0(Sprite::removeFromParent, effect)), NULL));
	//ÒôÐ§
	initDoll(1);
	setListener();
	schedule(schedule_selector(SecondDollv1::shoot), 3.0f);
}

void SecondDollv1::updateDoll() {
	auto firstDollv2 = SecondDollv2::create();
	firstDollv2->setMyGourd(myGourd);
	firstDollv2->setTag(myGourd->getTag());
	firstDollv2->setPosition(Point(0, 20));
	myGourd->addChild(firstDollv2);
	this->removeDoll();
}

void SecondDollv1::showUpdateMenu() {
	auto updateMenu = UpdateMenu::create();
	updateMenu->setTag(myGourd->getTag() + 100);
	updateMenu->setGourd(this);
	updateMenu->setPosition(this->getParent()->getPosition());
	static_cast<BaseLevel*>(this->getParent()->mTouchLayer->addChild(updateMenu));
	if (GameManager::getInstance()->LEVEL <= 0) {
		updateMenu->canUpdate = false;
	}
	updateMenu->playAnimation();
	isUpdateMenuShown = true;
}

BaseBullet * SecondDollv1::SecondDollBullet() {
	auto secondDollBullet = Laser::create();
	secondDollBullet->setPosition(Point(40, 45));
	secondDollBullet->setMaxForce(15);
	this->getParent()->addChild(secondDollBullet);
	return secondDollBullet;

}