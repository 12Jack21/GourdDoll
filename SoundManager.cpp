#include"SoundManager.h"

USING_NS_CC;

bool SoundManager::checkEffectState()
{
	if (UserDefault::getInstance()->getBoolForKey(EFFECT_KEY))
	{
		return true;
	}
	else
	{
		return false;
	}
	
}

