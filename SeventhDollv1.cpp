#include "SeventhDollv1.h"
#include "SeventhDollv2.h"
#include "GameManager.h"
#include "UpdateMenu.h"
#include "BaseLevel.h"
#include "GourdBullet.h"

bool SeventhDollv1::init() {
	if (!Sprite::init()) {
		return false;
	}
	setDollType(SEVENTHDOLL_1);
	setLv(1);
	addGourd();
	updateAnimation();

	setScope(160.0f);
	setUpdateGourd(150);
	setFosterGourd(120);
	isUpdateMenuShown = false;
	nearestMonster = NULL;
	return true;
}

void SeventhDollv1::createAndSetHpBar() {
	hpBgSprite = Sprite::createWithSpriteFrameName(".png");
	hpBgSprite->setPosition(Point(baseSprite->getContentSize().width / 2, baseSprite->getContentSize().height / 3 * 2));
	baseSprite->addChild(hpBgSprite);

	hpBar = ProgressTimer::create(Sprite::createWithSpriteFrameName(".png"));
	hpBar->setType(ProgressTimer::Type::BAR);
	hpBar->setPercentage(100);
	hpBar->setMidpoint(Point(0,0.5f));
	hpBar->setPosition(Point(hpBgSprite->getContentSize().width / 2, hpBgSprite->getContentSize().height / 2));
	hpBar->setBarChangeRate(Point(1,0));
	hpBgSprite->addChild(hpBar);

}

void SeventhDollv1::updateAnimation() {
	auto update = Sprite::create();
	auto shape = Sprite::createWithSpriteFrameName(".png");
	update->addChild(shape);
	addChild(update);
	scheduleOnce(schedule_selector(SeventhDollv1::updateEffectAnimation), 0.5f);
}

void SeventhDollv1::updateEffectAnimation(float dt) {
	auto effect = Sprite::createWithSpriteFrameName(".png");
	addChild(effect, 99);
	effect->runAction(Sequence::create(Animate::create(AnimationCache::getInstance()->getAnimation(" ")), CallFuncN::create(CC_CALLBACK_0(Sprite::removeFromParent, effect)), NULL));
	//音效
	initDoll(1);
	setListener();
	schedule(schedule_selector(SeventhDollv1::shoot), 3.0f);
}

void SeventhDollv1::updateDoll() {
	auto SeventhDollv2 = SeventhDollv2::create();
	SeventhDollv2->setMyGourd(myGourd);
	SeventhDollv2->setTag(myGourd->getTag());
	SeventhDollv2->setPosition(Point(0, 20));
	myGourd->addChild(SeventhDollv2);
	this->removeDoll();
}

void SeventhDollv1::showUpdateMenu() {
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

BaseBullet * SeventhDollv1::SeventhDollBullet() {
	auto seventhDollBullet = GourdBullet::create();
	seventhDollBullet->setPosition(Point(40, 45));
	seventhDollBullet->setMaxForce(0);
	this->getParent()->addChild(seventhDollBullet);
	return seventhDollBullet;
}

void SeventhDollv1::seventhdollv1Death() {
	if (GameManager::getInstance()->seventhDollv1Vector.contains(this))
		GameManager::getInstance()->seventhDollv1Vector.eraseObject(this, false);
	if (getState() != SevenDollStateDeath) {
		setCurHp(0);
		setState(SevenDollStateDeath);
		hpBgSprite->setVisible(false);
		baseSprite->stopAllActions();
		unscheduleUpdate();
		auto decal_blood = Sprite::createWithSpriteFrameName(".png");
		decal_blood->setPosition(Point(baseSprite->getContentSize().width / 2, -baseSprite->getContentSize().height / 4));
		baseSprite->addChild(decal_blood);

		decal_blood->runAction(Sequence::create(FadeOut::create(1.0f)
			, CallFuncN::create(CC_CALLBACK_0(SeventhDollv1::setVisible, this, false))
			, NULL));
	}
}

void SeventhDollv1::shoot(float dt) {
	auto instance = GameManager::getInstance();
	checkNearestMonster();
	if (nearestMonster != NULL && nearestMonster->getCurHp() > 0) {
		auto curBullet = SeventhDollBullet();
		//二娃的游戏音效SoundManager::

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

