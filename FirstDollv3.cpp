#include "FirstDollv3.h"
#include "UpdateMenu.h"
#include "GameManager.h"
#include "BaseLevel.h"
#include "Stone.h"

bool FirstDollv3::init() {
	if (!Sprite::init()) {
		return false;
	}
	setDollType(FIRSTDOLL_3);
	setLv(3);
	addGourd();
	initDoll(3);
	setScope(180.0f);
	setUpdateGourd(230);
	setFosterGourd(500);
	isUpdateMenuShown = false;
	schedule(schedule_selector(FirstDollv3::shoot), 2.0f);
	//����Ч��Ҫ�ɲ�Ҫ
	SoundManager::playDollUpdate();
	return true;
}

BaseBullet* FirstDollv3::FirstDollBullet()
{
	auto firstDollBullet = Stone::create();
	firstDollBullet->setPosition(Point(10, 45));
	firstDollBullet->setMaxForce(50);
	this->getParent()->addChild(firstDollBullet);
	return firstDollBullet;
}

void FirstDollv3::shoot(float dt) {
	auto instance = GameManager::getInstance();
	checkNearestMonster();
	if (nearestMonster != NULL && nearestMonster->getCurHp() > 0) {
		auto curBullet = FirstDollBullet();
		//���޵���Ϸ��ЧSoundManager::

		Point shootVector = nearestMonster->monsterSprite->getPosition() - this->getParent()->getPosition();

		auto position = curBullet->getPosition() - shootVector;
		auto rotation = atan2(position.y, position.x);
		float angle = CC_RADIANS_TO_DEGREES(rotation);
		curBullet->setRotation(180.0f - angle);

		dollBase->runAction(Animate::create(AnimationCache::getInstance()->getAnimation(String::createWithFormat(" ", lv)->getCString())));
		//�������
		auto move = MoveTo::create(0.25f, shootVector);
		auto action = Spawn::create(move, NULL);
		curBullet->setBulletAction(action);
		curBullet->shoot();
		curBullet = NULL;
	}
}