#include "AnimationManager.h"

AnimationManager* AnimationManager::getInstance;

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
	//òùòð¹¥»÷
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("batattack.plist");
	AnimationCache::getInstance()->addAnimation(createAnimation("batattack%d.png", 1, 4, 0.15f), "batattack");
}

void AnimationManager::init_bee() {
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("bee.plist");
	AnimationCache::getInstance()->addAnimation(createAnimation("beewalk%d.png", 1, 4, 0.15f), "beewalk");
	AnimationCache::getInstance()->addAnimation(createAnimation("beedeath%d.png", 1, 6, 0.15f), "beedeath");
	//ÃÛ·ä¹¥»÷
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
	//òÚò¼¹¥»÷
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
	AnimationCache::getInstance()->addAnimation(createAnimation("snakeattack%d.png", 1, 3, 0.15f), "snakeattack");
}

void AnimationManager::init_xiezi() {
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("xiezi.plist");
	AnimationCache::getInstance()->addAnimation(createAnimation("xieziwalk%d.png", 1, 4, 0.15f), "xieziwalk");
	AnimationCache::getInstance()->addAnimation(createAnimation("xiezideath%d.png", 1, 4, 0.15f), "xiezideath");
	//Ð«×Ó¹¥»÷
	AnimationCache::getInstance()->addAnimation(createAnimation("xieziattack%d.png", 1, 4, 0.15f), "xieziattack");
}