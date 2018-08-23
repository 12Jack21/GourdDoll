#pragma once
#ifndef _BASE_INFO_LAYER_H_
#define _BASE_INFO_LAYER_H_

#include "cocos2d.h"
#include "BaseDoll.h"

USING_NS_CC;

class BaseInfoLayer:public Sprite
{
public:
	static BaseInfoLayer* createBaseInfoLayer(DollType dolltype);
	virtual bool init(DollType dollType);
	void setBaseInfo(DollType dollType);
	Sprite * info;
      
};
#endif