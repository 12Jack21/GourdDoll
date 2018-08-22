#pragma once

#include "SystemHeader.h"

USING_NS_CC;

class GameWinLayer : public Layer
{
public:

	virtual bool initGameWinLayer(int star, int gem);
	static GameWinLayer* createGameWinLayer(int star, int gem);
	//���	���¿�ʼ ��ť
	void OnRestartTouch(Ref* pSpender);
	//��� ���� ��ť
	void OnContinueTouch(Ref* pSpender);

	int level;
	//int difficult;
	CREATE_FUNC(GameWinLayer);

private:
	Point position;
	Sprite* GameWinLayerSprite;
	//����	�˵���
	MenuItemSprite* ContinueMenuItem;
	//���¿�ʼ	�˵���
	MenuItemSprite* RestartMenuItem;

};