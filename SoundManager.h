#pragma once
#include"SystemHeader.h"

class SoundManager
{
public:
	static void playClickEffect();
	//即将到来的波数
	static void playIncomingWave();
	static void playNextWaveReady();

	//游戏胜利和失败
	static void playGameWin();
	static void playGameFail();

	/////////////////////////////葫芦娃
	static void playDollFoster();
	static void playDollUpdate();
	static void playDollSell();

	//大娃石头砸地音效
	static void playFirsetDollAttack();
	//二娃激光发射音效
	static void playSecondDollAttack();
	//三娃被攻击音效
	static void playThirdDollAttacked();
	//四娃攻击特效（喷火）
	static void playFourthDollAttack();
	//五娃攻击特效
	static void playFifthDollAttack();
	//七娃攻击特效
	static void playSeventhDollAttack();
	/////////////////////////////葫芦娃

	//妖怪(改过函数名字）
	static void playMonsterLaugh();
	static void playMonsterMove();
	static void playMonsterDeath();

	//爷爷受伤
	static void playGrandpaHurt();
	static void playGrandpaDeath();

	//技能
	//六娃释放
	static void playSixthDoll();
	//金刚山释放
	static void playKingkong();

public:
	//欢迎界面，关于界面，选关界面
	static void playWelcomeBackMusic();
	//游戏界面
	static void playGameBackMusic();

private:
	//检查音效状态
	static bool checkEffectState();
};