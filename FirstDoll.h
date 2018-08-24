#ifndef _FIRST_DOLL_H_
#define _FIRST_DOLL_H_

#include "BaseDoll.h"
#include "cocos2d.h"
#include "BaseBullet.h"

USING_NS_CC;
class FirstDoll : public BaseDoll {
protected:
	Sprite * shooter;
	Sprite * dollBase;
	BaseBullet * curBullet;
	void initDoll(int level);
	void addGourd();

	virtual BaseBullet * FirstDollBullet();
	void shoot(float dt);
};


#endif _FIRST_DOLL_H_