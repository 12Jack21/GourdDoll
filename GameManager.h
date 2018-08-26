#pragma once
#include"SystemHeader.h"

USING_NS_CC;
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
	//��«��
	int GOURD;
	//үү����
	int LIFE;

	void setInstanceByTag(int tag);
	void eraseAll();
	
private:
	static GameManager * instance;

};