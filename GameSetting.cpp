#include "GameSetting.h"
#include "GameScene.h"
#include "TransitionInterface.h"
#include "LevelViewScene.h"
#include "SoundManager.h"
#include "PlayStateLayer.h"
#include"SystemHeader.h"

using namespace CocosDenshion;

bool GameSetting::init()
{
	if (!Layer::init())
	{
		return false;
	}

	initSetting();
	initButton();
	
	//设置界面的动画（动作）实现


	return true;
}

void GameSetting::initSetting()
{
	setting = Sprite::create();

	visibleSize = Director::getInstance()->getVisibleSize();
	//设置栏的背景
	auto bg = Sprite::createWithSpriteFrameName("");
	bg->setPosition(Vec2(visibleSize.width / 2, 
		visibleSize.height / 2 + bg->getContentSize().height*0.4));
	addChild(bg);
}

void GameSetting::initButton()
{
	//关闭 按钮
	auto close = MenuItemSprite::create(Sprite::createWithSpriteFrameName(".png"),
		Sprite::createWithSpriteFrameName(".png"));
	close->setCallback([&](Ref *pSender) {
		SoundManager::playClickEffect();
		Director::getInstance()->resume();
		this->runAction(Sequence::create(
		MoveBy::create(0.2f,Point(0,500))
		,CallFuncN::create(CC_CALLBACK_0(Layer::removeFromParent, this))
		,NULL));
		static_cast<PlayStateLayer*>(this->getParent())->removeGameSetting();
	});
	
	close->setPosition(Point(337, 156));
	//重新开始 按钮
	auto restart = Sprite::createWithSpriteFrameName(".png");
	restart->setPosition(Point(-145, -100));
	restart->setTag(0);
	//退出 按钮
	auto exit = Sprite::createWithSpriteFrameName(".png");
	exit->setPosition(Point(145, -100));
	exit->setTag(1);
	
	//控制音乐和音效的按钮的 背景
	auto soundBg = Sprite::createWithSpriteFrameName("");
	soundBg->setPosition(Vec2(visibleSize.width / 2 - soundBg->getContentSize().width * 0.8,
		soundBg->getContentSize().height / 2));

	auto musicBg = Sprite::createWithSpriteFrameName("");
	musicBg->setPosition(Vec2(visibleSize.width / 2 + musicBg->getContentSize().width * 0.8,
		musicBg->getContentSize().height / 2));

	//音乐 按钮
	auto music = Sprite::createWithSpriteFrameName("options_optButtons_0001.png");
	music->setPosition(Point(musicBg->getContentSize().width / 2, musicBg->getContentSize().height / 2));
	if (UserDefault::getInstance()->getIntegerForKey("backmusic", 1) == 0) {
		//0表示禁止BGM，1表示开启
		addOff(music);
	}
	musicBg->addChild(music);

	auto sound = Sprite::createWithSpriteFrameName("settings_optButtons_0003.png");
	sound->setPosition(Point(soundBg->getContentSize().width / 2, soundBg->getContentSize().height / 2));
	sound->setTag(2);
	if (UserDefault::getInstance()->getIntegerForKey("backsound", 1) == 0) {
		//0表示禁止BGM，1表示开启
		addOff(sound);
	}
	soundBg->addChild(sound);

	setting->addChild(musicBg);
	setting->addChild(soundBg);
	auto menu = Menu::create(close, NULL);
	menu->setPosition(Vec2::ZERO);
	setting->addChild(menu);
	setting->addChild(restart);
	setting->addChild(exit);

	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = [&](Touch* touch, Event* event) {

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
	};
	listener->onTouchEnded = [&](Touch* touch, Event* event) {
		auto target = static_cast<Sprite*>(event->getCurrentTarget());
		target->setScale(1.0f);
		if (target->getChildrenCount() == 0)
		{
			addOff(target);
			switch (target->getTag())
			{
			case(1):
				SimpleAudioEngine::getInstance()->pauseBackgroundMusic();

				//需要修改 key
				UserDefault::getInstance()->setIntegerForKey("backmusic", 0);
				break;
			case(2):
				UserDefault::getInstance()->setIntegerForKey("backeffect", 0);
				break;
			case(3):

				break;
			default:
				break;
			}
		}
		else {
			target->removeAllChildren();
			switch (target->getTag())
			{
			case(1):
				SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
				UserDefault::getInstance()->setIntegerForKey("backeffect", 1);
				break;
			case(2):
				UserDefault::getInstance()->setIntegerForKey("backmusic", 1);
				break;
			case(3):

				break;
			default:
				break;
			}
		}
	};
	listener->setSwallowTouches(true);
	//监听 音乐和音效
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, music);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener->clone(), sound);

	auto listener2 = EventListenerTouchOneByOne::create();
	listener2->setSwallowTouches(true);
	listener2->onTouchBegan = CC_CALLBACK_2(GameSetting::onTouchBegan, this);
	listener2->onTouchEnded = CC_CALLBACK_2(GameSetting::onTouchEnded, this);
	//监听 重新开始 和 退出
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener2, restart);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener2->clone(), exit);

}

//增加 红色叉叉
void GameSetting::addOff(Sprite* target)
{
	auto off = Sprite::createWithSpriteFrameName("Settings_optButtons_off.png");
	off->setPosition(Point(95, 85));
	target->addChild(off);
}

void GameSetting::onTouchEnded(Touch* touch, Event* event)
{
	auto target = static_cast<Sprite*>(event->getCurrentTarget());
	target->setScale(1.0f);
	switch (target->getTag())
	{
	case(0)://重新开始
	{
		Director::getInstance()->resume();
		Director::getInstance()->replaceScene(TransitionInterface::create(1.0f, GameScene::playGame(level)));
	}
	break;
	case(1)://退出
	{
		Director::getInstance()->resume();
		Director::getInstance()->replaceScene(TransitionInterface::create(1.0f, LevelViewScene::createScene()));
	}
	break;
	default:
		break;
	}
}

bool GameSetting::onTouchBegan(Touch* touch, Event* event)
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

void GameSetting::pauseGame()
{
	Director::getInstance()->pause();
}
