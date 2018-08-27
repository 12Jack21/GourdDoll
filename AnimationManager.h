#pragma once

#include "SystemHeader.h"
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

	//葫芦娃
	void init_FirstDoll();
	void init_SecondDoll();
	void init_ThirdDoll();
	void init_FourthDoll();
	void init_FifthDoll();
	void init_SixthDoll();
	void init_SeventhDoll();
	void init_others();
	void init_Grandpa();
	Animation* createAnimation(const char* prefixName, int start, int end, float delay);
private:
	static AnimationManager * instance;
};
