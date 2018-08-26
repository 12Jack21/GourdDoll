#pragma once
#include "BaseMonster.h"
#include "cocos2d.h"
USING_NS_CC;

class Bat :public BaseMonster {
public:
	virtual bool init() override;
	static Bat *createMonster(std::vector<Point> points);
};
