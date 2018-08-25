#include"GameWinLayer.h"
#include"TransitionInterface.h"
#include"GameViewScene.h"
#include"GameManager.h"

USING_NS_CC;

GameWinLayer* GameWinLayer::createGameWin(int star)
{
	auto layer = GameWinLayer::create();
	layer->initGameWinLayer(star);
	return layer;
}


