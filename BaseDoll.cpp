#include "BaseDoll.h"
#include "GameManager.h"
//未见地图cpp，未导入
#include "TouchLayer.h"

BaseDoll::BaseDoll() :isUpdateMenuShown(false) {
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
	static_cast<gourd *>(this->getParent()->gourd->setVisible(true));
	removeDoll();
}

void BaseDoll::removeDoll() {
	//特效自填
	static_cast<gourd *>(this->getParent())->Effect();
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
	for (int i = 0; i < monsterVector.size(); i++) {
		auto monster = monsterVector.at(i);
		double distance = this->getParent()->getPosition().getDistance(monster->baseSprite->getPosition);
			if (distance < curMinDistance && monster->getAttackByTower()) {
				distance = curMinDistance;
				monsterTemp = monster;
		}
	}
	nearestMonster = monsterTemp;
}

void BaseDoll::hideUpdateMenu() {
	isUpdateMenuShown = false;
}

void BaseDoll::onTouchEnded(Touch * t, Event *e) {
	auto target = static_cast<Sprite *>(e->getCurrentTarget());
	Point locationInNode = target->convertTouchToNodeSpace(t);

	Size size = target->getContentSize();
	Rect rect = Rect(0, 0, size.width, size.height);
	if (rect.containPoint(locationInNode)) {
		static_cast</*未见地图.cpp*/>(this->getParent())->playerState->showDollInfo(getDollType());
		if (isUpdateMenuShown) {
			hideUpdateMenu;
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

void BaseDoll::showDollInfo() {

}