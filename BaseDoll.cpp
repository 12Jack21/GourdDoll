#include "BaseDoll.h"
#include "GameManager.h"
#include "BaseLevel.h"
#include "UpdateMenu.h"
#include "TouchLayer.h"
#include "Gourd.h"


BaseDoll::BaseDoll() :isUpdateMenuShown(false) 
{

};

BaseDoll::~BaseDoll() {};


bool BaseDoll::init() {
	if (!Sprite::init()) {
		return false;
	}
	isUpdateMenuShown = false;
	return true;
}

void BaseDoll::sellDoll() {
	static_cast<Gourd *>(this->getParent())->gourd->setVisible(true);
	removeDoll();
}

void BaseDoll::removeDoll() {
	static_cast<BaseLevel *>(this->getParent()->getParent())->playState->removeDollInfo();
	static_cast<Gourd *>(this->getParent())->Effect();
	this->unscheduleAllCallbacks();
	this->removeAllChildren();
	this->removeFromParent();
}

void BaseDoll::setListener() {
	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(BaseDoll::onTouchBegan, this);
	listener->onTouchEnded = CC_CALLBACK_2(BaseDoll::onTouchEnded, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, gourd);
}

void BaseDoll::checkNearestMonster() {
	auto instance = GameManager::getInstance();
	auto monsterVector = instance->monsterVector;

	auto curMinDistance = this->scope;

	BaseMonster * monsterTemp = NULL;
	//forѭ���ҵ���DOLL�������MONSTER
	for (int i = 0; i < monsterVector.size(); i++) {
		auto monster = monsterVector.at(i);
		double distance = this->getParent()->getPosition().getDistance(monster->monsterSprite->getPosition());
			if (distance < curMinDistance && monster->getAttackByDoll()) {
				distance = curMinDistance;
				monsterTemp = monster;
		}
	}
	nearestMonster = monsterTemp;
}

void BaseDoll::hideUpdateMenu() {
	static_cast<BaseLevel *>(this->getParent())->mTouchLayer->removeChildByTag(getTag() + 100);
	isUpdateMenuShown = false;
}

void BaseDoll::onTouchEnded(Touch * t, Event *e) {
	auto target = static_cast<Sprite *>(e->getCurrentTarget());
	Point locationInNode = target->convertTouchToNodeSpace(t);

	Size size = target->getContentSize();
	Rect rect = Rect(0, 0, size.width, size.height);
	if (rect.containsPoint(locationInNode)) {
		//��ȡ����������ʾ�˵�
		static_cast<BaseLevel *>(this->getParent())->playState->showDollInfo(getDollType());
		if (isUpdateMenuShown) {
			hideUpdateMenu();
		}
		else
		{
			showUpdateMenu();
		}
	}
	else
	{
		hideUpdateMenu();
	}

}
//��ʼ�����ĵȼ�
void BaseDoll::initDoll(int level) {
	if (level == 1) {
		dollBase = Sprite::createWithSpriteFrameName(String::createWithFormat(".png", level)->getCString());
		shooter = Sprite::createWithSpriteFrameName(String::createWithFormat(".png", level)->getCString());
		shooter->setPosition(Point(dollBase->getContentSize().width / 2 + 3, dollBase->getContentSize().height / 2 + 34));
	}
	if (level == 2) {
		dollBase = Sprite::createWithSpriteFrameName(String::createWithFormat(".png", level)->getCString());
		shooter = Sprite::createWithSpriteFrameName(String::createWithFormat(".png", level)->getCString());
		shooter->setPosition(Point(dollBase->getContentSize().width / 2 + 3, dollBase->getContentSize().height / 2 + 34));
	}
	if (level = 3) {
		dollBase = Sprite::createWithSpriteFrameName(String::createWithFormat(".png", level)->getCString());
		shooter = Sprite::createWithSpriteFrameName(String::createWithFormat(".png", level)->getCString());
		shooter->setPosition(Point(dollBase->getContentSize().width / 2 + 3, dollBase->getContentSize().height / 2 + 34));
	}
	dollBase->setPosition(Point(0, -10));
	dollBase->addChild(shooter);
	curBullet = NULL;
}


void BaseDoll::addGourd() {
	gourd = Sprite::createWithSpriteFrameName(".png");
	gourd->setAnchorPoint(Point(/*������*/));
	addChild(gourd);
}

//void BaseDoll::shoot(float dt) {
//	auto instance = GameManager::getInstance();
//	checkNearestMonster();
//	if (nearestMonster != NULL && nearestMonster->getCurHp() > 0) {
//		
//	}
//	Point shootVector = nearestMonster->monsterSprite->getPosition() - this->getParent()->getPosition();
//
//	auto position = curBullet->getPosition() - shootVector;
//	auto rotation = atan2(position.y, position.x);
//	float angle = CC_RADIANS_TO_DEGREES(rotation);
//	curBullet->setRotation(180.0f - angle);
//
//	dollBase->runAction(Animate::create(AnimationCache::getInstance()->getAnimation(String::createWithFormat(" ", level)->getCString())));
//
//	if (shootVector.y)
//	{
//		shooter->runAction(Animate::create(AnimationCache::getInstance()->getAnimation(" ")));
//	}
//	else
//	{
//		shooter->runAction(Animate::create(AnimationCache::getInstance()->getAnimation(" ")));
//	}
//
//	auto move = MoveTo::create(0.25f, shootVector);
//	auto action = Spawn::create(move, NULL);
//
//	curBullet->setBulletAction(action);
//	curBullet->shoot();
//	curBullet = NULL;
//}
void BaseDoll::showDollInfo() {

}