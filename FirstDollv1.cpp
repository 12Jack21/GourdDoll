#include "FirstDollv1.h"
#include "FirstDollv2.h"
#include "GameManager.h"
#include "UpdateMenu.h"
#include "BaseLevel.h"
#include "Stone.h"


bool FirstDollv1::init() {
	if (!Sprite::init()) {
		return false;
	}
	setDollType(FIRSTDOLL_1);
	setLv(1);
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
	auto shape = Sprite::createWithSpriteFrameName(".png");//
	update->addChild(shape);
	addChild(update);
	scheduleOnce(schedule_selector(FirstDollv1::updateEffectAnimation), 0.5f);
}

void FirstDollv1::updateEffectAnimation(float dt) {
	auto effect = Sprite::createWithSpriteFrameName(".png");//升级拆塔
	addChild(effect, 99);//升级拆塔动画
	effect->runAction(Sequence::create(Animate::create(AnimationCache::getInstance()->getAnimation("updateDoll")), CallFuncN::create(CC_CALLBACK_0(Sprite::removeFromParent, effect)), NULL));
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
	updateMenu->setDoll(this);
	updateMenu->setPosition(this->getParent()->getPosition());
	static_cast<BaseLevel*>(this->getParent()->getParent())->mTouchLayer->addChild(updateMenu);
	if (GameManager::getInstance()->LEVEL <= 0) {
		updateMenu->canUpdate = false;
	}
	updateMenu->inAnimation();
	isUpdateMenuShown = true;
}

BaseBullet * FirstDollv1::FirstDollBullet() {
	auto firstDollBullet = Stone::create();
	firstDollBullet->setPosition(Point(40, 45));
	firstDollBullet->setMaxForce(15);
	this->getParent()->addChild(firstDollBullet);
	return firstDollBullet;

}

void FirstDollv1::shoot(float dt) {
	auto instance = GameManager::getInstance();
	checkNearestMonster();
	if (nearestMonster != NULL && nearestMonster->getCurHp() > 0) {
		auto curBullet = FirstDollBullet();
		//大娃的游戏音效SoundManager::

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