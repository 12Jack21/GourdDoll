#ifndef _SEVENTH_DOLL_V2_H_
#define _SEVENTH_DOLL_V2_H_
#include "BaseDoll.h"
#include "cocos2d.h"
#include "SeventhDollv1.h"
USING_NS_CC;

class SeventhDollv2 :public SeventhDollv1
{
public:
	bool init();
	CREATE_FUNC(SeventhDollv2);
	void createAndSetHpBar();
	virtual void seventhdollv2Death();
	BaseBullet * SeventhDollBullet();
};

//typedef enum {
//	SevenDollStateNone = 0, //无状态
//	SevenDollStateAttack, //攻击
//	SevenDollStateDeath,//死亡
//}SevenDollState;
//
//class SeventhDollv2 :public BaseDoll {
//public:
//	bool init();
//	CREATE_FUNC(SeventhDollv2);
//	BaseBullet * SeventhDollBullet();
//	CC_SYNTHESIZE(float, maxHp, MaxHp);
//	CC_SYNTHESIZE(float, curHp, CurHp);
//	CC_SYNTHESIZE(float, hpPercentage, HpPercentage);
//	//七娃状态
//	CC_SYNTHESIZE(SevenDollState, state, State);
//	//只有get方法，没有set方法，get返回的就是其值
//	CC_SYNTHESIZE_READONLY(ProgressTimer*, hpBar, HpBar);
//
//	Sprite * baseSprite;
//
//	virtual void death();
//	BaseMonster* nearestMonster;
//protected:
//	//血条的设置
//	virtual void createAndSetHpBar();
//	Sprite* hpBgSprite;
//	virtual void update(float dt) {};
//
//	//基本状态
//	SevenDollState lastState;
//	virtual void attackMonster(float dt) {};
//
//	virtual bool init();
//	void updateDoll();
//	void showUpdateMenu();
//	BaseBullet * SeventhDollBullet();
//	int attackCount;
//};



#endif _SEVENTH_DOLL_V2_H_