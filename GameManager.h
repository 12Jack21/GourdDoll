#pragma once
#include"SystemHeader.h"
#include "BaseBullet.h"
#include "cocos2d.h"
#include "BaseMonster.h"
#include "BaseDoll.h"
#include "SeventhDollv1.h"
#include "TouchLayer.h"
#include"WayPoint.h"

USING_NS_CC;

class GameManager
{
public:

	static GameManager* getInstance();

		//某关卡是否完成,0表示未完成，1表示完成
	char LEVELX_ISDONE[20];
	//路标
	Vector<WayPoint*> wayPoints;

	/*Vector<SeventhDollv1*> seventhDollv1Vector;*/

	Vector<BaseDoll *> baseDollVector;
	Vector<BaseMonster *> monsterVector;
	Vector<BaseBullet*>bulletVector;
	

		//某关卡是否完成,0表示未完成，1表示完成
	char LEVELX_ISDONE[20];

	//某存档通关数
	char SLOTX_DONECOUNT[20];

	//实时葫芦
	int GOURD;
	//实时生命
	int LIFE;
	//关卡
	int LEVEL;

	void setInstance(int tag);
	static void eraseAll();
	
private:
	static GameManager * instance;

};

