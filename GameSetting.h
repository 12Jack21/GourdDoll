#pragma once

#include "SystemHeader.h"

USING_NS_CC;

//游戏中的设置类
class GameSetting : public Layer
{
public:
	virtual bool init();
	CREATE_FUNC(GameSetting);
	int difficult;
	int level;

private:
	void initSetting();
	void initButton();
	void pauseGame();
	Sprite* setting;
	bool onTouchBegan(Touch* touch, Event* event);
	void onTouchEnded(Touch* touch, Event* event);
	//加上 红叉叉
	void addOff(Sprite* target);
};
