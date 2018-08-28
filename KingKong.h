
#ifndef _KINGKONG_H_
#define _KINGKONG_H_

#include "cocos2d.h"
#include "BaseBullet.h"

USING_NS_CC;
class Kingkong : public BaseBullet
{
public:
	bool init();
	CREATE_FUNC(Kingkong);
	void shoot(Point location);
	void removeKingkong();
};

#endif _KINGKONG_H_
