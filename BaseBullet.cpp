#include "BaseBullet.h"

BaseBullet::BaseBullet():bulletSprite(NULL), maxForce(0), bulletScope(0)
{
}

BaseBullet::~BaseBullet() {}

bool BaseBullet::init()
{
	if (!Sprite::init())
	{
		return false;
	}
	return true;
}