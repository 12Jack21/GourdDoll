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
	setLv(1);
	addGourd();
	updateAnimation();

	setScope(160.0f);
	setUpdateGourd(150);
	setFosterGourd(120);
	isUpdateMenuShown = false;
	return true;
}

BaseMonster * BaseDoll::checknearestmonster() {
	auto instance = GameManager::getInstance();
	auto monsterVector = instance->monsterVector;

	auto curMinDistance = this->scope;

	BaseMonster * checkedNearestMonster = NULL;
	//for循环找到在DOLL内最近的MONSTER
	for (int i = 0; i < monsterVector.size(); i++) {
		auto monster = monsterVector.at(i);
		double distance = this->getParent()->getPosition().getDistance(monster->monsterSprite->getPosition());
		if (distance < curMinDistance && monster->getAttackByTower()) {
			distance = curMinDistance;
			checkedNearestMonster = monster;
		}
	}
	nearestMonster = checkedNearestMonster;
	return nearestMonster;
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
	//音效
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
	updateMenu->setDoll(this);
	updateMenu->setPosition(this->getParent()->getPosition());
	static_cast<BaseLevel*>(this->getParent()->getParent())->mTouchLayer->addChild(updateMenu);
	if (GameManager::getInstance()->LEVEL <= 0) {
		updateMenu->canUpdate = false;
	}
	updateMenu->inAnimation();
	isUpdateMenuShown = true;
}

BaseBullet * SecondDollv1::SecondDollBullet() {
	auto secondDollBullet = Laser::create();
	secondDollBullet->setPosition(Point(40, 45));
	secondDollBullet->setMaxForce(15);
	this->getParent()->addChild(secondDollBullet);
	return secondDollBullet;

}

void SecondDollv1::shoot(float dt) {
	auto instance = GameManager::getInstance();
	checkNearestMonster();
	if (nearestMonster != NULL && nearestMonster->getCurHp() > 0) {
		auto curBullet = SecondDollBullet();
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