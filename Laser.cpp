#include "Laser.h"

bool Laser::init() {
	if (!Sprite::init()) {
		return false;
	}
	bulletSprite = Sprite::createWithSpriteFrameName(/*ÎÄ¼şÃû*/);
	addChild(bulletSprite);
	return true;
}