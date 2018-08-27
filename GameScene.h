#pragma once
#include"SystemHeader.h"

USING_NS_CC;
class GameScene :public Scene
{
public:
	virtual bool initGame(int Level);
	static Scene* playGame(int Level);

};