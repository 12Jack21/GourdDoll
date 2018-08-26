#pragma once

#include "cocos2d.h"
#include "Circle.h"
#include "Terrain.h"
#include "BaseFosterIcon.h"

USING_NS_CC;

class FosterMenu : public Sprite
{
public:
	virtual bool init() override;
	CREATE_FUNC(FosterMenu);
	// ���ش����ص�����
	bool onTouchBegan(Touch *touch, Event *event);
	void onTouchEnded(Touch* touch, Event* event);
	CC_SYNTHESIZE(Terrain*, terrain, MyTerrain);
	void inAnimation();
private:
	void addIcons();
	void addTempTower(int type);
	void addTower(int type);

	BaseFosterIcon* firstDollIcon;
	BaseFosterIcon* secondDollIcon;
	BaseFosterIcon* thirdDollIcon;
	BaseFosterIcon* fourthDollIcon;
	BaseFosterIcon* fifthDollIcon;
	BaseFosterIcon* seventhDollIcon;

	//�˵��߿�
	Sprite* borderSprite;
	Circle* circle;

	//Sprite *tempTower;
	
	bool isBuilt;
};
