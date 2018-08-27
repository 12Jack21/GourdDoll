#ifndef _SEVEN_DOLLV1_H_
#define _SEVEN_DOLLV1_H_

#include "SoundManager.h"
#include "cocos2d.h"
#include "BaseDoll.h"
#include "BaseMonster.h"
USING_NS_CC;

typedef enum {
	SevenDollStateNone = 0, //��״̬
	SevenDollStateAttack, //����
	SevenDollStateDeath,
}SevenDollState;
class SeventhDollv1 :public BaseDoll
{
public:
	CC_SYNTHESIZE(float, maxHp, MaxHp);
	CC_SYNTHESIZE(float, curHp, CurHp);
	CC_SYNTHESIZE(float, hpPercentage, HpPercentage);
	//����״̬
	CC_SYNTHESIZE(SevenDollState, state, State);
	//ֻ��get������û��set������get���صľ�����ֵ
	CC_SYNTHESIZE_READONLY(ProgressTimer*, hpBar, HpBar);

	Sprite * baseSprite;

	virtual void seventhdollv1death();
	BaseMonster* nearestMonster;
	virtual void updateSoldier(int level) {};
protected:
	//Ѫ��������
	virtual void createAndSetHpBar();
	Sprite* hpBgSprite;
	virtual void lookingForMonsters(float dt);

	//������������
	virtual void checkNearestMonster();
	//����
	virtual void attack();

	virtual void update(float dt) {};

	//����״̬
	SevenDollState lastState;

	virtual void stopSevenDollAnimation();
	void checkDirection(Point point);
	//false�ұ�true���
	virtual bool checkDirectionForMonster();
	float caculateTime(Point point);
	//ִ�н���
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


