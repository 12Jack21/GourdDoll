#pragma once

#include "SystemHeader.h"

USING_NS_CC;

class GameWinLayer : public Layer
{
public:
	static GameWinLayer* createGameWin(int star);
	virtual bool initGameWinLayer(int star);

	//���	���¿�ʼ ��ť
	void OnRestartTouch(Ref* pSpender);
	//��� ���� ��ť
	void OnContinueTouch(Ref* pSpender);

	int level;
	//int difficult;
	CREATE_FUNC(GameWinLayer);

private:
	Point position;
	Sprite* winSprite;
	//����	�˵���
	MenuItemSprite* ContinueMenuItem;
	//���¿�ʼ	�˵���
	MenuItemSprite* RestartMenuItem;

};