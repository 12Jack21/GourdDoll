#pragma once

#include"SystemHeader.h"
#include"BaseDoll.h"

USING_NS_CC;

class DollInfoLayer :public Sprite
{
public:
	DollInfoLayer * createDollInfoLayer(DollType dollType);
	virtual bool init(DollType dollType);
	void setDollInfo(DollType dollType);
	Sprite* dollInfo_bg;

};