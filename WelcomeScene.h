#pragma once
#include"SystemHeader.h"

USING_NS_CC;

class WelcomeScene :public Layer
{
private:
	Size visibleSize;
	//����
	Sprite* bg;
	//logo
	Sprite* logo;
	Point logoPoint;
	//start��ť
	Sprite* start_Btn;
	Point start_BtnPoint();
	//about��ťλ��
	Sprite* about_Btn;
	Point about_BtnPoint();
	
public:
	static Scene* createScene();
	//��ʼ��
	virtual bool init();

	//logo����
	void initLogoAnimation();

	//������װ�ξ���
	void initOrnamentSprite();

	//��ʼ��������Ա����
	void initStartButton();
	void initAboutButton();
	void initSoundButton();

	void onEnterTransitionDidFinish();
};