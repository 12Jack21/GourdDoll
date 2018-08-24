#pragma once
#ifndef _GOURD_H_
#define _GOURD_H_

#include "cocos2d.h"
USING_NS_CC;

class Gourd:public Sprite
{
public:
	virtual bool init(int type);
	static Gourd * createGourd(int type);
	void showUpdateMenu();
	bool isUpdateMenuShown;
	void hideUpdateMenu();
	Sprite * gourd;
	bool onTouchBegan(cocos2d::Touch *t, cocos2d::Event *e);
	void onTouchEnded(cocos2d::Touch *t, cocos2d::Event *e);
	void Effect();
};



#endif // !_GOURD_H_