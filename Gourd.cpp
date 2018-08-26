#include "Gourd.h"
#include "TouchLayer.h"
#include "BaseLevel.h"
#include"SoundManager.h"
#include"FosterMenu.h"

Gourd * Gourd::createGourd() 
{
	auto gourd = new Gourd();
	if (gourd && gourd->init()) 
	{
		gourd->autorelease();
		return gourd;
	}
	CC_SAFE_DELETE(gourd);
	return NULL;
}

bool Gourd::init() 
{
	if (!Sprite::init()) 
	{
		return false;
	}
	isFosterMenuShown = false;

	addChild(gourd);
	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(Gourd::onTouchBegan, this);
	listener->onTouchEnded = CC_CALLBACK_2(Gourd::onTouchEnded, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, gourd);
	return true;
}

bool Gourd::onTouchBegan(Touch* touch, Event* event) 
{
	return true;
}

void Gourd::onTouchEnded(Touch* touch, Event* event) 
{
	auto target = static_cast<Sprite*>(event->getCurrentTarget());

	Point locationInNode = target->convertTouchToNodeSpace(touch);

	Size size = target->getContentSize();
	Rect rect = Rect(0, 0, size.width, size.height);

	if (rect.containsPoint(locationInNode) && target->isVisible()) 
	{
		if (hideFosterMenu) 
		{
			showFosterMenu();
		}
		else
		{
			hideFosterMenu();
		}
	}
	else
	{
		hideFosterMenu();
	}
}

void Gourd::showFosterMenu()
{


}

void Gourd::hideFosterMenu() 
{
	static_cast<BaseLevel*>(this->getParent())->mTouchLayer->removeChildByTag(getTag());
	isFosterMenuShown = false;
}