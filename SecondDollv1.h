
#ifndef _SECOND_DOLL_V1_H_
#define _SECOND_DOLL_V1_H_
#include "BaseDoll.h"
#include "cocos2d.h"
USING_NS_CC;

class SecondDollv1 :public BaseDoll
{
public:
	virtual bool init();
	CREATE_FUNC(SecondDollv1);
	void updateDoll();
	void showUpdateMenu();
	BaseBullet * SecondDollBullet();
private:
	void updateAnimation();
	void updateEffectAnimation(float dt);
	void shoot(float dt);
};



#endif _SECOND_DOLL_V1_H_