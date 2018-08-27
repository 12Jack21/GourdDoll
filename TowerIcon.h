#pragma once
#ifndef _TOWERICON_H_
#define _TOWERICON_H_

#include "cocos2d.h"
USING_NS_CC;

class TowerIcon :public Sprite {
public:
	virtual bool initIcon(int type, int gourd);
	static TowerIcon * createIcon(int type, int gourd);
	CREATE_FUNC(TowerIcon);
	virtual void setSelected();
	virtual void setNotSelected();
	virtual void setNotEnoughGourd();
	virtual void setEnoughGourd();
	virtual void setUpdateGourd(int Gourd);
	Sprite* towerIcon;

protected:
	CC_SYNTHESIZE(bool, can, Can);
	CC_SYNTHESIZE(int, type, Type);
	CC_SYNTHESIZE(bool, isSelected, IsSelected);
	CC_SYNTHESIZE(int, gourd, Gourd);
	void update(float dt);
	Sprite* okIcon;
	Sprite* gourdIcon;
	Label* gourdLabel;
};
#endif

