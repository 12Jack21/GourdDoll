#ifndef _FIFTH_DOLL_V3_H_
#define _FIFTH_DOLL_V3_H_
#include "BaseDoll.h"
#include "cocos2d.h"
USING_NS_CC;

class FifthDollv3 :public BaseDoll {
public:
	bool init();
	CREATE_FUNC(FifthDollv3);
	BaseBullet * FifthDollBullet();
};



#endif _FIFTH_DOLL_V3_H_
