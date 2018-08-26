
#ifndef _SEOCOND_DOLL_V3_H_
#define _SEOCOND_DOLL_V3_H_
#include "BaseDoll.h"
#include "cocos2d.h"
USING_NS_CC;

class SecondDollv3 :public BaseDoll {
public:
	bool init();
	CREATE_FUNC(SecondDollv3);
	BaseBullet * SecondDollBullet();
};



#endif _SEOCOND_DOLL_V3_H_
