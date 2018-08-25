#include"GameManager.h"
#include"BaseMonster.h"

GameManager* GameManager::instance;

GameManager* GameManager::getInstance()
{
	if (instance == NULL)
		instance = new GameManager();
	return instance;
}

void GameManager::setInstance(int tag)
{
	sprintf(SLOTX_DONECOUNT, "Slot%d_DownCount", tag);
}

void GameManager::eraseAll()
{
	instance->monsterVector.clear();
	//instance->towerVector.clear();
}