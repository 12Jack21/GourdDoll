#pragma once

#include "BaseFosterIcon.h"
#include "SystemHeader.h"

USING_NS_CC;

class SellIcon : public BaseFosterIcon
{
public:
	virtual bool init();
	CREATE_FUNC(SellIcon);
	void setSelected();
	void setNotSelected();
};
