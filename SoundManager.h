#pragma once
#include"SystemHeader.h"

class SoundManager
{
public:
	static void playClickEffect();
	static void playIncomingWave();
	static void playNextWaveReady();

	//音效
	static void playTowerMenu();
	static void playWinStars();

	//葫芦娃
	static void playDollSpawn();
	static void playDollUpdate();
	static void playDollSell();

	//妖怪（boss)
	static void playEffectLaugh();
	static void playEffectMove();
	static void playEffectDeath();

	//技能
	//六娃
	static void playSixDoll();
	//金刚山
	static void playKingkongMount();

	//关卡结束
	static void playGameWin();
	static void playGameFail();

public:
	//欢迎界面
	static void playWelcomeBackMusic();
	//游戏界面
	static void playGameBackMusic();

private:
	//检查音效状态
	static bool checkEffectState();
};