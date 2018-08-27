#pragma once
#include"SystemHeader.h"
#include "BaseMonster.h"
#include "BaseDoll.h"
#include "SeventhDollv1.h"


class GameManager
{
public:

	static GameManager* getInstance();


	
	/*Vector<Path*> pathVector;*/
	Vector<BaseDoll *> baseDollVector;
	Vector<SeventhDollv1* > seventhDollv1Vector;
	Vector<BaseMonster *> monsterVector;
	Vector<BaseBullet *> bulletVector;
	int LEVEL;
	int GOURD;
	void setInstanceByTag(int tag);
	void eraseAll();
	
private:
	static GameManager * instance;
	
};