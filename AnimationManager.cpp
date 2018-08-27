#include "AnimationManager.h"

AnimationManager* AnimationManager::instance;

AnimationManager* AnimationManager::getInstance()
{
	if (instance == NULL)
		instance = new AnimationManager();
	return instance;
}

void AnimationManager::init() {
	init_bat();
	//蜜蜂精
	init_bee();
	//蜈蚣精
	init_wugong();
	//天牛精
	init_tianniu();
	//蛤蟆精
	init_frog();
	//蛇精
	init_snake();
	//蝎子精
	init_xiezi();

	init_FirstDoll();
	init_SecondDoll();
	init_ThirdDoll();
	init_FourthDoll();
	init_FifthDoll();
	init_SixthDoll();
	init_SeventhDoll();
	init_others();
}

Animation* AnimationManager::createAnimation(const char* prefixName, int start, int end, float delay)
{
	Vector<SpriteFrame*> animFrames;

	for (int i = start; i <= end; i++)
	{
		auto frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(String::createWithFormat(prefixName, i)->getCString());
		if (frame != nullptr)
			animFrames.pushBack(frame);
	}
	return Animation::createWithSpriteFrames(animFrames, delay);
}

void AnimationManager::init_bat() {
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("batwalk.plist");
	AnimationCache::getInstance()->addAnimation(createAnimation("batwalk%d.png", 1, 6, 0.15f), "batwalk");
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("batdeath.plist");
	AnimationCache::getInstance()->addAnimation(createAnimation("batdeath%d.png", 1, 4, 0.15f), "batdeath");
	//蝙蝠攻击
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("batattack.plist");
	AnimationCache::getInstance()->addAnimation(createAnimation("batattack%d.png", 1, 4, 0.15f), "batattack");
}

void AnimationManager::init_bee() {
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("bee.plist");
	AnimationCache::getInstance()->addAnimation(createAnimation("beewalk%d.png", 1, 4, 0.15f), "beewalk");
	AnimationCache::getInstance()->addAnimation(createAnimation("beedeath%d.png", 1, 6, 0.15f), "beedeath");
	//蜜蜂攻击
	AnimationCache::getInstance()->addAnimation(createAnimation("beeattack%d.png", 1, 5, 0.2f), "beeattack");
}

void AnimationManager::init_frog() {
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("frogwalk.plist");
	AnimationCache::getInstance()->addAnimation(createAnimation("frogwalk%d.png", 1, 5, 0.15f), "frogwalk");
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("frogdeath.plist");
	AnimationCache::getInstance()->addAnimation(createAnimation("frogdeath%d.png", 1, 4, 0.15f), "frogdeath");
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("frogattack.plist");
	AnimationCache::getInstance()->addAnimation(createAnimation("frogattack%d.png", 1, 4, 0.15f), "frogattack");
}

void AnimationManager::init_wugong() {
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("wugongwalk.plist");
	AnimationCache::getInstance()->addAnimation(createAnimation("wugongwalk%d.png", 1, 5, 0.15f), "wugongwalk");
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("wugongdeath.plist");
	AnimationCache::getInstance()->addAnimation(createAnimation("wugongdeath%d.png", 1, 4, 0.15f), "wugongdeath");
	//蜈蚣攻击
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("wugongattack.plist");
	AnimationCache::getInstance()->addAnimation(createAnimation("wugongattack%d.png", 1, 4, 0.15f), "wugongattack");
}

void AnimationManager::init_tianniu() {
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("tianniu.plist");
	AnimationCache::getInstance()->addAnimation(createAnimation("tianniuwalk%d.png", 1, 4, 0.15f), "tianniuwalk");
	AnimationCache::getInstance()->addAnimation(createAnimation("tianniudeath%d.png", 1, 4, 0.15f), "tianniudeath");
	AnimationCache::getInstance()->addAnimation(createAnimation("tianniuattack%d.png", 1, 5, 0.15f), "tianniuattack");
}

void AnimationManager::init_snake() {
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("snake.plist");
	AnimationCache::getInstance()->addAnimation(createAnimation("snakewalk%d.png", 1, 4, 0.15f), "snakewalk");
	AnimationCache::getInstance()->addAnimation(createAnimation("snakedeath%d.png", 1, 4, 0.15f), "snakedeath");
	//蛇精攻击
	AnimationCache::getInstance()->addAnimation(createAnimation("snakeattack%d.png", 1, 3, 0.15f), "snakeattack");
}

void AnimationManager::init_xiezi() {
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("xiezi.plist");
	AnimationCache::getInstance()->addAnimation(createAnimation("xieziwalk%d.png", 1, 4, 0.15f), "xieziwalk");
	AnimationCache::getInstance()->addAnimation(createAnimation("xiezideath%d.png", 1, 4, 0.15f), "xiezideath");
	//蝎子攻击
	AnimationCache::getInstance()->addAnimation(createAnimation("xieziattack%d.png", 1, 4, 0.15f), "xieziattack");
}

void AnimationManager::init_FirstDoll() {
	/*AnimationCache::getInstance()->addAnimation(createAnimation("mage_lvl1_00%02d.png", 1, 12, 0.04f), "level1_mage_shine");
	AnimationCache::getInstance()->addAnimation(createAnimation("mage_lvl2_00%02d.png", 1, 12, 0.04f), "level2_mage_shine");
	AnimationCache::getInstance()->addAnimation(createAnimation("mage_lvl3_00%02d.png", 1, 12, 0.04f), "level3_mage_shine");*/
	//以上是源码
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("firstdoll.plist");
	AnimationCache::getInstance()->addAnimation(createAnimation("firstdollstand%d.png", 1, 4, 0.15f), "firstdollstand");
	AnimationCache::getInstance()->addAnimation(createAnimation("firstdollattack%d.png", 1, 4, 0.15f), "firsdolltattack");
}

void AnimationManager::init_SecondDoll() {
	//二娃攻击动画
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("seconddoll.plist");
	AnimationCache::getInstance()->addAnimation(createAnimation("seconddollstand%d.png", 1, 4, 0.15f), "seconddollstand");
	AnimationCache::getInstance()->addAnimation(createAnimation("seconddollattack%d.png", 1, 4, 0.15f), "seconddollattack");
}

void AnimationManager::init_ThirdDoll() {
	//三娃受击动画
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("thirddoll.plist");
	AnimationCache::getInstance()->addAnimation(createAnimation("thirddollstand%d.png", 1, 4, 0.15f), "thirddollstand");
	AnimationCache::getInstance()->addAnimation(createAnimation("thirddollattacked%d.png", 1, 4, 0.15f), "thirddollattacked");
}

void AnimationManager::init_FourthDoll() {
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("fourthdoll.plist");
	AnimationCache::getInstance()->addAnimation(createAnimation("fourthdollstand%d.png", 1, 4, 0.15f), "fourthdollstand");
	//蝎子攻击
	AnimationCache::getInstance()->addAnimation(createAnimation("fourthdollattack%d.png", 1, 4, 0.15f), "fourthdollattack");
}

void AnimationManager::init_FifthDoll() {
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("fifthdoll.plist");
	AnimationCache::getInstance()->addAnimation(createAnimation("fifthdollstand%d.png", 1, 4, 0.15f), "fifthdollstand");
	//蝎子攻击
	AnimationCache::getInstance()->addAnimation(createAnimation("fifthdollattack%d.png", 1, 4, 0.15f), "fifthdollattack");
}

void AnimationManager::init_SixthDoll() {
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("sixthdoll.plist");

	AnimationCache::getInstance()->addAnimation(createAnimation("sixthdollstand%d.png", 1, 4, 0.15f), "sixthdollstand");
	//蝎子攻击
	AnimationCache::getInstance()->addAnimation(createAnimation("sixthdollattack%d.png", 1, 4, 0.15f), "sixthdollattack");
}

void AnimationManager::init_SeventhDoll() {
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("seventhdoll.plist");

	AnimationCache::getInstance()->addAnimation(createAnimation("seventhdollstand%d.png", 1, 4, 0.15f), "seventhdollstand");
	//蝎子攻击
	AnimationCache::getInstance()->addAnimation(createAnimation("seventhdollattack%d.png", 1, 4, 0.15f), "seventhdollattack");
}

		//技能动画 以及 其他
void AnimationManager::init_others() {
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile(".plist");
	AnimationCache::getInstance()->addAnimation(createAnimation("fosterdoll.png", 1, 4, 0.15f), "fosterDoll");
	AnimationCache::getInstance()->addAnimation(createAnimation("kingkong.png", 1, 4, 0.15f), "kingkong");
}

void AnimationManager::init_Grandpa() {
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("grandpa.plist");
	AnimationCache::getInstance()->addAnimation(createAnimation("grandpaHurt.png", 1, 4, 0.15f), "GranpaHurt");
}

