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
	//������
	CC_SYNTHESIZE(int, maxForce, MaxForce);
	//���޵��ӵ�������Χ
	CC_SYNTHESIZE(int, bulletScope, BulletScope);
	//�ӵ�����
	CC_SYNTHESIZE(int, bulletType, BulletType);
	//�ӵ����ֶ���
	CC_SYNTHESIZE(Spawn*, bulletAction, BulletAction);

	Sprite* bullteSprite;
	virtual void shoot() {};
	virtual void removeBullet() {};
};
