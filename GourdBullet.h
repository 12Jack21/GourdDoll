#ifndef _GOURDBULLET_H_
#define _GOURDBULLET_H_
#include "cocos2d.h"
#include "BaseBullet.h"
USING_NS_CC;

class GourdBullet :public BaseBullet {
public:
	virtual bool init();
	CREATE_FUNC(GourdBullet);
	void shoot();
	void removeGourdBullet();
};
#endif _GOURDBULLET_H_

