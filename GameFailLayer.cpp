#include"GameFailLayer.h"
#include"SoundManager.h"

bool GameFailLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}
	//初始化选项
	initOption();

	Size visibleSize = Director::getInstance()->getVisibleSize();
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
	//重新开始
	auto restart = Sprite::createWithSpriteFrameName("options_buttons_0003.png");
	restart->setPosition(Point(-145, -100));
	restart->setTag(0);
	//退出
	auto exit = Sprite::createWithSpriteFrameName("options_buttons_0001.png");
	exit->setPosition(Point(145, -100));
	exit->setTag(1);

	option->addChild(restart);
	option->addChild(exit);

	auto listener = EventListenerTouchOneByOne::create();
	listener->setSwallowTouches(true);
	listener->onTouchBegan = CC_CALLBACK_2(Failure::onTouchBegan, this);
	listener->onTouchEnded = CC_CALLBACK_2(Failure::onTouchEnded, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, restart);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener->clone(), exit);

}
