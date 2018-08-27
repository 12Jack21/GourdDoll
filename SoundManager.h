#pragma once
#include"SystemHeader.h"

class SoundManager
{
public:
	static void playClickEffect();
	//���������Ĳ���
	static void playIncomingWave();
	static void playNextWaveReady();

	//��Ϸʤ����ʧ��
	static void playGameWin();
	static void playGameFail();

	/////////////////////////////��«��
	static void playDollFoster();
	static void playDollUpdate();
	static void playDollSell();

	//����ʯͷ�ҵ���Ч
	static void playFirsetDollAttack();
	//���޼��ⷢ����Ч
	static void playSecondDollAttack();
	//���ޱ�������Ч
	static void playThirdDollAttacked();
	//���޹�����Ч�����
	static void playFourthDollAttack();
	//���޹�����Ч
	static void playFifthDollAttack();
	//���޹�����Ч
	static void playSeventhDollAttack();
	/////////////////////////////��«��

	//����(�Ĺ��������֣�
	static void playMonsterLaugh();
	static void playMonsterMove();
	static void playMonsterDeath();

	//үү����
	static void playGrandpaHurt();
	static void playGrandpaDeath();

	//����
	//�����ͷ�
	static void playSixthDoll();
	//���ɽ�ͷ�
	static void playKingkong();

public:
	//��ӭ���棬���ڽ��棬ѡ�ؽ���
	static void playWelcomeBackMusic();
	//��Ϸ����
	static void playGameBackMusic();

private:
	//�����Ч״̬
	static bool checkEffectState();
};