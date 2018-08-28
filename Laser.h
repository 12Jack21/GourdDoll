#pragma once
#ifndef _LASER_H_
#define _LASER_H_
#include "cocos2d.h"
#include "BaseBullet.h"
USING_NS_CC;

class Laser :public BaseBullet {
public:
	virtual bool init();
	CREATE_FUNC(Laser);
	void shoot();
	void removeLaser();
};
#endif

