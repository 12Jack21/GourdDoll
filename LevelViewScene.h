#pragma once
#include"SystemHeader.h"

USING_NS_CC;
class LevelViewScene :public Layer
{
public:
	static Scene* createScene();
	virtual bool init();
	//初始化关卡选关菜单
	void initLevelMenu();
};