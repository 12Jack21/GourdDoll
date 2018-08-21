#pragma once
#include"SystemHeader.h"

USING_NS_CC;

class WelcomeScene :public Layer
{
private:
	Size visibleSize;
	//背景
	Sprite* bg;
	//logo
	Sprite* logo;
	Point logoPoint;
	//start按钮
	Sprite* start_Btn;
	Point start_BtnPoint();
	//about按钮位置
	Sprite* about_Btn;
	Point about_BtnPoint();
	
public:
	static Scene* createScene();
	//初始化
	virtual bool init();

	//logo动画
	void initLogoAnimation();

	//场景中装饰精灵
	void initOrnamentSprite();

	//初始化三个成员按键
	void initStartButton();
	void initAboutButton();
	void initSoundButton();

	void onEnterTransitionDidFinish();
};