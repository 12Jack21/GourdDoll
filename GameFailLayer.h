#pragma once
#include "SystemHeader.h"

USING_NS_CC;

class GameFailLayer : public Layer
{

public:

	virtual bool init();
	void initMap();
	void starMenu(Ref *pSpender);
	//返回按钮回调
	void callBackMenu(Ref *pSpender);
	void getItemMenu(Ref *pSpender);
	CREATE_FUNC(GameFailLayer);
	int level;
	//int difficulty;

private:
	void pauseGame();
	void initOption();
	Sprite* option;
	bool onTouchBegan(Touch* touch, Event* event);
	void onTouchEnded(Touch* touch, Event* event);
};