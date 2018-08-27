#pragma once
#include"SystemHeader.h"

class SoundManager
{
public:
	static void playClickEffect();
	//���������Ĳ���
	static void playIncomingWave();
	static void playNextWaveReady();

	//��Ч
	static void playDollMenu();
	static void playWinStars();
	static void playGameFail();

	//��«��
	static void playDollFoster();
	static void playDollUpdate();
	static void playDollSell();

	//����ʯͷ�ҵ���Ч
	static void playFirsetDollAttack();
	//���޼��ⷢ����Ч
	static void playSecondDollAttack();


	//���֣�boss)
	static void playEffectLaugh();
	static void playEffectMove();
	static void playEffectDeath();

	//����
	//�����ͷ�
	static void playSixthDoll();
	//���ɽ�ͷ�
	static void playKingkong();

	//�ؿ�����
	static void playGameWin();



public:
	//��ӭ����
	static void playWelcomeBackMusic();
	//��Ϸ����
	static void playGameBackMusic();

private:
	//�����Ч״̬
	static bool checkEffectState();
};