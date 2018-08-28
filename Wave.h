#pragma once
#include"SystemHeader.h"
#include"BaseMonster.h"

USING_NS_CC;

class Wave : public Node
{
public:
	Point position;
	int totalMonsters;
	double spawnRate;
	BaseMonster* monsterType;
	virtual bool init();
	Wave* initWithMonster(BaseMonster* monster, double SpawnRate, int TotalMonsters);
	CREATE_FUNC(Wave);
};