#pragma once
#ifndef _FIFTH_DOLL_V2_H_
#define _FIFTH_DOLL_V2_H_
#include "BaseDoll.h"
#include "cocos2d.h"
USING_NS_CC;

class FifthDollv2 :public BaseDoll {
public:
	bool init();
	CREATE_FUNC(FifthDollv2);
	void updateDoll();
	void showUpdateMenu();
	BaseBullet * FifthDollBullet();
};



#endif _FIFTH_DOLL_V2_H_