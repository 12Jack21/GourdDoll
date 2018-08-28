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

	//��Ӳ�ͬ�ؿ���װ����
	void addOrnament();
	void onExit();
	//void addMonsters(float dt);
	void addGourds();
};

