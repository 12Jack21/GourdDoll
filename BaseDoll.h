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

	//升级娃娃
	virtual void updateDoll() {};
	//卖娃娃
	virtual void sellDoll();

	//移除塔
	virtual void removeDoll();

	virtual bool init();

	CC_SYNTHESIZE(DollType, dollType, DollType);
	//CC_SYNTHESIZE(Terrain*, myTerrain, MyTerrain);
	CC_SYNTHESIZE(std::string, dollName, DollName);
	CC_SYNTHESIZE(int, level, Level);

	//攻击范围
	CC_SYNTHESIZE(float, scope, Scope);
	CC_SYNTHESIZE(float, nextScope, NextScope);
	//攻速
	CC_SYNTHESIZE(float, rate, Rate);
	//攻击力
	CC_SYNTHESIZE(int, force, Force);
	//升级所需葫芦
	CC_SYNTHESIZE(int, updateMoney, UpdateMoney);
	//产生所需葫芦
	CC_SYNTHESIZE(int, buildMoney, BuildMoney);

	virtual void showDollInfo();
	//升级菜单是否显示
	bool isUpdateMenuShown;

	virtual void update1() {};
	virtual void update2() {};

	//设置集结点
	virtual void setRallyPoint(Point point) {};

protected:
	virtual void checkNearestMonster();
	BaseMonster* nearestMonster;
	bool onTouchBegan(Touch *touch, Event *event);
	void onTouchEnded(Touch* touch, Event* event);
	virtual void showUpdateMenu() {};
	virtual void hideUpdateMenu();
	//土堆
	Sprite* terrain;
	//设置监听器
	void setListener();

};

#endif