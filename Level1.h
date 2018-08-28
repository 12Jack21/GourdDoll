#pragma once

#include "BaseLevel.h"
#include "SystemHeader.h"

USING_NS_CC;

class Level1 : public BaseLevel
{
public:
	Level1();
	~Level1();
	static Level1* createGame();
	virtual bool init();

private:

	//添加不同关卡的装饰物
	void addOrnament();
	void onExit();
	//void addMonsters(float dt);
	void addGourds();
};

