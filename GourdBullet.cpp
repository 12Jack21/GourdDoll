#include "GourdBullet.h"
#include "GameManager.h"

bool GourdBullet::init() {
	if (!Sprite::init()) {
		return false;
	}
	bulletSprite = Sprite::createWithSpriteFrameName(/*�ļ���*/);
	addChild(bulletSprite);
	return true;
}