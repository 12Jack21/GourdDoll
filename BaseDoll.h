#pragma once
#ifndef _BASE_Doll_
#define _BASE_Doll_

#include "BaseMonster.h"
#include "SoundManager.h"
#include"SystemHeader.h"

USING_NS_CC;

typedef enum {
	
}DollType;

class BaseDoll : public Sprite
{
public:
	BaseDoll();
	~BaseDoll();

	//��������
	virtual void updateDoll() {};
	//������
	virtual void sellDoll();

	//�Ƴ���
	virtual void removeDoll();

	virtual bool init();

	CC_SYNTHESIZE(DollType, dollType, DollType);
	//CC_SYNTHESIZE(Terrain*, myTerrain, MyTerrain);
	CC_SYNTHESIZE(std::string, dollName, DollName);
	CC_SYNTHESIZE(int, level, Level);

	//������Χ
	CC_SYNTHESIZE(float, scope, Scope);
	CC_SYNTHESIZE(float, nextScope, NextScope);
	//����
	CC_SYNTHESIZE(float, rate, Rate);
	//������
	CC_SYNTHESIZE(int, force, Force);
	//���������«
	CC_SYNTHESIZE(int, updateMoney, UpdateMoney);
	//���������«
	CC_SYNTHESIZE(int, buildMoney, BuildMoney);

	virtual void showDollInfo();
	//�����˵��Ƿ���ʾ
	bool isUpdateMenuShown;

	virtual void update1() {};
	virtual void update2() {};

	//���ü����
	virtual void setRallyPoint(Point point) {};

protected:
	virtual void checkNearestMonster();
	BaseMonster* nearestMonster;
	bool onTouchBegan(Touch *touch, Event *event);
	void onTouchEnded(Touch* touch, Event* event);
	virtual void showUpdateMenu() {};
	virtual void hideUpdateMenu();
	//����
	Sprite* terrain;
	//���ü�����
	void setListener();

};

#endif