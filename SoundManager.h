#pragma once
#include"SystemHeader.h"

class SoundManager
{
public:
	static void playClickEffect();
	//即将到来的波数
	static void playIncomingWave();
	static void playNextWaveReady();

	//音效
	static void playDollMenu();
	static void playWinStars();
	static void playGameFail();

	//葫芦娃
	static void playDollFoster();
	static void playDollUpdate();
	static void playDollSell();

	//大娃石头砸地音效
	static void playFirsetDollAttack();
	//二娃激光发射音效
	static void playSecondDollAttack();


	//妖怪（boss)
	static void playEffectLaugh();
	static void playEffectMove();
	static void playEffectDeath();

	//技能
	//六娃释放
	static void playSixthDoll();
	//金刚山释放
	static void playKingkong();

	//关卡结束
	static void playGameWin();



public:
	//欢迎界面
	static void playWelcomeBackMusic();
	//游戏界面
	static void playGameBackMusic();

private:
	//检查音效状态
	static bool checkEffectState();
};