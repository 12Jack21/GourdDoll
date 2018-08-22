#pragma once

#include"SystemHeader.h"
#include"BaseMonster.h"

class MonsterInfoLayer :public Sprite
{
public:
	MonsterInfoLayer * createMonsterInfoLayer(BaseMonster* monster);
	virtual bool init(BaseMonster* monster);
	void setMonsterInfo();
	BaseMonster* baseMonster;
	Sprite* monsterInfo_bg;
	int maxHp;

	void updateHp();
	
	Label* hpLabel;

};