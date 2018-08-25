#pragma once

#include "SystemHeader.h"

USING_NS_CC;

class GameWinLayer : public Layer
{
public:
	static GameWinLayer* createGameWin(int star);
	virtual bool initGameWinLayer(int star);

	//点击	重新开始 按钮
	void OnRestartTouch(Ref* pSpender);
	//点击 继续 按钮
	void OnContinueTouch(Ref* pSpender);

	int level;
	//int difficult;
	CREATE_FUNC(GameWinLayer);

private:
	Point position;
	Sprite* winSprite;
	//继续	菜单项
	MenuItemSprite* ContinueMenuItem;
	//重新开始	菜单项
	MenuItemSprite* RestartMenuItem;

};