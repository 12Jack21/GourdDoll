
#ifndef _FIRST_DOLL_V1_H_
#define _FIRST_DOLL_V1_H_
#include "BaseDoll.h"
#include "cocos2d.h"
USING_NS_CC;

class FirstDollv1:public BaseDoll
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



#endif _FIRST_DOLL_V1_H_