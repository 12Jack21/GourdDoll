#pragma once

#ifndef _SECOND_DOLL_V2_H_
#define _SECOND_DOLL_V2_H_
#include "BaseDoll.h"
#include "cocos2d.h"
USING_NS_CC;

class SecondDollv2 :public BaseDoll {
public:
	bool init();
	CREATE_FUNC(SecondDollv2);
	void updateDoll();
	void showUpdateMenu();
	BaseBullet * SecondDollBullet();
private:
	void shoot(float dt);
};



#endif _SECOND_DOLL_V2_H_