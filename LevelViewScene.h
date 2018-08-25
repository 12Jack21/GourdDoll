#pragma once
#include"SystemHeader.h"

USING_NS_CC;
class LevelViewScene :public Layer
{
public:
	static Size visibleSize;
	static Scene* createScene();
	virtual bool init();

	bool onTouchBegan(Touch* touch, Event* event);
	void onTouchEnded(Touch* touch, Event* event);

	//��ʼ���ؿ�ѡ�ز˵�(�߸���«)
	void initLevelMenu();
};