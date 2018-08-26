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

	//��������
	virtual void updateDoll() {};

	//������
	virtual void sellDoll();

	//�Ƴ�����
	virtual void removeDoll();

	virtual bool init();

	CC_SYNTHESIZE(DollType, dollType, DollType);

	CC_SYNTHESIZE(Gourd*, myGourd, MyGourd);

	CC_SYNTHESIZE(std::string, dollName, DollName);
	CC_SYNTHESIZE(int, level, Level);

	//������Χ
	CC_SYNTHESIZE(float, scope, Scope);

	CC_SYNTHESIZE(float, nextScope, NextScope);
	//����
	CC_SYNTHESIZE(float, rate, Rate);
	//������
	CC_SYNTHESIZE(int, force, Force);
	//���������«
	CC_SYNTHESIZE(int, updateGourd, UpdateGourd);
	//���������«
	CC_SYNTHESIZE(int, fosterGourd, FosterGourd);
	//��ʾ������Ϣ(�������������ٶȵ�)
	virtual void showDollInfo();
	//�����˵��Ƿ���ʾ
	bool isUpdateMenuShown;

	virtual void update1() {};
	virtual void update2() {};

	//���ü����
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
	//(��ʼ)��«
	Sprite* gourd;
	//���ü�����
	void setListener();

};
