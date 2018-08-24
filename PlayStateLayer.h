#pragma once

#include "SystemHeader.h"
#include "TouchLayer.h"
#include "GameManager.h"
#include "BaseDoll.h"
#include "BaseMonster.h"
#include "GameSetting.h"

USING_NS_CC;

#define TOWER_INFO 1001
#define MONSTER_INFO 1002

class PlayStateLayer : public Layer
{
public:
	void startProgressTimers();
	static Scene* createScene();
	virtual bool init();
	CREATE_FUNC(PlayStateLayer);
	void onEnterTransitionDidFinish();
	/*void showOption();*/
	Sprite* stateSprite;
	Sprite* pause;
	//ÉúÃü°å¿é
	Label* lifeLabel;
	//½ð±Ò°å¿é
	Label* goldLabel;
	//²¨Êý°å¿é
	Label* waveLabel;

	void showDollInfo(DollType dollType);
	void removeDollInfo();

	void showMonsterInfo(BaseMonster* monster);
	void removeMonsterInfo();
	void removeGameSetting();

private:
	CC_SYNTHESIZE(int, level, Level);
	//CC_SYNTHESIZE(int, difficult, Difficult);

	void clearMonsters();
	GameSetting *gameSetting;
	void addGameSetting();
	void pauseGame();
	void initGameSetting();
};
