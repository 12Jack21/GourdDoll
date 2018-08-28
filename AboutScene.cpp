#include"LevelViewScene.h"
#include "WelcomeScene.h"
#include"TransitionInterface.h"
#include"GameScene.h"

USING_NS_CC;
Scene* LevelViewScene::createScene()
{
	auto scene = Scene::create();
	auto layer = LevelViewScene::create();
	scene->addChild(layer);
	return scene;
}

bool LevelViewScene::init()
{
	if (!Layer::init())
	{
		return false;
	}
	visibleSize = Director::getInstance()->getVisibleSize();

	//背景
	auto bg = Sprite::createWithSpriteFrameName("levelView.jpg");
	bg->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	addChild(bg, -1);

	//初始化菜单
	initLevelMenu();

	auto homeSprite = Sprite::createWithSpriteFrameName("home.png");
	homeSprite->setPosition(Vec2(100, visibleSize.height - 50));
	addChild(homeSprite);

	//接触监测
	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = [&](Touch* touch, Event* event) {

		auto target = static_cast<Sprite*>(event->getCurrentTarget());

		Point locationInNode = target->convertTouchToNodeSpace(touch);

		Size size = target->getContentSize();
		Rect rect = Rect(0, 0, size.width, size.height);
		if (rect.containsPoint(locationInNode))
		{
			target->setScale(1.1f);
			return true;
		}
		return false;
	};
	listener->onTouchEnded = [&](Touch* touch, Event* event) {

		auto target = static_cast<Sprite*>(event->getCurrentTarget());

		Point locationInNode = target->convertTouchToNodeSpace(touch);

		Size size = target->getContentSize();
		Rect rect = Rect(0, 0, size.width, size.height);
		if (rect.containsPoint(locationInNode))
		{
			Director::getInstance()->replaceScene(TransitionInterface::create(2.0f, WelcomeScene::createScene()));
		}
	};
	listener->setSwallowTouches(true);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, homeSprite);
	return true;
}

//七个葫芦菜单精灵
void LevelViewScene::initLevelMenu()
{
	//动作创建
	auto rotate1 = RotateTo::create(1.0f, 40.0f);
	auto roatat2 = RotateTo::create(2.0f, -40.0f);
	auto delay = DelayTime::create(0.3f);

	auto gourd1 = Sprite::createWithSpriteFrameName("FirstGourd.png");
	gourd1->setPosition(Vec2(360.0f, visibleSize.height - 293.0f));
	gourd1->setScale(0.8);
	addChild(gourd1, 100);

	auto listener1 = EventListenerTouchOneByOne::create();
	listener1->onTouchBegan = [&](Touch* touch, Event* event) {

		auto target = static_cast<Sprite*>(event->getCurrentTarget());

		Point locationInNode = target->convertTouchToNodeSpace(touch);

		Size size = target->getContentSize();
		Rect rect = Rect(0, 0, size.width, size.height);
		if (rect.containsPoint(locationInNode))
		{
			target->setScale(1.1f);
			return true;
		}
		return false;
	};
	listener1->onTouchEnded = [&](Touch* touch, Event* event) {

		auto target = static_cast<Sprite*>(event->getCurrentTarget());

		Point locationInNode = target->convertTouchToNodeSpace(touch);

		Size size = target->getContentSize();
		Rect rect = Rect(0, 0, size.width, size.height);
		if (rect.containsPoint(locationInNode))
		{
			/*Director::getInstance()->replaceScene(TransitionInterface::create(1.0f, GameScene::playGame(1)));*/
		}
	};
	listener1->setSwallowTouches(true);

	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener1, gourd1);

	////实现葫芦绕顶部左右晃动（旋转
	//auto gourd1 = Sprite::createWithSpriteFrameName("");
	//gourd1->setPosition(Vec2());
	////葫芦绕 锚点 旋转
	//gourd1->setAnchorPoint(Vec2());
	//addChild(gourd1);
	//gourd1->runAction(gourdAction);

	auto gourd2 = Sprite::createWithSpriteFrameName("SecondGourd.png");
	gourd2->setPosition(Vec2(234.0f, visibleSize.height - 446.0f));
	gourd2->setScale(0.8);
	addChild(gourd2, 100);

	auto listener2 = EventListenerTouchOneByOne::create();
	listener2->onTouchBegan = [&](Touch* touch, Event* event) {

		auto target = static_cast<Sprite*>(event->getCurrentTarget());

		Point locationInNode = target->convertTouchToNodeSpace(touch);

		Size size = target->getContentSize();
		Rect rect = Rect(0, 0, size.width, size.height);
		if (rect.containsPoint(locationInNode))
		{
			target->setScale(1.1f);
			return true;
		}
		return false;
	};
	listener2->onTouchEnded = [&](Touch* touch, Event* event) {

		auto target = static_cast<Sprite*>(event->getCurrentTarget());

		Point locationInNode = target->convertTouchToNodeSpace(touch);

		Size size = target->getContentSize();
		Rect rect = Rect(0, 0, size.width, size.height);
		if (rect.containsPoint(locationInNode))
		{
			/*Director::getInstance()->replaceScene(TransitionInterface::create(1.0f, GameScene::playGame(2)));*/
		}
	};
	listener2->setSwallowTouches(true);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener2, gourd2);

	auto gourd3 = Sprite::createWithSpriteFrameName("ThirdGourd.png");
	gourd3->setPosition(Vec2(426.0f, visibleSize.height - 536.0f));
	gourd3->setScale(0.8);
	addChild(gourd3, 100);

	auto listener3 = EventListenerTouchOneByOne::create();
	listener3->onTouchBegan = [&](Touch* touch, Event* event) {

		auto target = static_cast<Sprite*>(event->getCurrentTarget());

		Point locationInNode = target->convertTouchToNodeSpace(touch);

		Size size = target->getContentSize();
		Rect rect = Rect(0, 0, size.width, size.height);
		if (rect.containsPoint(locationInNode))
		{
			target->setScale(1.1f);
			return true;
		}
		return false;
	};
	listener3->onTouchEnded = [&](Touch* touch, Event* event) {

		auto target = static_cast<Sprite*>(event->getCurrentTarget());

		Point locationInNode = target->convertTouchToNodeSpace(touch);

		Size size = target->getContentSize();
		Rect rect = Rect(0, 0, size.width, size.height);
		if (rect.containsPoint(locationInNode))
		{
			/*Director::getInstance()->replaceScene(TransitionInterface::create(1.0f, GameScene::playGame(3)));*/
		}
	};
	listener3->setSwallowTouches(true);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener3, gourd3);

	auto gourd4 = Sprite::createWithSpriteFrameName("FourthGourd.png");
	gourd4->setPosition(Vec2(641.0f, visibleSize.height - 331.0f));
	gourd4->setScale(0.8);
	addChild(gourd4, 100);

	auto listener4 = EventListenerTouchOneByOne::create();
	listener4->onTouchBegan = [&](Touch* touch, Event* event) {

		auto target = static_cast<Sprite*>(event->getCurrentTarget());

		Point locationInNode = target->convertTouchToNodeSpace(touch);

		Size size = target->getContentSize();
		Rect rect = Rect(0, 0, size.width, size.height);
		if (rect.containsPoint(locationInNode))
		{
			target->setScale(1.1f);
			return true;
		}
		return false;
	};
	listener4->onTouchEnded = [&](Touch* touch, Event* event) {

		auto target = static_cast<Sprite*>(event->getCurrentTarget());

		Point locationInNode = target->convertTouchToNodeSpace(touch);

		Size size = target->getContentSize();
		Rect rect = Rect(0, 0, size.width, size.height);
		if (rect.containsPoint(locationInNode))
		{
			/*Director::getInstance()->replaceScene(TransitionInterface::create(1.0f, GameScene::playGame(4)));*/
		}
	};
	listener4->setSwallowTouches(true);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener4, gourd4);

	auto gourd5 = Sprite::createWithSpriteFrameName("FifthGourd.png");
	gourd5->setPosition(Vec2(919.0f, visibleSize.height - 264.0f));
	gourd5->setScale(0.8);
	addChild(gourd5, 100);

	auto listener5 = EventListenerTouchOneByOne::create();
	listener5->onTouchBegan = [&](Touch* touch, Event* event) {

		auto target = static_cast<Sprite*>(event->getCurrentTarget());

		Point locationInNode = target->convertTouchToNodeSpace(touch);

		Size size = target->getContentSize();
		Rect rect = Rect(0, 0, size.width, size.height);
		if (rect.containsPoint(locationInNode))
		{
			target->setScale(1.1f);
			return true;
		}
		return false;
	};
	listener5->onTouchEnded = [&](Touch* touch, Event* event) {

		auto target = static_cast<Sprite*>(event->getCurrentTarget());

		Point locationInNode = target->convertTouchToNodeSpace(touch);

		Size size = target->getContentSize();
		Rect rect = Rect(0, 0, size.width, size.height);
		if (rect.containsPoint(locationInNode))
		{
			/*Director::getInstance()->replaceScene(TransitionInterface::create(1.0f, GameScene::playGame(5)));*/
		}
	};
	listener5->setSwallowTouches(true);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener5, gourd5);

	auto gourd6 = Sprite::createWithSpriteFrameName("SixthGourd.png");
	gourd6->setPosition(Vec2(847.0f, visibleSize.height - 418.0f));
	gourd6->setScale(0.8);
	addChild(gourd6, 100);

	auto listener6 = EventListenerTouchOneByOne::create();
	listener6->onTouchBegan = [&](Touch* touch, Event* event) {

		auto target = static_cast<Sprite*>(event->getCurrentTarget());

		Point locationInNode = target->convertTouchToNodeSpace(touch);

		Size size = target->getContentSize();
		Rect rect = Rect(0, 0, size.width, size.height);
		if (rect.containsPoint(locationInNode))
		{
			target->setScale(1.1f);
			return true;
		}
		return false;
	};
	listener6->onTouchEnded = [&](Touch* touch, Event* event) {

		auto target = static_cast<Sprite*>(event->getCurrentTarget());

		Point locationInNode = target->convertTouchToNodeSpace(touch);

		Size size = target->getContentSize();
		Rect rect = Rect(0, 0, size.width, size.height);
		if (rect.containsPoint(locationInNode))
		{
			/*Director::getInstance()->replaceScene(TransitionInterface::create(1.0f, GameScene::playGame(6)));*/
		}
	};
	listener6->setSwallowTouches(true);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener6, gourd6);

	auto gourd7 = Sprite::createWithSpriteFrameName("SeventhGourd.png");
	gourd7->setPosition(Vec2(1003.0f, visibleSize.height - 477.0f));
	gourd7->setScale(0.8);
	addChild(gourd7, 100);

	auto listener7 = EventListenerTouchOneByOne::create();
	listener7->onTouchBegan = [&](Touch* touch, Event* event) {

		auto target = static_cast<Sprite*>(event->getCurrentTarget());

		Point locationInNode = target->convertTouchToNodeSpace(touch);

		Size size = target->getContentSize();
		Rect rect = Rect(0, 0, size.width, size.height);
		if (rect.containsPoint(locationInNode))
		{
			target->setScale(1.1f);
			return true;
		}
		return false;
	};
	listener7->onTouchEnded = [&](Touch* touch, Event* event) {

		auto target = static_cast<Sprite*>(event->getCurrentTarget());

		Point locationInNode = target->convertTouchToNodeSpace(touch);

		Size size = target->getContentSize();
		Rect rect = Rect(0, 0, size.width, size.height);
		if (rect.containsPoint(locationInNode))
		{
			/*Director::getInstance()->replaceScene(TransitionInterface::create(1.0f, GameScene::playGame(7)));*/
		}
	};
	listener7->setSwallowTouches(true);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener7, gourd7);

}

bool LevelViewScene::onTouchBegan(Touch* touch, Event* event)
{
	auto target = static_cast<Sprite*>(event->getCurrentTarget());
	Point locationInNode = target->convertTouchToNodeSpace(touch);
	Size size = target->getContentSize();
	Rect rect = Rect(0, 0, size.width, size.height);

	if (rect.containsPoint(locationInNode))
	{
		target->pauseSchedulerAndActions();
		target->setScale(1.0f);
	}
	return true;
}

void LevelViewScene::onTouchEnded(Touch* touch, Event* event)
{
	auto target = static_cast<Sprite*>(event->getCurrentTarget());
	Point locationInNode = target->convertTouchToNodeSpace(touch);
	Rect rect = target->getBoundingBox();

	if (rect.containsPoint(locationInNode))
	{
		//Director::getInstance()->replaceScene(GameScene::create());
	}
	else
	{
		target->resumeSchedulerAndActions();
	}

}
