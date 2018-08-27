#include"GameScene.h"
#include "Level1.h"
#include "Level2.h"
#include "Level3.h
#include"PlayStateLayer.h"
#include"GameManager.h"

Scene* GameScene::playGame(int level)
{
	auto gameScene = new GameScene();
	if (gameScene && gameScene->initGame(level))
	{
		return gameScene;
	}
	CC_SAFE_DELETE(gameScene);
	return NULL;
}

bool GameScene::initGame(int level)
{
	//游戏实例化
	BaseLevel* game;
	//设置游戏状态层
	auto playState = PlayStateLayer::create();
	//设置游戏管理的关卡
	GameManager::getInstance()->LEVEL = level;
	switch (level)
	{
	case(1):
		game = Level1::createGame();
		break;
	case(2):
		game = Level2::createGame();
		break;
	case(3):
		game = Level3::createGame();
		break;
	}

	//关卡 绑定 游戏状态层
	game->binPlayState(playState);
	playState->setLevel(level);
	playState->initGameSetting();
	addChild(game);
	addChild(playState);

	return true;
}