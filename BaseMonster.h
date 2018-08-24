#pragma once
#ifndef _BASE_MONSTER_H_
#define _BASE_MONSTER_H_

#include "cocos2d.h"

USING_NS_CC;

//妖怪基本状态
typedef enum {
	stateNone = 0, //无状态
	stateWalkRight, //向右走
	stateWalkLeft, //向左走
	stateWalkUp, //向上走
	stateWalkDown, //向下走
	stateAttackLeft, //向左攻击
	stateAttackRight, //向右攻击
	stateDeath,//死亡
}MonsterState;

//妖怪类型
typedef enum {

}MonsterType;

class BaseMonster : public Sprite
{
public:
	BaseMonster();
	~BaseMonster();
	virtual bool init() override;
	CREATE_FUNC(BaseMonster);
	Sprite* monsterSprite;

	//死亡
	virtual void death();

	CC_SYNTHESIZE(std::vector<Point>, pointsVector, PointsVector);
	//是否被三娃攻击
	CC_SYNTHESIZE(bool, attackBySoldier, AttackBySoldier);
	//怪物类型
	CC_SYNTHESIZE(MonsterType, monsterType, MonsterType);
	//是否被塔攻击
	CC_SYNTHESIZE(bool, attackByTower, AttackByTower);
	//是否处于 攻击状态
	CC_SYNTHESIZE(bool, isAttacking, IsAttacking);
	//移动速度
	CC_SYNTHESIZE(float, runSpeed, RunSpeed);
	//最大生命
	CC_SYNTHESIZE(float, maxHp, MaxHp);
	//当前血量
	CC_SYNTHESIZE(float, curHp, CurHp);
	//怪物攻击力
	CC_SYNTHESIZE(float, force, Force);
	//盔甲（物理抗性）
	CC_SYNTHESIZE(float, armor, Armor);
	//生命值百分比（供血量槽用）
	CC_SYNTHESIZE(float, hpPercentage, HpPercentage);
	//基本状态
	CC_SYNTHESIZE(MonsterState, state, State);
	//杀死后奖励葫芦
	CC_SYNTHESIZE(int, gourd, Gourd);
	//血量栏
	CC_SYNTHESIZE_READONLY(ProgressTimer*, hpBar, HpBar);

	virtual void stopWalking();
	virtual void restartWalking();
	//减速
	virtual void slowRunSpeed(float dt, float dis);

	//下个运动点
	Point getNextPoint();

private:

protected:
	void setMonsterZorder(int yOrder);
	int pointCounter;
	//血量精灵
	Sprite* hpBgSprite;
	//当前点
	Point currPoint();
	//下个点
	Point nextPoint();
	//
	Point tempNextPoint;
	void runNextPoint();
	void createAndSetHpBar();

	bool onTouchBegan(Touch* touch, Event* event);
	void onTouchEnded(Touch* touch, Event* event);

	virtual void update(float dt);//    im
	//检测是否减速
	CC_SYNTHESIZE(bool, isSlowed, IsSlowed);

	//血
	Sprite* blood;
	//中间状态
	MonsterState tempState;

	MonsterState lastState;

	void stopMonsterAnimation();

	void showInfo();

	void setListener();
};
#endif