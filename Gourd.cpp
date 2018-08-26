#include "Gourd.h"
#include "TouchLayer.h"
#include "BaseLevel.h"

Gourd * Gourd::createGourd(int type) {
	auto gourd = new Gourd();
	if (gourd && gourd->init(type)) {
		gourd->autorelease();
		return gourd;
	}
	CC_SAFE_DELETE(gourd);
	return NULL;
}

bool Gourd::init(int type) {
	if (!Sprite::init()) {
		return false;
	}
	isUpdateMenuShown = false;
	switch (type)
	{
	case 1:
		gourd = Sprite::createWithSpriteFrameName(".png");
		break;
	case 2:
		gourd = Sprite::createWithSpriteFrameName(".png");
		break;
	case 3:
		gourd = Sprite::createWithSpriteFrameName(".png");
		break;
		default:
			break;
	}
	addChild(gourd);
	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(Gourd::onTouchBegan, this);
	listener->onTouchEnded = CC_CALLBACK_2(Gourd::onTouchEnded, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, gourd);
	return true;
}

bool Gourd::onTouchBegan(Touch* t, Event*e) {
	return true;
}

void Gourd::onTouchEnded(Touch * t, Event *e) {
	auto target = static_cast<Sprite*>(e->getCurrentTarget());

	Point locationInNode = target->convertTouchToNodeSpace(t);

	Size size = target->getContentSize();
	Rect rect = Rect(0, 0, size.width, size.height);

	if (rect.containsPoint(locationInNode) && target->isVisible()) {
		if (hideUpdateMenu) {
			showUpdateMenu();
		}
		else
		{
			hideUpdateMenu();
		}
	}
	else
	{
		hideUpdateMenu();
	}
}

void Gourd::hideUpdateMenu() {
	static_cast<BaseLevel *>(this->getParent())->mTouchLayer->removeChildByTag(getTag());
	isUpdateMenuShown = false;
}