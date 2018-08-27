#include"SoundManager.h"

USING_NS_CC;
using namespace CocosDenshion;

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

void SoundManager::playEffectLaugh()
{
	if (checkEffectState())
		SimpleAudioEngine::getInstance()->playEffect("sound/boss_efreeti_evillaugh.wav");
}

void SoundManager::playWinStars()
{
	if (checkEffectState())
		SimpleAudioEngine::getInstance()->playEffect("sound/Sound_WinStars.wav");
}

void SoundManager::playEffectDeath()
{
	if (checkEffectState())
		SimpleAudioEngine::getInstance()->playEffect("sound/boss_efreeti_death.wav");
}

void SoundManager::playClickEffect()
{
	if (checkEffectState())
		SimpleAudioEngine::getInstance()->playEffect("sound/Sound_GUIButtonCommon.wav");
}

void SoundManager::playWelcomeBackMusic()
{
	SimpleAudioEngine::getInstance()->playBackgroundMusic("sound/savage_music_theme.wav");
	if (UserDefault::getInstance()->getIntegerForKey("backmusic", 1) == 0)
		SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

void SoundManager::playNextWaveReady()
{
	if (checkEffectState())
		SimpleAudioEngine::getInstance()->playEffect("sound/Sound_NextWaveReady.wav");
}

void SoundManager::playIncomingWave()
{
	if (checkEffectState())
		SimpleAudioEngine::getInstance()->playEffect("sound/Sound_WaveIncoming.wav");
}

void SoundManager::playDollUpdate()
{
	if (checkEffectState())
		SimpleAudioEngine::getInstance()->playEffect("sound/Sound_DollUpgrade.wav");
}

void SoundManager::playDollSell()
{
	if (checkEffectState())
		SimpleAudioEngine::getInstance()->playEffect("sound/Sound_DollSell.wav");
}

void SoundManager::playDollFoster()
{
	if (checkEffectState())
		SimpleAudioEngine::getInstance()->playEffect("sound/Sound_DollBuilding.wav");
}

void SoundManager::playDollMenu()
{
	if (checkEffectState())
		SimpleAudioEngine::getInstance()->playEffect("sound/Sound_GUIOpenDollMenu.wav");
}

void SoundManager::playArrowShoot1()
{
	if (checkEffectState())
		SimpleAudioEngine::getInstance()->playEffect("sound/Sound_ArrowHit2.wav");
}

void SoundManager::playArrowShoot2()
{
	if (checkEffectState())
		SimpleAudioEngine::getInstance()->playEffect("sound/Sound_ArrowHit3.wav");
}

void SoundManager::playArcherReady()
{
	if (checkEffectState())
		SimpleAudioEngine::getInstance()->playEffect("sound/Archer_Ready.wav");
}

void SoundManager::playArcher2Ready()
{
	if (checkEffectState())
		SimpleAudioEngine::getInstance()->playEffect("sound/Archer_Taunt1.wav");
}

void SoundManager::playArcher3Ready()
{
	if (checkEffectState())
		SimpleAudioEngine::getInstance()->playEffect("sound/Archer_Taunt2.wav");
}

void SoundManager::playCrossbowReady()
{
	if (checkEffectState())
		SimpleAudioEngine::getInstance()->playEffect("sound/crossbow_taunt_ready.wav");
}

void SoundManager::playCrossbowMultishot()
{
	if (checkEffectState())
		SimpleAudioEngine::getInstance()->playEffect("sound/crossbow_multishot.wav");
}

void SoundManager::playCrossbowEagle()
{
	if (checkEffectState())
		SimpleAudioEngine::getInstance()->playEffect("sound/crossbow_eagle.wav");
}

void SoundManager::playArtilleryReady()
{
	if (checkEffectState())
		SimpleAudioEngine::getInstance()->playEffect("sound/Artillery_Ready.wav");
}

void SoundManager::playArtillery2Ready()
{
	if (checkEffectState())
		SimpleAudioEngine::getInstance()->playEffect("sound/Artillery_Taunt1.wav");
}

void SoundManager::playArtillery3Ready()
{
	if (checkEffectState())
		SimpleAudioEngine::getInstance()->playEffect("sound/Artillery_Taunt2.wav");
}

void SoundManager::playArchmageReady()
{
	if (checkEffectState())
		SimpleAudioEngine::getInstance()->playEffect("sound/archmage_taunt_ready.wav");
}

void SoundManager::playArchmageShot()
{
	if (checkEffectState())
		SimpleAudioEngine::getInstance()->playEffect("sound/archmage_attack.wav");
}

void SoundManager::playArchmageTwister()
{
	if (checkEffectState())
		SimpleAudioEngine::getInstance()->playEffect("sound/archmage_twister.wav");
}

void SoundManager::playArchmagePrecharge()
{
	if (checkEffectState())
		SimpleAudioEngine::getInstance()->playEffect("sound/archmage_precharge.wav");
}

void SoundManager::playMageDollReady()
{
	if (checkEffectState())
		SimpleAudioEngine::getInstance()->playEffect("sound/Mage_Ready.wav");
}

void SoundManager::playMageDoll2Ready()
{
	if (checkEffectState())
		SimpleAudioEngine::getInstance()->playEffect("sound/Mage_Taunt1.wav");
}

void SoundManager::playMageDoll3Ready()
{
	if (checkEffectState())
		SimpleAudioEngine::getInstance()->playEffect("sound/Mage_Taunt2.wav");
}

void SoundManager::playMageDollShot()
{
	if (checkEffectState())
		SimpleAudioEngine::getInstance()->playEffect("sound/Sound_MageShot.wav");
}

void SoundManager::playDKReady()
{
	if (checkEffectState())
		SimpleAudioEngine::getInstance()->playEffect("sound/necromancer_taunt_dknight.wav");
}

void SoundManager::playNecShot()
{
	if (checkEffectState())
		SimpleAudioEngine::getInstance()->playEffect("sound/necromancer_attack.wav");
}

void SoundManager::playDKTaunt()
{
	if (checkEffectState())
		SimpleAudioEngine::getInstance()->playEffect("sound/necromancer_deathknight_taunt_2.wav");
}

void SoundManager::playBomb()
{
	if (checkEffectState())
		SimpleAudioEngine::getInstance()->playEffect("sound/Sound_Bomb1.wav");
}

void SoundManager::playFireballHit()
{
	if (checkEffectState())
		SimpleAudioEngine::getInstance()->playEffect("sound/Sound_FireballHit.wav");
}

void SoundManager::playFireballUnleash()
{
	if (checkEffectState())
		SimpleAudioEngine::getInstance()->playEffect("sound/Sound_FireballUnleash.wav");
}

void SoundManager::playQuestCompleted()
{
	if (checkEffectState())
		SimpleAudioEngine::getInstance()->playEffect("sound/Sound_QuestCompleted.wav");
}

void SoundManager::playQuestFailed()
{
	if (checkEffectState())
		SimpleAudioEngine::getInstance()->playEffect("sound/Sound_QuestFailed.wav");
}

void SoundManager::playAssassinMove()
{
	if (checkEffectState())
		SimpleAudioEngine::getInstance()->playEffect("sound/assassin_taunt_ready.wav");
}

void SoundManager::playReinforcement()
{
	if (checkEffectState())
		SimpleAudioEngine::getInstance()->playEffect("sound/Reinforcements_Event2.wav");
}

void SoundManager::playCash()
{
	if (checkEffectState())
		SimpleAudioEngine::getInstance()->playEffect("sound/inapp_cash.wav");
}

void SoundManager::playHearts()
{
	if (checkEffectState())
		SimpleAudioEngine::getInstance()->playEffect("sound/inapp_hearts.wav");
}



