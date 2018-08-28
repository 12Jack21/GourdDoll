#include "Wave.h"

USING_NS_CC;

bool Wave::init()
{
	if (!Node::init())
	{
		return false;
	}

	return true;
}

Wave* Wave::initWithMonster(BaseMonster* monster, double SpawnRate, int TotalMonsters)
{
	this->monsterType = monster;
	this->spawnRate = SpawnRate;
	this->totalMonsters = TotalMonsters;

	return this;
}