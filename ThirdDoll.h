#pragma once

#include "SoundManager.h"
#include "BaseMonster.h"
#include "SystemHeader.h"
USING_NS_CC;

typedef enum {
	ThirdDollStateNone = 0, //无状态
	ThirdDollStateWalk,//行走

	//ThirdDollStateByAttacked, //被攻击

	ThirdDollStateDeath,//死亡
	ThirdDollStateSearch,//寻找敌人

}ThirdDollState;

class BaseThirdDoll : public Sprite
{
public:
	CC_SYNTHESIZE(float, maxHp, MaxHp);
	CC_SYNTHESIZE(float, curHp, CurHp);

	//CC_SYNTHESIZE(float, force, Force);

	CC_SYNTHESIZE(float, armor, Armor);
	CC_SYNTHESIZE(float, hpPercentage, HpPercentage);
	CC_SYNTHESIZE(ThirdDollState, state, State);
	CC_SYNTHESIZE_READONLY(ProgressTimer*, hpBar, HpBar);
	CC_SYNTHESIZE(Point, location, Location);

	//不管是近战兵，塔，妖怪等都得建立 baseSprite
	Sprite* baseSprite;

	//指定位置让三娃过去
	virtual void runToLocation(Point point);
	virtual bool init();

	//最近的妖怪 （MIm）
	BaseMonster* nearestMonster;
	virtual void updateThirdDoll(int level) {};

protected:

	virtual void createAndSetHpBar();
	//血量背景精灵
	Sprite* hpBgSprite;
	virtual void SearchingMonster(float dt);

	//检测最近的妖怪
	virtual void checkNearestMonster();

	//进攻
	//virtual void attack();

	virtual void update(float dt) {};

	virtual void runToDestination(Point destination, bool isAttacking) {};
	//基本状态
	ThirdDollState lastState;

	virtual void stopThirdDollAnimation();
	void checkDirection(Point point);
	//false右边	true左边
	virtual bool checkDirectionForMonster();

	float caculateTime(Point point);

	//向怪物接近
	virtual void runToMonster();

	//执行进攻
	//virtual void attackMonster(float dt) {};

	//int attackCount;

};
