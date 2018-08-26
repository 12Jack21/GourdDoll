#pragma once
#include "BaseMonster.h"
#include "cocos2d.h"
USING_NS_CC;

class Frog :public BaseMonster {
public:
	virtual bool init() override;
	static Frog *createMonster(std::vector<Point> points);
};

