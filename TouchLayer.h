#pragma once

#include "SystemHeader.h"
#include "BaseDoll.h"

USING_NS_CC;

class TouchLayer :public Layer
{
public:
	virtual bool init();
	CREATE_FUNC(TouchLayer);
	EventListenerTouchOneByOne* listener;
	EventListenerTouchOneByOne* touchlistener;
	EventListenerTouchOneByOne* ThirdDolllistener;

	EventListenerTouchOneByOne* SixthDolllistener;
	EventListenerTouchOneByOne* KingKonglistener;

	//设置 技能 触摸遮罩
	void setSixthDollTouchShield();
	void removeSixthDollTouchShield();
	bool onSixthDollTouchBegan(Touch* touch, Event* event);
	void onSixthDollTouchEnded(Touch* touch, Event* event);
	

	void setRallyFlagTouchShield();
	void removeRallyFlagTouchShield();
	bool onRallyFlagTouchBegan(Touch* touch, Event* event);
	void onRallyFlagTouchEnded(Touch* touch, Event* event);

	void setThirdDollTouchShield();
	void removeThirdDollTouchShield();
	bool onThirdDollTouchBegan(Touch* touch, Event* event);
	void onThirdDollTouchEnded(Touch* touch, Event* event);

	void setKingKongTouchShield();
	void removeKingKongTouchShield();
	bool onKingKongTouchBegan(Touch* touch, Event* event);
	void onKingKongTouchEnded(Touch* touch, Event* event);

	void removeTouchShield();
	void setTouchShield();

	BaseDoll* doll;

	//增加 集结旗（未定）
	void addRallyFlag(Point location);
	//增加 错误地方（图像上显示为一个红色的叉）
	void addWrongPlace(Point location);

	bool isFlag;
	bool onTouchBegan(Touch* touch, Event* event);
	void onTouchEnded(Touch* touch, Event* event);
	void onTouchMoved(Touch* touch, Event* event);
	Size winSize;

	void removeAllListener();
};

