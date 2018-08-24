#ifndef _FIREBALL_H_
#define _FIREBALL_H_

#include "cocos2d.h"
#include "BaseBullet.h"

class FireBall : public BaseBullet
{
public:
	bool init();
	CREATE_FUNC(FireBall);
	void shoot();
	void removeFireBall();
};

#endif
