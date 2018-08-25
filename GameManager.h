#pragma once
#include"SystemHeader.h"


class GameManager
{
public:

	static GameManager* getInstance();


	
	/*Vector<Path*> pathVector;*/
	Vector<SeventhDollv1* > seventhDollv1Vector;
	Vector<BaseMonster*> monsterVector;
	Vector<BaseBullet*> bulletVector;
	int LEVEL;
	int GOURD;
	void setInstanceByTag(int tag);
	void eraseAll();
	
private:
	static GameManager * instance;
	
};