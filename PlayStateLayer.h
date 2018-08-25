#pragma once

#include "SystemHeader.h"
#include "TouchLayer.h"
#include "GameManager.h"
#include "BaseDoll.h"
#include "BaseMonster.h"
#include "GameSetting.h"

USING_NS_CC;

#define Doll_INFO 1001
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

	//生命板块
	Label* lifeLabel;
	//葫芦板块
	Label* gourdLabel;
	//波数板块
	Label* waveLabel;
	//金刚精灵
	Sprite* kingKongSprite;

	void updateKingKongProgress(float dt);

	TouchLayer* touchLayer;
	void setLife(int life);
	void setGourd(int gourd);
	void setWave(int thisWave, int totalWave);
	void showDollInfo(DollType dollType);
	void removeDollInfo();

	void showMonsterInfo(BaseMonster* monster);
	void removeMonsterInfo();

	ProgressTimer* kingKongTimer;

	bool isCompleteKingKong;
	//开启金刚计时
	void startKingKong();
	//开启六娃计时
	void startSixthDoll();

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
