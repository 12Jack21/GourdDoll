#pragma once
#include"SystemHeader.h"
#include "BaseMonster.h"
#include "BaseDoll.h"
#include "SeventhDollv1.h"

USING_NS_CC;

class GameManager
{
public:

	static GameManager* getInstance();

		//ĳ�ؿ��Ƿ����,0��ʾδ��ɣ�1��ʾ���
	char LEVELX_ISDONE[20];

	//ĳ�浵ͨ����
	char SLOTX_DONECOUNT[20];
	
	/*Vector<Path*> pathVector;*/
	Vector<BaseDoll *> baseDollVector;
	Vector<SeventhDollv1* > seventhDollv1Vector;
	Vector<BaseMonster *> monsterVector;
	Vector<BaseBullet *> bulletVector;
	int LEVEL;

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

