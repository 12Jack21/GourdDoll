#pragma once
#include"SystemHeader.h"

USING_NS_CC;
class LevelViewScene :public Layer
{
public:
	static Scene* createScene();
	virtual bool init();
	//��ʼ���ؿ�ѡ�ز˵�
	void initLevelMenu();
};