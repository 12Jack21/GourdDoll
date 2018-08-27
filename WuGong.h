#pragma once
#include "BaseMonster.h"
#include "cocos2d.h"
USING_NS_CC;

class WuGong :public BaseMonster {
public:
	virtual bool init() override;
	static WuGong *createMonster(std::vector<Point> points);
};