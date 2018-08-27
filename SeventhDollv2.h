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
//	SevenDollStateNone = 0, //��״̬
//	SevenDollStateAttack, //����
//	SevenDollStateDeath,//����
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
//	//����״̬
//	CC_SYNTHESIZE(SevenDollState, state, State);
//	//ֻ��get������û��set������get���صľ�����ֵ
//	CC_SYNTHESIZE_READONLY(ProgressTimer*, hpBar, HpBar);
//
//	Sprite * baseSprite;
//
//	virtual void death();
//	BaseMonster* nearestMonster;
//protected:
//	//Ѫ��������
//	virtual void createAndSetHpBar();
//	Sprite* hpBgSprite;
//	virtual void update(float dt) {};
//
//	//����״̬
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