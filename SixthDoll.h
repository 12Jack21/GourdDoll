#ifndef _SIXTHDOLL_H_
#define _SIXTHDOLL_H_
#include "cocos2d.h"
#include "BaseBullet.h"
USING_NS_CC;

class SixthDoll :public BaseBullet {
public:
	virtual bool init();
	CREATE_FUNC(SixthDoll);
	void shoot(Point location);
	void removeSixthDoll();
}
#endif _SIXTHDOLL_H_
