#ifndef _FOURTH_DOLL_V3_H_
#define _FOURTH_DOLL_V3_H_
#include "BaseDoll.h"
#include "cocos2d.h"
USING_NS_CC;

class FourthDollv3 :public BaseDoll {
public:
	bool init();
	CREATE_FUNC(FourthDollv3);
	BaseBullet * FourthDollBullet();
};



#endif _FOURTH_DOLL_V3_H_
