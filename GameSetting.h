#pragma once

#include "SystemHeader.h"

USING_NS_CC;

//游戏中的设置类
class GameSetting : public Layer
{
public:
	static Size visibleSize;
	virtual bool init();
	CREATE_FUNC(GameSetting);

	int level;

private:
	void initSetting();
	void initButton();
	void pauseGame();
	Sprite* setting;
	bool onTouchBegan(Touch* touch, Event* event);
	void onTouchEnded(Touch* touch, Event* event);

	//加上 红色斜杠 代表关闭
	void addOff(Sprite* target);
};
