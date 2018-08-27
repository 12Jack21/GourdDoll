#include"MonsterInfoLayer.h"

MonsterInfoLayer* MonsterInfoLayer::createMonsterInfo(BaseMonster* monster)
{
	MonsterInfoLayer* monsterInfo = new MonsterInfoLayer();
	if (monsterInfo && monsterInfo->init(monster))
	{
		monsterInfo->autorelease();
		return monsterInfo;
	}
	CC_SAFE_DELETE(monsterInfo);
	return false;
}

bool MonsterInfoLayer::init(BaseMonster* monster)
{
	if (!Sprite::init())
	{
		return false;
	}
	info_bg = Sprite::createWithSpriteFrameName("");
	addChild(info_bg);
	baseMonster = monster;
	setMonsterInfo();

	//不停调用计时器 更新怪物血量值
	schedule(MonsterInfoLayer::updateHp, this);
	return true;
}