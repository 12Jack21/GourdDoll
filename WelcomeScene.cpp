#include"WelcomeScene.h"
//#include"SoundManager.h"
#include"AboutScene.h"
#include"TransitionInterface.h"
#include "LevelViewScene.h"

//触摸的大小未定,各种元素动画（包括菜单回调的）未定

using namespace CocosDenshion;

Scene* WelcomeScene::createScene()
{
	auto scene = Scene::create();
	auto layer = WelcomeScene::create();
	scene->addChild(layer);
	return scene;
}

bool WelcomeScene::init()
{
	if (!Layer::init())
	{
		return false;
	}
	visibleSize = Director::getInstance()->getVisibleSize();

	//背景
	bg = Sprite::createWithSpriteFrameName("WelcomeBg.png");
	bg->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	//设置 Z order 为-1
	addChild(bg, -1);

	////动画测试
	//SpriteFrameCache::getInstance()->addSpriteFramesWithFile("ThirdDoll.plist");
	//SpriteFrameCache::getInstance()->addSpriteFramesWithFile("longicorn_scorpion_snake.plist");
	//auto first = Sprite::createWithSpriteFrameName("ThirdDollStand1.png");
	//first->setPosition(Vec2(visibleSize.width *0.8, visibleSize.height*0.8));
	//addChild(first);

	//auto firstDoll = Animation::create();
	//for (int i = 1; i <= 6; i++)
	//{
	//	__String* frameName = __String::createWithFormat("ThirdDollStand%d.png", i);

	//	auto frame11 = SpriteFrameCache::getInstance()->getSpriteFrameByName(frameName->getCString());
	//	if (frame11 != NULL)
	//	{
	//		firstDoll->addSpriteFrame(frame11);
	//	}
	//}
	//firstDoll->setDelayPerUnit(1.0f);
	//firstDoll->setRestoreOriginalFrame(true);

	//first->runAction(RepeatForever::create(Animate::create(firstDoll)));



	//logo动画(未完善）
	//initLogoAnimation();

	//初始化装饰精灵
	initOrnamentSprite();

	//初始化菜单
	initSoundButton();

	initStartButton();

	initAboutButton();

	return true;
}

void WelcomeScene::initLogoAnimation()
{
	//logo
	logo = Sprite::createWithSpriteFrameName(".png");
	logoPoint.x = visibleSize.width / 2;
	logoPoint.y = visibleSize.height - logo->getContentSize().height / 2;
	logo->setPosition(logoPoint);
	//锚点设置 设为中点
	logo->setAnchorPoint(Vec2(0.5f, 0.5f));
	//Z order 设置为6
	addChild(logo, 6);


	//。。。。。。
}


void WelcomeScene::initOrnamentSprite()
{
	//实现装饰精灵的动作

}

void WelcomeScene::initStartButton()
{
	start_Btn = Sprite::createWithSpriteFrameName("start_btn.png");
	start_Btn->setAnchorPoint(Vec2(0.5f, 0.5f));
	start_BtnPoint.x = visibleSize.width / 2 - 5;
	start_BtnPoint.y = 196.5;
	start_Btn->setPosition(start_BtnPoint);
	addChild(start_Btn, 1);

	//动画实现

	//菜单回调
	auto start_Btn_listener = EventListenerTouchOneByOne::create();
	start_Btn_listener->onTouchBegan = [&](Touch* touch, Event* event) {

		auto target = static_cast<Sprite*>(event->getCurrentTarget());

		Point locationInNode = target->convertTouchToNodeSpace(touch);

		Size size = target->getContentSize();
		Rect rect = Rect(0, 0, size.width, size.height);
		if (rect.containsPoint(locationInNode) && target->isVisible())
		{
			//SoundManager::playClickEffect();
			//改变Button式样达到点击效果
			//target->setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("menu_startchain_0002.png"));
			target->setScale(1.1f);
			return true;
		}
		return false;
	};
	start_Btn_listener->onTouchEnded = [&](Touch* touch, Event* event) {
		auto target = static_cast<Sprite*>(event->getCurrentTarget());
		//static_cast<Sprite*>(event->getCurrentTarget())->setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("menu_startchain_0001.png"));
		//about_Btn->setVisible(false);
		///*
		//回调后的动画
		//*/
		//start_Btn->setVisible(false);
		Director::getInstance()->replaceScene(TransitionInterface::create(3.0f, LevelViewScene::createScene()));

	};
	start_Btn_listener->setSwallowTouches(true);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(start_Btn_listener, start_Btn);

}

void WelcomeScene::initAboutButton()
{
	about_Btn = Sprite::createWithSpriteFrameName("about_btn.png");
	about_Btn->setAnchorPoint(Vec2(0.5f, 0.5f));

	about_BtnPoint.x = visibleSize.width / 2;
	about_BtnPoint.y = 65;
	about_Btn->setPosition(about_BtnPoint);
	addChild(about_Btn, 2);

	//动画实现

	//菜单回调
	auto about_Btn_listener = EventListenerTouchOneByOne::create();
	about_Btn_listener->onTouchBegan = [&](Touch* touch, Event* event) {

		auto target = static_cast<Sprite*>(event->getCurrentTarget());

		//触摸点坐标转换成关于目标的模型坐标
		Point locationInNode = target->convertTouchToNodeSpace(touch);

		Size size = target->getContentSize();

		Rect rect = Rect(0, 0, size.width, size.height);//未定
		if (rect.containsPoint(locationInNode) && target->isVisible())
		{
			//SoundManager::playClickEffect();
			//改变Button式样达到点击效果
			//target->setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("menu_creditschain_0002.png"));
			target->setScale(1.1f);
			return true;
		}
		return false;
	};
	about_Btn_listener->onTouchEnded = [&](Touch* touch, Event* event) {
		//static_cast<Sprite*>(event->getCurrentTarget())->setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("menu_creditschain_0001.png"));

		Director::getInstance()->replaceScene(TransitionInterface::create(3.0f, AboutScene::createScene()));
	};
	about_Btn_listener->setSwallowTouches(true);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(about_Btn_listener, about_Btn);
}

void WelcomeScene::initSoundButton()
{
	auto winSize = Director::getInstance()->getWinSize();
	Sprite* backMusic_Btn;

	//SoundManager::playWelcomebackMusic_Btn();

	if (UserDefault::getInstance()->getIntegerForKey("backMusic_Btn", 1) == 1)
	{
		//0表示关闭BGM，1表示开启
		backMusic_Btn = Sprite::createWithSpriteFrameName("music.png");
	}
	else
	{
		backMusic_Btn = Sprite::createWithSpriteFrameName("music_disable.png");
	}
	backMusic_Btn->setPosition(Point(backMusic_Btn->getContentSize().width / 2 + 10,
		winSize.height - backMusic_Btn->getContentSize().height / 2 - 10));
	addChild(backMusic_Btn);
	auto backMusic_Btn_listener = EventListenerTouchOneByOne::create();
	backMusic_Btn_listener->onTouchBegan = [&](Touch* touch, Event* event) {

		auto target = static_cast<Sprite*>(event->getCurrentTarget());

		Point locationInNode = target->convertTouchToNodeSpace(touch);

		Size size = target->getContentSize();
		Rect rect = Rect(0, 0, size.width, size.height);
		//检测触摸位置是否在规定范围内
		if (rect.containsPoint(locationInNode))
		{
			if (UserDefault::getInstance()->getIntegerForKey("backMusic_Btn", 1) == 1)
			{//0表示禁止BGM，1表示开启
				UserDefault::getInstance()->setIntegerForKey("backMusic_Btn", 0);
			}
			else
			{
				UserDefault::getInstance()->setIntegerForKey("backMusic_Btn", 1);
			}
			target->setScale(1.1f);
			return true;
		}
		return false;
	};
	backMusic_Btn_listener->onTouchEnded = [&](Touch* touch, Event* event) {
		auto target = static_cast<Sprite*>(event->getCurrentTarget());
		target->setScale(1.0f);
		if (UserDefault::getInstance()->getIntegerForKey("backMusic_Btn", 1) == 1)
		{//0表示禁止BGM，1表示开启
			SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
			target->setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("music.png"));
		}
		else
		{
			SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
			target->setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("music_disable.png"));
		}
	};
	//事件监听器（默认在CCNode中）
	_eventDispatcher->addEventListenerWithSceneGraphPriority(backMusic_Btn_listener, backMusic_Btn);

	Sprite* backEffect_Btn;
	if (UserDefault::getInstance()->getIntegerForKey("backEffect_Btn", 1) == 1)
	{
		//0表示禁止BGM，1表示开启
		backEffect_Btn = Sprite::createWithSpriteFrameName("effect.png");
	}
	else
	{
		backEffect_Btn = Sprite::createWithSpriteFrameName("effect.png");
	}
	backEffect_Btn->setPosition(Point(backMusic_Btn->getPosition().x + backMusic_Btn->getContentSize().width + 20,
		winSize.height - backEffect_Btn->getContentSize().height / 2 - 10));
	addChild(backEffect_Btn);
	auto backEffect_Btn_listener = EventListenerTouchOneByOne::create();
	backEffect_Btn_listener->onTouchBegan = [&](Touch* touch, Event* event) {

		auto target = static_cast<Sprite*>(event->getCurrentTarget());

		Point locationInNode = target->convertTouchToNodeSpace(touch);

		Size size = target->getContentSize();
		Rect rect = Rect(0, 0, size.width, size.height);
		if (rect.containsPoint(locationInNode))
		{
			if (UserDefault::getInstance()->getIntegerForKey("backEffect_Btn", 1) == 1)
			{
				//0表示禁止BGM，1表示开启
				UserDefault::getInstance()->setIntegerForKey("backEffect_Btn", 0);
			}
			else
			{
				UserDefault::getInstance()->setIntegerForKey("backEffect_Btn", 1);
			}
			target->setScale(1.1f);
			return true;
		}
		return false;
	};
	backEffect_Btn_listener->onTouchEnded = [&](Touch* touch, Event* event) {
		auto target = static_cast<Sprite*>(event->getCurrentTarget());
		target->setScale(1.0f);
		if (UserDefault::getInstance()->getIntegerForKey("backEffect_Btn", 1) == 1)
		{
			//0表示禁止BGM，1表示开启
			target->setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("effect.png"));
		}
		else
		{
			target->setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("effect_disable.png"));
		}
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(backEffect_Btn_listener, backEffect_Btn);
}

void WelcomeScene::onEnterTransitionDidFinish()
{
	//进入欢迎界面后须实现的东西（包括动画）
	/*
	auto Sequence = Sequence::create(ScaleTo::create(0.5f, 1.5f, 1.5f),
	ScaleTo::create(0.2f, 1.0f, 1.0f),
	CallFuncN::create(CC_CALLBACK_0(WelcomeScene::initLogoAnimation, this)),
	CallFuncN::create(CC_CALLBACK_0(WelcomeScene::initButton_startAnimation, this)),
	CallFuncN::create(CC_CALLBACK_0(WelcomeScene::init_creditBtn_startAnimation, this)),
	NULL);
	sprite_Logo->runAction(Sequence);
	*/
}