#pragma once
#include"SystemHeader.h"

USING_NS_CC;

class AboutScene :public Layer
{
private:
	//背景
	Sprite * bg;
public:
	static Scene* createScene();

	virtual bool init();

	//初始化装饰精灵
	void initOrnamentSprite();

	//初始化字体
	void initLabel();

	//返回菜单回调
	void menuCallBack(Ref* pSender);

	void onExit();
};