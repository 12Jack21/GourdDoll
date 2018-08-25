#include"TouchLayer.h"
#include"BaseLevel.h"
#include"KingKong.h"

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
	auto kingKong = KingKong::create();
	addChild(kingKong);
	kingKong->shoot(static_cast<TouchLayer*>(event->getCurrentTarget())->convertTouchToNodeSpace(touch));

	//��ȡ��������״̬�㣬����startKingKong�����¼�ʱ
	static_cast<BaseLevel*>(this->getParent())->playState->startKingKong();
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

}
