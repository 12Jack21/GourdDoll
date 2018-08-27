#pragma once
#include "BaseMonster.h"
#include "cocos2d.h"
USING_NS_CC;

class XieZi :public BaseMonster {
public:
	virtual bool init() override;
	static XieZi *createMonster(std::vector<Point> points);
};