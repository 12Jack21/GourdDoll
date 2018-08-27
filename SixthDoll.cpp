#include "SixthDoll.h"
#include "BaseDoll.h"
#include "GameManager.h"
#include "BaseBullet.h"


bool SixthDoll::init() {
	if (!Sprite::init()) {
		return false;
	}
	bulletSprite = Sprite::createWithSpriteFrameName(".png");
	addChild(bulletSprite);
	this->setMaxForce(250);
	return true;
}

void SixthDoll::shoot(Point location) {
	setPosition(location);
	auto move = MoveBy::create(0.5f, Point(0, -320));
	runAction(Sequence::create(move,
		CallFuncN::create(CC_CALLBACK_0(SixthDoll::removeSixthDoll, this)),
		NULL));
}

void SixthDoll::removeSixthDoll()
{
	auto instance = GameManager::getInstance();

	auto sixthdollPostion = this->getPosition() + this->getParent()->getPosition();

	auto basedollVector = instance->baseDollVector;

	for (int j = 0; j < basedollVector.size(); j++)
	{
		auto basedoll = basedollVector.at(j);
		auto basedollPosition = basedoll->dollBase->getPosition();

		if (basedoll != NULL && sixthdollPostion.distance(basedollPosition) <= 30)
		{
			//音效
			SoundManager::playSixthDoll();
			int nowForce = basedoll->getForce();
			basedoll->setForce(nowForce + 100);
		}
	}
	//释放之后的特效
	bulletSprite->runAction(Sequence::create(
		Animate::create(AnimationCache::getInstance()->getAnimation("")),
		CallFuncN::create(CC_CALLBACK_0(SixthDoll::removeFromParent, this))
		, NULL));
}