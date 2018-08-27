
#ifndef _FIRST_DOLL_V3_H_
#define _FIRST_DOLL_V3_H_
#include "BaseDoll.h"
#include "cocos2d.h"
USING_NS_CC;

class FirstDollv3 :public BaseDoll {
public:
	bool init();
	CREATE_FUNC(FirstDollv3);
	BaseBullet * FirstDollBullet();
	void shoot(float dt);
};



#endif _FIRST_DOLL_V3_H_
