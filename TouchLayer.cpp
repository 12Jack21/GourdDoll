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
	//金刚山释放音效
	SoundManager::playKingkong();
	auto kingKong = KingKong::create();
	addChild(kingKong);
	kingKong->shoot(static_cast<TouchLayer*>(event->getCurrentTarget())->convertTouchToNodeSpace(touch));

	//获取父类的玩家状态层，调用startKingKong，重新计时
	static_cast<BaseLevel*>(this->getParent())->playState->startKingKong();
	//移除遮罩
	removeKingKongTouchShield();
}

void TouchLayer::addWrongPlace(Point location)
{
	auto wrongPlace = Sprite::createWithSpriteFrameName("");
	wrongPlace->setPosition(location);
	addChild(wrongPlace);
	//错误地点动作
	wrongPlace->runAction();
}

void TouchLayer::removeAllListener()
{
	removeKingKongTouchShield();

}
