#pragma once

#ifndef _FOURTH_DOLL_V2_H_
#define _FOURTH_DOLL_V2_H_
#include "BaseDoll.h"
#include "cocos2d.h"
USING_NS_CC;

class FourthDollv2 :public BaseDoll {
public:
	bool init();
	CREATE_FUNC(FourthDollv2);
	void updateDoll();
	void showUpdateMenu();
	BaseBullet * FourthDollBullet();
private:
	void shoot(float dt);
};


#endif _FOURTH_DOLL_V2_H_
