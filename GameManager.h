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

	void setInstanceByTag(int tag);
	void eraseAll();

private:
	static GameManager * instance;

};