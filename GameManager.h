#pragma once
#include"SystemHeader.h"


class GameManager
{
public:

	static GameManager* getInstance();

	/*
	Vector<Path*> pathVector;
	Vector<BaseDoll*> dollVector;
	Vector<BaseMonster*> monsterVector;
	Vector<Bullet*> bulletVector;
	*/

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