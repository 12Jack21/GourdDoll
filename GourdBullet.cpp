#include "GourdBullet.h"
#include "GameManager.h"

bool GourdBullet::init() {
	if (!Sprite::init()) {
		return false;
	}
	bulletSprite = Sprite::createWithSpriteFrameName(/*ÎÄ¼şÃû*/);
	addChild(bulletSprite);
	return true;
}