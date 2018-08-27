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
	//无法升级的提示物
	Sprite* lock;
	CC_SYNTHESIZE(BaseDoll*, doll, Doll);

private:

	void addIcons();
	//菜单边框
	Sprite* borderSprite;
	//显示该等级攻击范围
	Circle* thisLvlCircle;
	//显示下一等级攻击范围
	Circle* nextLvlCircle;

	bool onTouchBegan(Touch* touch, Event* event);
	void onTouchEnded(Touch* touch, Event* event);
	bool isBuilt;
};

