#ifndef _WATERBALL_H_
#define _WATERBALL_H_

#include "cocos2d.h"
#include "BaseBullet.h"

USING_NS_CC;
class WaterBall : public BaseBullet
{
public:
	bool init();
	CREATE_FUNC(WaterBall);
	void shoot();
	void removeWaterBall();
};

#endif _WATERBALL_H_
