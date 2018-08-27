#ifndef _SEVEN_DOLLV1_H_
#define _SEVEN_DOLLV1_H_

#include "SoundManager.h"
#include "cocos2d.h"
#include "BaseDoll.h"
#include "BaseMonster.h"
USING_NS_CC;

typedef enum {
	SevenDollStateNone = 0, //无状态
	SevenDollStateAttack, //攻击
	SevenDollStateDeath,
}SevenDollState;
class SeventhDollv1 :public BaseDoll
{
public:
	CC_SYNTHESIZE(float, maxHp, MaxHp);
	CC_SYNTHESIZE(float, curHp, CurHp);
	CC_SYNTHESIZE(float, hpPercentage, HpPercentage);
	//七娃状态
	CC_SYNTHESIZE(SevenDollState, state, State);
	//只有get方法，没有set方法，get返回的就是其值
	CC_SYNTHESIZE_READONLY(ProgressTimer*, hpBar, HpBar);

	Sprite * baseSprite;

	virtual void seventhdollv1death();
	BaseMonster* nearestMonster;
	virtual void updateSoldier(int level) {};
protected:
	//血条的设置
	virtual void createAndSetHpBar();
	Sprite* hpBgSprite;
	virtual void lookingForMonsters(float dt);

	//检测最近的妖怪
	virtual void checkNearestMonster();
	//进攻
	virtual void attack();

	virtual void update(float dt) {};

	//基本状态
	SevenDollState lastState;

	virtual void stopSevenDollAnimation();
	void checkDirection(Point point);
	//false右边true左边
	virtual bool checkDirectionForMonster();
	float caculateTime(Point point);
	//执行进攻
	virtual void attackMonster(float dt) {};

	virtual bool init();
	CREATE_FUNC(SeventhDollv1);
	void updateDoll();
	void showUpdateMenu();
	BaseBullet * SeventhDollBullet();
    int attackCount;

private:
	void updateAnimation();
	void updateEffectAnimation(float dt);
};

#endif _SEVEN_DOLLV1_H_


