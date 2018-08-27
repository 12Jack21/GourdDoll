#pragma once

#include "SystemHeader.h"
#include "Circle.h"
#include "UpdateIcon.h"
#include "BaseDoll.h"
#include "SellIcon.h"
#include"BaseFosterIcon.h"

USING_NS_CC;

class UpdateMenu : public Sprite
{
public:

	virtual bool init() override;
	CREATE_FUNC(UpdateMenu);
	void inAnimation();
	BaseFosterIcon* updateIcon;
	SellIcon* sellIcon;
	bool canUpdate;
	//�޷���������ʾ��
	Sprite* lock;
	CC_SYNTHESIZE(BaseDoll*, doll, Doll);

private:

	void addIcons();
	//�˵��߿�
	Sprite* borderSprite;
	//��ʾ�õȼ�������Χ
	Circle* thisLvlCircle;
	//��ʾ��һ�ȼ�������Χ
	Circle* nextLvlCircle;

	bool onTouchBegan(Touch* touch, Event* event);
	void onTouchEnded(Touch* touch, Event* event);
	bool isBuilt;
};

