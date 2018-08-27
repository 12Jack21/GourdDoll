#pragma once
#include "BaseMonster.h"
#include "cocos2d.h"
USING_NS_CC;

class TianNiu :public BaseMonster {
public:
	virtual bool init() override;
	static TianNiu *createMonster(std::vector<Point> points);
};