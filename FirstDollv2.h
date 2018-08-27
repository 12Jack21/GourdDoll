
#ifndef _FIRST_DOLL_V2_H_
#define _FIRST_DOLL_V2_H_
#include "BaseDoll.h"
#include "cocos2d.h"
USING_NS_CC;

class FirstDollv2 :public BaseDoll {
public:
    bool init();
	CREATE_FUNC(FirstDollv2);
	void updateDoll();
	void showUpdateMenu();
	BaseBullet * FirstDollBullet();
	void shoot(float dt);
};



#endif _FIRST_DOLL_V2_H_