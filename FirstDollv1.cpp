#include "FirstDollv1.h"
#include "FirstDollv2.h"
#include "GameManager.h"
#include "UpdateMenu.h"
#include "BaseLevel.h"


bool FirstDollv1::init() {
	if (!Sprite::init()) {
		return false;
	}
	setDollType(FIRSTDOLL_1);
	setLevel(1);
	addGourd();
	updateAnimation();

	setScope(160.0f);
	setUpdateGourd(150);
	setFosterGourd(120);
	isUpdateMenuShown = false;
	return true;
}

void FirstDollv1::updateAnimation() {
	auto update = Sprite::create();
	auto shape = Sprite::createWithSpriteFrameName(/*文件名*/);
	update->addChild(shape);
	addChild(update);
	scheduleOnce(schedule_selector(FirstDollv1::updateEffectAnimation), 0.5f);
}

void FirstDollv1::updateEffectAnimation(float dt) {
	auto effect = Sprite::createWithSpriteFrameName(/*文件名*/);
	addChild(effect, 99);
	effect->runAction(Sequence::create(Animate::create(AnimationCache::getInstance()->getAnimation(/*文件名*/)), CallFuncN::create(CC_CALLBACK_0(Sprite::removeFromParent, effect)), NULL));
	//音效
	initDoll(1);
	setListener();
	schedule(schedule_selector(FirstDollv1::shoot), 3.0f);
}

void FirstDollv1::updateDoll() {
	auto firstDollv2 = FirstDollv2::create();
	firstDollv2->setMyGourd(myGourd);
	firstDollv2->setTag(myGourd->getTag());
	firstDollv2->setPosition(Point(0, 20));
	myGourd->addChild(firstDollv2);
	this->removeDoll();
}

void FirstDollv1::showUpdateMenu() {
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

BaseBullet * FirstDollv1::FirstDollBullet() {
	auto firstDollBullet = Stone::create();
	firstDollBullet->setPosition(Point(40, 45));
	firstDollBullet->setMaxForce(15);
	this->getParent()->addChild(firstDollBullet);
	return firstDollBullet;

}