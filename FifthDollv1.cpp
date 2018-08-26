#include "FifthDollv1.h"
#include "FifthDollv2.h"
#include "GameManager.h"
#include "UpdateMenu.h"
#include "BaseLevel.h"
#include "WaterBall.h"


bool FifthDollv1::init() {
	if (!Sprite::init()) {
		return false;
	}
	setDollType(FIFTHDOLL_1);
	setLevel(1);
	addGourd();
	updateAnimation();

	setScope(160.0f);
	setUpdateGourd(150);
	setFosterGourd(120);
	isUpdateMenuShown = false;
	return true;
}

void FifthDollv1::updateAnimation() {
	auto update = Sprite::create();
	auto shape = Sprite::createWithSpriteFrameName(".png");
	update->addChild(shape);
	addChild(update);
	scheduleOnce(schedule_selector(FifthDollv1::updateEffectAnimation), 0.5f);
}

//升级塔时的动画效果
void FifthDollv1::updateEffectAnimation(float dt) {
	auto effect = Sprite::createWithSpriteFrameName(".png");
	addChild(effect, 99);
	effect->runAction(Sequence::create(Animate::create(AnimationCache::getInstance()->getAnimation(".png")), CallFuncN::create(CC_CALLBACK_0(Sprite::removeFromParent, effect)), NULL));
	initDoll(1);
	setListener();
	schedule(schedule_selector(FifthDollv1::shoot), 3.0f);
}

void FifthDollv1::updateDoll() {
	auto fifthDollv2 = FifthDollv2::create();
	fifthDollv2->setMyGourd(myGourd);
	fifthDollv2->setTag(myGourd->getTag());
	fifthDollv2->setPosition(Point(0, 20));
	myGourd->addChild(fifthDollv2);
	this->removeDoll();
}

void FifthDollv1::showUpdateMenu() {
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

BaseBullet * FifthDollv1::FifthDollBullet() {
	auto fifthDollBullet = WaterBall::create();
	fifthDollBullet->setPosition(Point(40, 45));
	fifthDollBullet->setMaxForce(10);
	this->getParent()->addChild(fifthDollBullet);
	return fifthDollBullet;

}