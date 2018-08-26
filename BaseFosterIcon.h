#pragma once
#include "SystemHeader.h"

USING_NS_CC;

class BaseFosterIcon : public Sprite
{
public:
	virtual bool initIcon(int type, int gourd);
	static BaseFosterIcon* createIcon(int type, int gourd);
	CREATE_FUNC(BaseFosterIcon);
	virtual void setSelected();
	virtual void setNotSelected();
	virtual void setNotEnoughGourd();
	virtual void setEnoughGourd();
	virtual void setUpdateGourd(int gourd);
	Sprite* baseIcon;

protected:
	//ºùÂ«ÊÇ·ñ×ã¹»
	CC_SYNTHESIZE(bool, isAble, IsAble);
	CC_SYNTHESIZE(int, type, Type);
	CC_SYNTHESIZE(bool, isSelected, IsSelected);
	CC_SYNTHESIZE(int, gourd, Gourd);
	void update(float dt);

	Sprite* okIcon;
	Sprite* priceIcon;
	Label* priceLabel;
};
