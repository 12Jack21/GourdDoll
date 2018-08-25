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

	//ĳ�ؿ��Ƿ����,0��ʾδ��ɣ�1��ʾ���
	char LEVELX_ISDONE[20];

	//ĳ�浵ͨ����
	char SLOTX_DONECOUNT[20];

	//ʵʱ��«
	int GOURD;
	//ʵʱ����
	int LIFE;
	//�ؿ�
	int LEVEL;

	void setInstance(int tag);
	static void eraseAll();
	
private:
	static GameManager * instance;

};