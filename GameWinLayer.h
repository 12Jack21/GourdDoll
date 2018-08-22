#pragma once

#include "SystemHeader.h"

USING_NS_CC;

class GameWinLayer : public Layer
{
public:

	virtual bool initGameWinLayer(int star, int gem);
	static GameWinLayer* createGameWinLayer(int star, int gem);
	//点击	重新开始 按钮
	void OnRestartTouch(Ref* pSpender);
	//点击 继续 按钮
	void OnContinueTouch(Ref* pSpender);

	int level;
	//int difficult;
	CREATE_FUNC(GameWinLayer);

private:
	Point position;
	Sprite* GameWinLayerSprite;
	//继续	菜单项
	MenuItemSprite* ContinueMenuItem;
	//重新开始	菜单项
	MenuItemSprite* RestartMenuItem;

};