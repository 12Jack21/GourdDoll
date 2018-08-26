#pragma once
#ifndef _FIFTH_DOLL_V1_H_
#define _FIFTH_DOLL_V1_H_
#include "BaseDoll.h"
#include "cocos2d.h"
USING_NS_CC;

class FifthDollv1 :public BaseDoll
{
public:
	virtual bool init();
	CREATE_FUNC(FifthDollv1);
	void updateDoll();
	void showUpdateMenu();
	BaseBullet * FifthDollBullet();
private:
	void updateAnimation();
	void updateEffectAnimation(float dt);
};



#endif _FIRST_DOLL_V1_H_