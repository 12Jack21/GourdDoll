#pragma once

#include "SystemHeader.h"
#include "BaseDoll.h"

USING_NS_CC;

class TouchLayer :public Layer
{
public:
	virtual bool init();
	CREATE_FUNC(TouchLayer);
	//通用监听器
	EventListenerTouchOneByOne* listener;

	EventListenerTouchOneByOne* SixthDolllistener;
	EventListenerTouchOneByOne* KingKonglistener;

	//设置 金刚 触摸遮罩
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

	BaseDoll* doll;

	//增加 错误地方（图像上显示为一个红色的叉）
	void addWrongPlace(Point location);

	Size winSize;

	void removeAllListener();
};

