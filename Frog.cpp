#include "Frog.h"

USING_NS_CC;
//∏ÚÛ°¿‡
Frog * Frog::createMonster(std::vector<Point> points) {
	auto monster = new Frog();
	if (monster&&monster->init()) {
		monster->setPointsVector(points);
		monster->setMaxHp(20);
		monster->setCurHp(20);
		monster->setGourd(10);
		monster->setForce(15);
		monster->setArmor(0);
		monster->setAttackByDoll(true);
		monster->setRunSpeed(40);
		monster->runNextPoint();
		monster->autorelease();
		return monster;
	}
	CC_SAFE_DELETE(monster);
	return NULL;
}

bool Frog::init()
{
	if (!BaseMonster::init())
	{
		return false;
	}
	setMonsterType(FROG);
	setName("frog");
	monsterSprite = Sprite::createWithSpriteFrameName("frogwalk1.png");
	addChild(monsterSprite);
	createAndSetHpBar();
	blood = Sprite::createWithSpriteFrameName(".png");//—™¡øÃı
	blood->setPosition(Point(monsterSprite->getContentSize().width / 2, monsterSprite->getContentSize().height / 2));
	monsterSprite->addChild(blood);
	blood->setVisible(false);
	lastState = stateNone;
	scheduleUpdate();
	setListener();
	return true;
}