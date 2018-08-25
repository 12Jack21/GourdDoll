#include"GameWinLayer.h"
#include"TransitionInterface.h"
#include"GameViewScene.h"
#include"LevelViewScene.h"
#include"GameManager.h"

USING_NS_CC;

GameWinLayer* GameWinLayer::createGameWin(int star)
{
	auto layer = GameWinLayer::create();
	layer->initGameWin(star);
	return layer;
}

bool GameWinLayer::initGameWin(int star)
{
	if (!Layer::init())
	{
		return false;
	}
	Size visibleSize = Director::getInstance()->getVisibleSize();
	auto winColor = LayerColor::create(Color4B(0, 0, 0, 70), 
		visibleSize.width, visibleSize.height);
	addChild(winColor);

	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = [&](Touch* touch, Event* event) {
		return true;
	};
	listener->setSwallowTouches(true);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, winColor);

	position.x = visibleSize.width / 2;
	position.y = visibleSize.height / 2;

	//继续游戏 和 重新开始 菜单项
	auto continueSpriteOff = Sprite::createWithSpriteFrameName(".png");
	auto continueSpriteOn = Sprite::createWithSpriteFrameName(".png");
	auto restartSpriteOff = Sprite::createWithSpriteFrameName(".png");
	auto restartSpriteOn = Sprite::createWithSpriteFrameName(".png");

	continueMenuItem = MenuItemSprite::create(continueSpriteOff, continueSpriteOn,
		CC_CALLBACK_1(GameWinLayer::OnContinueTouch, this));
	restartMenuItem = MenuItemSprite::create(restartSpriteOff, restartSpriteOn, 
		CC_CALLBACK_1(GameWinLayer::OnRestartTouch, this));
	continueMenuItem->setPosition(position.x, position.y);
	continueMenuItem->setVisible(false);
	restartMenuItem->setPosition(position.x, position.y - 240);
	restartMenuItem->setVisible(false);

	auto winMenu = Menu::create(continueMenuItem, restartMenuItem, NULL);
	winMenu->setPosition(Vec2::ZERO);
	addChild(winMenu, 1);


	return true;
}

void GameWinLayer::OnContinueTouch(Ref* pSpender)
{
	Director::getInstance()->replaceScene(TransitionInterface::create(1.0f, LevelViewScene::createScene()));

}
void GameWinLayer::OnRestartTouch(Ref* pSpender)
{
	Director::getInstance()->replaceScene(TransitionInterface::create(1.0f, GameScene::playGame(level, difficult)));
}

