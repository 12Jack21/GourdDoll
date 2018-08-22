#pragma once
#include "SoundManager.h"
#include "GameManager.h"
#include "SystemHeader.h"

USING_NS_CC;

class BaseBullet : public Sprite
{
public:
	BaseBullet();
	~BaseBullet();
	virtual bool init();
	CREATE_FUNC(BaseBullet);

protected:
	//攻击力
	CC_SYNTHESIZE(int, maxForce, MaxForce);
	//娃娃的子弹攻击范围
	CC_SYNTHESIZE(int, bulletScope, BulletScope);
	//子弹类型
	CC_SYNTHESIZE(int, bulletType, BulletType);
	//子弹出现动作
	CC_SYNTHESIZE(Spawn*, bulletAction, BulletAction);

	Sprite* bullteSprite;
	virtual void shoot() {};
	virtual void removeBullet() {};
};
