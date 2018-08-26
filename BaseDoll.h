#pragma once

#include "BaseMonster.h"
#include "BaseBullet.h"
#include "SoundManager.h"
#include"SystemHeader.h"
#include "Gourd.h"

USING_NS_CC;

typedef enum {
<<<<<<< HEAD
	FIRSTDOLL_1 = 1,
	FIRSTDOLL_2,
	FIRSTDOLL_3,
	SECONDDOLL_1,
	SECONDDOLL_2,
	SECONDDOLL_3,
	FOURTHDOLL_1 = 7,
	FOURTHDOLL_2,
	FOURTHDOLL_3,
	FIFTHDOLL_1,
	FIFTHDOLL_2,
	FIFTHDOLL_3,
	SIXTHDOLL,
	SEVENTHDOLL_1,
	SEVENTHDOLL_2,

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

	//移除娃娃
	virtual void removeDoll();

	virtual bool init();

	CC_SYNTHESIZE(DollType, dollType, DollType);

	CC_SYNTHESIZE(Gourd*, myGourd, MyGourd);

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
	CC_SYNTHESIZE(int, updateGourd, UpdateGourd);
	//养育所需葫芦
	CC_SYNTHESIZE(int, fosterGourd, FosterGourd);
	//显示娃娃信息(攻击力，攻击速度等)
	virtual void showDollInfo();
	//升级菜单是否显示
	bool isUpdateMenuShown;

	virtual void update1() {};
	virtual void update2() {};

	//设置集结点
	virtual void setRallyPoint(Point point) {};

protected:

	Sprite * shooter;
	Sprite * dollBase;
	BaseBullet * curBullet;
	void initDoll(int level);
	void addGourd();

	virtual BaseBullet * FirstDollBullet();
	void shoot(float dt);

	virtual void checkNearestMonster();
	BaseMonster* nearestMonster;
	bool onTouchBegan(Touch *touch, Event *event);
	void onTouchEnded(Touch* touch, Event* event);
	virtual void showUpdateMenu() {};
	virtual void hideUpdateMenu();
	//(初始)葫芦
	Sprite* gourd;
	//设置监听器
	void setListener();

};
