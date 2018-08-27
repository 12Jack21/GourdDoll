#include "FourthDollv1.h"
#include "FourthDollv2.h"
#include "GameManager.h"
#include "UpdateMenu.h"
#include "BaseLevel.h"
#include "FireBall.h"


bool FourthDollv1::init() {
	if (!Sprite::init()) {
		return false;
	}
	setDollType(FOURTHDOLL_1);
	setLv(1);
	addGourd();
	updateAnimation();

	setScope(160.0f);
	setUpdateGourd(150);
	setFosterGourd(120);
	isUpdateMenuShown = false;
	return true;
}

void FourthDollv1::updateAnimation() {
	auto update = Sprite::create();
	auto shape = Sprite::createWithSpriteFrameName(".png");
	update->addChild(shape);
	addChild(update);
	scheduleOnce(schedule_selector(FourthDollv1::updateEffectAnimation), 0.5f);
}

void FourthDollv1::updateEffectAnimation(float dt) {
	auto effect = Sprite::createWithSpriteFrameName(".png");
	addChild(effect, 99);
	effect->runAction(Sequence::create(Animate::create(AnimationCache::getInstance()->getAnimation(" ")), CallFuncN::create(CC_CALLBACK_0(Sprite::removeFromParent, effect)), NULL));
	//音效
	initDoll(1);
	setListener();
	schedule(schedule_selector(FourthDollv1::shoot), 3.0f);
}

void FourthDollv1::updateDoll() {
	auto fourthDollv2 = FourthDollv1::create();
	fourthDollv2->setMyGourd(myGourd);
	fourthDollv2->setTag(myGourd->getTag());
	fourthDollv2->setPosition(Point(0, 20));
	myGourd->addChild(fourthDollv2);
	this->removeDoll();
}

void FourthDollv1::showUpdateMenu() {
	auto updateMenu = UpdateMenu::create();
	updateMenu->setTag(myGourd->getTag() + 100);
	updateMenu->setDoll(this);
	updateMenu->setPosition(this->getParent()->getPosition());
	static_cast<BaseLevel*>(this->getParent()->getParent())->mTouchLayer->addChild(updateMenu);
	if (GameManager::getInstance()->LEVEL <= 0) {
		updateMenu->canUpdate = false;
	}
	updateMenu->inAnimation();
	isUpdateMenuShown = true;
}

BaseBullet * FourthDollv1::FourthDollBullet() {
	auto fourthDollBullet = FireBall::create();
	fourthDollBullet->setPosition(Point(40, 45));
	fourthDollBullet->setMaxForce(20);
	this->getParent()->addChild(fourthDollBullet);
	return fourthDollBullet;

}
void FourthDollv1::shoot(float dt) {
	auto instance = GameManager::getInstance();
	checkNearestMonster();
	if (nearestMonster != NULL && nearestMonster->getCurHp() > 0) {
		auto curBullet = FourthDollBullet();
		//四娃娃的游戏音效SoundManager::

		Point shootVector = nearestMonster->monsterSprite->getPosition() - this->getParent()->getPosition();

		auto position = curBullet->getPosition() - shootVector;
		auto rotation = atan2(position.y, position.x);
		float angle = CC_RADIANS_TO_DEGREES(rotation);
		curBullet->setRotation(180.0f - angle);

		dollBase->runAction(Animate::create(AnimationCache::getInstance()->getAnimation(String::createWithFormat(" ", lv)->getCString())));
		//动画需加
		auto move = MoveTo::create(0.25f, shootVector);
		auto action = Spawn::create(move, NULL);
		curBullet->setBulletAction(action);
		curBullet->shoot();
		curBullet = NULL;
	}
}