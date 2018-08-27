#pragma once

#include "SystemHeader.h"

USING_NS_CC;

class Gourd:public Sprite
{
public:
	//一种类型的葫芦
	virtual bool init();
	static Gourd * createGourd();

	//养育葫芦 菜单
	void showFosterMenu();

	bool isFosterMenuShown;
	void hideFosterMenu();
	Sprite * gourd;
	bool onTouchBegan(Touch* touch, Event* event);
	void onTouchEnded(Touch* touch, Event* event);
	void Effect();//
};
