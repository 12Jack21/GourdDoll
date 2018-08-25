#include"GameFailLayer.h"
#include"SoundManager.h"
#include"GameSetting.h"
#include"LevelViewScene.h"
#include"TransitionInterface.h"
#include"GameViewScene.h"

bool GameFailLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}
	//初始化选项
	initOption();

	visibleSize = Director::getInstance()->getVisibleSize();
	//层颜色
	auto layerColor = LayerColor::create(Color4B(0, 0, 0, 50),
		visibleSize.width, visibleSize.height);
	addChild(layerColor);

	//失败层进入动画


	//失败音效
	SoundManager::playGameFail();
	return true;
}


void GameFailLayer::initOption()
{
	//失败logo
	auto failLogo = Sprite::createWithSpriteFrameName("");
	failLogo->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	failOption->addChild(failLogo);

	//重新开始
	auto restart = Sprite::createWithSpriteFrameName("options_buttons_0003.png");
	restart->setPosition(Point(-145, -100));
	restart->setTag(0);
	//退出
	auto exit = Sprite::createWithSpriteFrameName("options_buttons_0001.png");
	exit->setPosition(Point(145, -100));
	exit->setTag(1);

	failOption->addChild(restart);
	failOption->addChild(exit);

	auto listener = EventListenerTouchOneByOne::create();
	listener->setSwallowTouches(true);
	listener->onTouchBegan = CC_CALLBACK_2(GameFailLayer::onTouchBegan, this);
	listener->onTouchEnded = CC_CALLBACK_2(GameFailLayer::onTouchEnded, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, restart);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener->clone(), exit);

}

void GameFailLayer::onTouchEnded(Touch* touch, Event* event)
{
	auto target = static_cast<Sprite*>(event->getCurrentTarget());
	target->setScale(1.0f);
	switch (target->getTag())
	{
	case(0)://重新开始
		Director::getInstance()->resume();
		Director::getInstance()->replaceScene(TransitionInterface::create(1.0f, GameScene::playGame(level, difficulty)));
		break;
	case(1)://退出
		Director::getInstance()->resume();
		Director::getInstance()->replaceScene(TransitionInterface::create(1.0f, GameLevelScene::createScene()));
		break;
	default:
		break;
	}
}

void GameFailLayer::pauseGame()
{
	Director::getInstance()->pause();
}

bool GameFailLayer::onTouchBegan(Touch* touch, Event* event)
{
	auto target = static_cast<Sprite*>(event->getCurrentTarget());

	Point locationInNode = target->convertTouchToNodeSpace(touch);

	Size size = target->getContentSize();
	Rect rect = Rect(0, 0, size.width, size.height);
	if (rect.containsPoint(locationInNode))
	{
		SoundManager::playClickEffect();
		target->setScale(0.9f);
		return true;
	}
	return false;
}