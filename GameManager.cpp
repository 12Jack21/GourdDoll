#include"GameManager.h"

GameManager* GameManager::instance;
GameManager* GameManager::getInstance()
{
	if (instance == NULL)
	{
		instance = new GameManager();
	}
	return instance;
}

void GameManager::eraseAll()
{
	instance->monsterVector.clear();
	instance->seventhDollv1Vector.clear();
	instance->baseDollVector.clear();
}