#ifndef _STONE_H_
#define _STONE_H_
#include "cocos2d.h"
#include "BaseBullet.h"
USING_NS_CC;

class Stone :public BaseBullet {
public:
	virtual bool init();
	CREATE_FUNC(Stone);
	void shoot();
	void removeStone();
}
#endif
