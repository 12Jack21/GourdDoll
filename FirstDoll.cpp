#include "FirstDoll.h"
#include "UpdateMenu.h"
#include "GameManager.h"
#include "BaseLevel.h"

void FirstDoll::initDoll(int level) {
	if (level == 1) {
		dollBase = Sprite::createWithSpriteFrameName(String::createWithFormat(/*文件名*/, level)->getCString());
		shooter = Sprite::createWithSpriteFrameName(String::createWithFormat(/*文件名*/, level)->getCString());
		shooter->setPosition(Point(dollBase->getContentSize().width / 2 + 3, dollBase->getContentSize().height / 2 + 34));
	}
	if (level == 2) {
		dollBase = Sprite::createWithSpriteFrameName(String::createWithFormat(/*文件名*/, level)->getCString());
		shooter = Sprite::createWithSpriteFrameName(String::createWithFormat(/*文件名*/, level)->getCString());
		shooter->setPosition(Point(dollBase->getContentSize().width / 2 + 3, dollBase->getContentSize().height / 2 + 34));
	}
	if (level = 3) {
		dollBase = Sprite::createWithSpriteFrameName(String::createWithFormat(/*文件名*/, level)->getCString());
		shooter = Sprite::createWithSpriteFrameName(String::createWithFormat(/*文件名*/, level)->getCString());
		shooter->setPosition(Point(dollBase->getContentSize().width / 2 + 3, dollBase->getContentSize().height / 2 + 34));
	}
	dollBase->setPosition(Point(0, -10));
	dollBase->addChild(shooter);
	curBullet = NULL;
}

void FirstDoll::addGourd() {
	gourd = Sprite::createWithSpriteFrameName(/*文件名*/);
	gourd->setAnchorPoint(Point(/*待定*/));
	addChild(gourd);
}

void FirstDoll::shoot(float dt) {
	auto instance = GameManager::getInstance();
	//需要添加射击音效播放
	Point shootVector = nearestMonster->monsterSprite->getPosition() - this->getParent()->getPosition();

	auto position = curBullet->getPosition() - shootVector;
	auto rotation = atan2(position.y, position.x);
	float angle = CC_RADIANS_TO_DEGREES(rotation);
	curBullet->setRotation(180.0f - angle);

	dollBase->runAction(Animate::create(AnimationCache::getInstance()->getAnimation(String::createWithFormat(/*文件名*/, level)->getCString())));

	if (shootVector.y)
	{
		shooter->runAction(Animate::create(AnimationCache::getInstance()->getAnimation(/*文件名*/)));
	}
	else
	{
		shooter->runAction(Animate::create(AnimationCache::getInstance()->getAnimation(/*文件名*/)));
	}

	auto move = MoveTo::create(0.25f, shootVector);
	auto action = Spawn::create(move, NULL);

	curBullet->setBulletAction(action);
	curBullet->shoot();
	curBullet = NULL;
}