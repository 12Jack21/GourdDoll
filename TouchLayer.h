#pragma once

#include "SystemHeader.h"
#include "BaseDoll.h"

USING_NS_CC;

class TouchLayer :public Layer
{
public:
	virtual bool init();
	CREATE_FUNC(TouchLayer);
	//ͨ�ü�����
	EventListenerTouchOneByOne* listener;

	EventListenerTouchOneByOne* SixthDolllistener;
	EventListenerTouchOneByOne* KingKonglistener;

	//���� ��� ��������
	void setKingKongTouchShield();
	void removeKingKongTouchShield();
	bool onKingKongTouchBegan(Touch* touch, Event* event);
	void onKingKongTouchEnded(Touch* touch, Event* event);

	BaseDoll* doll;

	//���� ����ط���ͼ������ʾΪһ����ɫ�Ĳ棩
	void addWrongPlace(Point location);

	Size winSize;

	void removeAllListener();
};

