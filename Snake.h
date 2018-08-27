#pragma once
#include "BaseMonster.h"
#include "cocos2d.h"
USING_NS_CC;

class Snake :public BaseMonster {
public:
	virtual bool init() override;
	static Snake *createMonster(std::vector<Point> points);
};