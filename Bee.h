#pragma once
#include "BaseMonster.h"
#include "cocos2d.h"
USING_NS_CC;

class Bee :public BaseMonster {
public:
	virtual bool init() override;
	static Bee *createMonster(std::vector<Point> points);
};