#pragma once

#include"SystemHeader.h"
#include"BaseMonster.h"

class MonsterInfoLayer :public Sprite
{
public:
	static MonsterInfoLayer * createMonsterInfo(BaseMonster* monster);
	virtual bool init(BaseMonster* monster);
	void setMonsterInfo();
	BaseMonster* baseMonster;
	Sprite* info_bg;
	int maxHp;

	void updateHp();
	
	Label* hpLabel;

};