
#ifndef _FIRST_DOLL_V1_H
#define _FIRST_DOLL_V1_H
#include "FirstDoll.h"
#include "cocos2d.h"
USING_NS_CC;

class FirstDollv1:public FirstDoll
{
public:
	virtual bool init();
	CREATE_FUNC(FirstDollv1);
	void updateDoll();
	void showUpdateMenu();
	BaseBullet * FirstDollBullet();
private:
	void updateAnimation();
	void updateEffectAnimation(float dt);
};



#endif _FIRST_DOLL_V1_H