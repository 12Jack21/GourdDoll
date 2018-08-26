#pragma once
#include "cocos2d.h"
USING_NS_CC;
class AnimationManager {
public:
	static AnimationManager*getInstance();
	void init(); 
	
	//塔的动画

	//妖精动画
	//蝙蝠精
	void init_bat();
	//蜜蜂精
	void init_bee();
	//蜈蚣精
	void init_wugong();
	//天牛精
	void init_tianniu();
	//蛤蟆精
	void init_frog();
	//蛇精
	void init_snake();
	//蝎子精
	void init_xiezi();

	Animation* createAnimation(const char* prefixName, int start, int end, float delay);
};