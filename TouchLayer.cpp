#include"TouchLayer.h"
#include"BaseLevel.h"
#include"KingKong.h"
#include "SixthDoll.h"

bool TouchLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}

	winSize = Director::getInstance()->getWinSize();
	SixthDolllistener = NULL;
	KingKonglistener = NULL;

	setKingKongTouchShield();

	return true;

}

void TouchLayer::setKingKongTouchShield()
{
	KingKonglistener = EventListenerTouchOneByOne::create();
	KingKonglistener->onTouchBegan = CC_CALLBACK_2(TouchLayer::onKingKongTouchBegan, this);
	KingKonglistener->onTouchEnded = CC_CALLBACK_2(TouchLayer::onKingKongTouchEnded, this);
	KingKonglistener->setSwallowTouches(true);

	_eventDispatcher->addEventListenerWithFixedPriority(KingKonglistener, 1);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(KingKonglistener, this);
}

void TouchLayer::removeKingKongTouchShield()
{
	if (KingKonglistener != NULL)
	{
		_eventDispatcher->removeEventListener(KingKonglistener);
	}
}

bool TouchLayer::onKingKongTouchBegan(Touch* touch, Event* event)
{
	return true;
}

void TouchLayer::onKingKongTouchEnded(Touch* touch, Event* event)
{
	//���ɽ�ͷ���Ч
	SoundManager::playKingkong();
<<<<<<< HEAD
	auto kingKong = KingKong::create();
=======
	auto kingKong = Kingkong::create();
>>>>>>> 86dbab6f10cc4571c714d43a23050c4a8759cd44
	addChild(kingKong);
	kingKong->shoot(static_cast<TouchLayer*>(event->getCurrentTarget())->convertTouchToNodeSpace(touch));

	//��ȡ��������״̬�㣬����startKingKong�����¼�ʱ
<<<<<<< HEAD
	static_cast<BaseLevel*>(this->getParent())->playState->startKingKong();
=======
	static_cast<BaseLevel*>(this->getParent())->playerState->startKingKong();
>>>>>>> 86dbab6f10cc4571c714d43a23050c4a8759cd44
	//�Ƴ�����
	removeKingKongTouchShield();
}

void TouchLayer::addWrongPlace(Point location)
{
	auto wrongPlace = Sprite::createWithSpriteFrameName("");
	wrongPlace->setPosition(location);
	addChild(wrongPlace);
	//����ص㶯��
	wrongPlace->runAction();
}

void TouchLayer::removeAllListener()
{
	removeKingKongTouchShield();
<<<<<<< HEAD

=======
	removeSixthDollTouchShield();
}

void TouchLayer::setSixthDollTouchShield()
{
	SixthDolllistener = EventListenerTouchOneByOne::create();
	SixthDolllistener->onTouchBegan = CC_CALLBACK_2(TouchLayer::onSixthDollTouchBegan, this);
	SixthDolllistener->onTouchEnded = CC_CALLBACK_2(TouchLayer::onSixthDollTouchEnded, this);
	SixthDolllistener->setSwallowTouches(true);

	_eventDispatcher->addEventListenerWithFixedPriority(SixthDolllistener, 1);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(SixthDolllistener, this);
}

void TouchLayer::removeSixthDollTouchShield()
{
	if (SixthDolllistener != NULL)
	{
		_eventDispatcher->removeEventListener(SixthDolllistener);
	}
}

bool TouchLayer::onSixthDollTouchBegan(Touch* touch, Event* event)
{

	return true;
}

void TouchLayer::onSixthDollTouchEnded(Touch* touch, Event* event)
{
	//�����ͷ���Ч
	SoundManager::playSixthDoll();
	auto kingKong = Kingkong::create();
	addChild(kingKong);
	kingKong->shoot(static_cast<TouchLayer*>(event->getCurrentTarget())->convertTouchToNodeSpace(touch));

	//��ȡ��������״̬�㣬����startKingKong�����¼�ʱ
	static_cast<BaseLevel*>(this->getParent())->playerState->startSixthDoll();
	//�Ƴ�����
	removeSixthDollTouchShield();
}

void TouchLayer::addWrongPlace(Point location)
{
	auto wrongPlace = Sprite::createWithSpriteFrameName("");
	wrongPlace->setPosition(location);
	addChild(wrongPlace);
	//����ص㶯��
	wrongPlace->runAction();
>>>>>>> 86dbab6f10cc4571c714d43a23050c4a8759cd44
}
