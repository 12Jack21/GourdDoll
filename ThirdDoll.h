#pragma once

#include "SoundManager.h"
#include "BaseMonster.h"
#include "SystemHeader.h"
USING_NS_CC;

typedef enum {
	ThirdDollStateNone = 0, //��״̬
	ThirdDollStateWalk,//����

	//ThirdDollStateByAttacked, //������

	ThirdDollStateDeath,//����
	ThirdDollStateSearch,//Ѱ�ҵ���

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

	//�����ǽ�ս�����������ֵȶ��ý��� baseSprite
	Sprite* baseSprite;

	//ָ��λ�������޹�ȥ
	virtual void runToLocation(Point point);
	virtual bool init();

	//��������� ��MIm��
	BaseMonster* nearestMonster;
	virtual void updateThirdDoll(int level) {};

protected:

	virtual void createAndSetHpBar();
	//Ѫ����������
	Sprite* hpBgSprite;
	virtual void SearchingMonster(float dt);

	//������������
	virtual void checkNearestMonster();

	//����
	//virtual void attack();

	virtual void update(float dt) {};

	virtual void runToDestination(Point destination, bool isAttacking) {};
	//����״̬
	ThirdDollState lastState;

	virtual void stopThirdDollAnimation();
	void checkDirection(Point point);
	//false�ұ�	true���
	virtual bool checkDirectionForMonster();

	float caculateTime(Point point);

	//�����ӽ�
	virtual void runToMonster();

	//ִ�н���
	//virtual void attackMonster(float dt) {};

	//int attackCount;

};
