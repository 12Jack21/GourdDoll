#pragma once
#include"SystemHeader.h"

class SoundManager
{
public:
	static void playClickEffect();
	static void playIncomingWave();
	static void playNextWaveReady();

	//��Ч
	static void playTowerMenu();
	static void playWinStars();

	//��«��
	static void playDollSpawn();
	static void playDollUpdate();
	static void playDollSell();

	//���֣�boss)
	static void playEffectLaugh();
	static void playEffectMove();
	static void playEffectDeath();

	//����
	//����
	static void playSixDoll();
	//���ɽ
	static void playKingkongMount();

	//�ؿ�����
	static void playGameWin();

	static void playGameFaile();

	//����BOSS
	static void playChestdrum();
	static void playChimps_1();
	static void playChimps_2();
	static void playChimps_3();
	static void playMonoDeath();

public:
	//��ӭ����
	static void playWelcomeBackMusic();
	//��Ϸ����
	static void playGameBackMusic();

private:
	//�����Ч״̬
	static bool checkEffectState();
};