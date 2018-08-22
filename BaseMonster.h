#pragma once
#ifndef _BASE_MONSTER_H_
#define _BASE_MONSTER_H_

#include "cocos2d.h"

USING_NS_CC;

//���ֻ���״̬
typedef enum {
	stateNone = 0, //��״̬
	stateWalkRight, //������
	stateWalkLeft, //������
	stateWalkUp, //������
	stateWalkDown, //������
	stateAttackLeft, //���󹥻�
	stateAttackRight, //���ҹ���
	stateDeath,//����
}MonsterState;

//��������
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

	//����
	virtual void death();

	CC_SYNTHESIZE(std::vector<Point>, pointsVector, PointsVector);
	//�Ƿ����޹���
	CC_SYNTHESIZE(bool, attackBySoldier, AttackBySoldier);
	//��������
	CC_SYNTHESIZE(MonsterType, monsterType, MonsterType);
	//�Ƿ�������
	CC_SYNTHESIZE(bool, attackByTower, AttackByTower);
	//�Ƿ��� ����״̬
	CC_SYNTHESIZE(bool, isAttacking, IsAttacking);
	//�ƶ��ٶ�
	CC_SYNTHESIZE(float, runSpeed, RunSpeed);
	//�������
	CC_SYNTHESIZE(float, maxHp, MaxHp);
	//��ǰѪ��
	CC_SYNTHESIZE(float, curHp, CurHp);
	//���﹥����
	CC_SYNTHESIZE(float, force, Force);
	//���ף������ԣ�
	CC_SYNTHESIZE(float, armor, Armor);
	//����ֵ�ٷֱȣ���Ѫ�����ã�
	CC_SYNTHESIZE(float, hpPercentage, HpPercentage);
	//����״̬
	CC_SYNTHESIZE(MonsterState, state, State);
	//ɱ��������«
	CC_SYNTHESIZE(int, gourd, Gourd);
	//Ѫ����
	CC_SYNTHESIZE_READONLY(ProgressTimer*, hpBar, HpBar);

	virtual void stopWalking();
	virtual void restartWalking();
	//����
	virtual void slowRunSpeed(float dt, float dis);

	//�¸��˶���
	Point getNextPoint();

private:

protected:
	void setMonsterZorder(int yOrder);
	int pointCounter;
	//Ѫ������
	Sprite* hpBgSprite;
	//��ǰ��
	Point currPoint();
	//�¸���
	Point nextPoint();
	//
	Point tempNextPoint;
	void runNextPoint();
	void createAndSetHpBar();

	bool onTouchBegan(Touch* touch, Event* event);
	void onTouchEnded(Touch* touch, Event* event);

	virtual void update(float dt);//    im
	//����Ƿ����
	CC_SYNTHESIZE(bool, isSlowed, IsSlowed);

	//Ѫ
	Sprite* blood;
	//�м�״̬
	MonsterState tempState;

	MonsterState lastState;

	void stopMonsterAnimation();

	void showInfo();

	void setListener();
};
#endif