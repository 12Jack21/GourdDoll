#pragma once

#ifndef _FOURTH_DOLL_V1_H_
#define _FOURTH_DOLL_V1_H_
#include "BaseDoll.h"
#include "cocos2d.h"
USING_NS_CC;

class FourthDollv1 :public BaseDoll
{
public:
	virtual bool init();
	CREATE_FUNC(FourthDollv1);
	void updateDoll();
	void showUpdateMenu();
	BaseBullet * FourthDollBullet();
private:
	void updateAnimation();
	void updateEffectAnimation(float dt);
	void shoot(float dt);
};



#endif _FOURTH_DOLL_V1_H_