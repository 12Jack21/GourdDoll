#pragma once
#include"SystemHeader.h"

USING_NS_CC;

class AboutScene :public Layer
{
private:
	//����
	Sprite * bg;
public:
	static Scene* createScene();

	virtual bool init();

	//��ʼ��װ�ξ���
	void initOrnamentSprite();

	//��ʼ������
	void initLabel();

	//���ز˵��ص�
	void menuCallBack(Ref* pSender);

	void onExit();
};