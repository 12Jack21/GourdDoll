#include "Laser.h"

bool Laser::init() {
	if (!Sprite::init()) {
		return false;
	}
	bulletSprite = Sprite::createWithSpriteFrameName(/*�ļ���*/);
	addChild(bulletSprite);
	return true;
}