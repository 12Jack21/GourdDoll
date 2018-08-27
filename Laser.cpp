#include "Laser.h"
#include "GameManager.h"
#include "BaseMonster.h"
#include "SecondDollv1.h"

bool Laser::init() {
	if (!Sprite::init()) {
		return false;
	}
	bulletSprite = Sprite::createWithSpriteFrameName(".png");
	addChild(bulletSprite);
	return true;
}

void Laser::shoot()
{
	runAction(Sequence::create(bulletAction,
		CallFuncN::create(CC_CALLBACK_0(Laser::removeBullet, this)),
		NULL));
}

BaseMonster * BaseDoll::checknearestmonster() {
	auto instance = GameManager::getInstance();
	auto monsterVector = instance->monsterVector;

	auto curMinDistance = this->scope;

	BaseMonster * checkedNearestMonster = NULL;
	//for循环找到在DOLL内最近的MONSTER
	for (int i = 0; i < monsterVector.size(); i++) {
		auto monster = monsterVector.at(i);
		double distance = this->getParent()->getPosition().getDistance(monster->monsterSprite->getPosition());
		if (distance < curMinDistance && monster->getAttackByTower()) {
			distance = curMinDistance;
			checkedNearestMonster = monster;
		}
	}
	nearestMonster = checkedNearestMonster;
	return nearestMonster;
}

void Laser::removeLaser() {
	GameManager * instance = GameManager::getInstance();
	auto fireballRect = Rect(this->getPositionX() + this->getParent()->getPositionX() - this->getContentSize().width / 2,
		this->getPositionY() + this->getParent()->getPositionY() - this->getContentSize().height / 2,
		this->bulletSprite->getContentSize().width,
		this->bulletSprite->getContentSize().height);

	
	
	auto monsterVector = instance->monsterVector;
	for (int i = 0; i < monsterVector.size(); i++) {
		auto monster = monsterVector.at(i);
		auto monsterRect = monster->monsterSprite->getBoundingBox();

		if (monster != NULL && monsterRect.intersectsRect(fireballRect) && monster->getAttackByTower()) {
			auto curHp = monster->getCurHp();
			curHp = curHp - this->getMaxForce();
			if (curHp <= 0) {
				curHp = 0;
			}
			monster->setCurHP(curHp);
			monster->getHpBar()->setPercentage((curHp / monster->getMaxHp()) * 100);
			if (curHp == 0) {
				monster->death();
			}
			break;
		}
	}
	this->removeFromParent();
}
void Laser::removeLaser()
{
	auto instance = GameManager::getInstance();

	auto laserPostion = this->getPosition() + this->getParent()->getPosition();

	auto monsterVector = instance->monsterVector;

	for (int j = 0; j < monsterVector.size(); j++)
	{
		auto monster = monsterVector.at(j);
		auto monsterPosition = monster->monsterSprite->getPosition();

		if (monster != NULL && laserPostion.distance(monsterPosition) <= 50 && monster->getAttackByTower())
		{
			SoundManager::playBomb();
			auto currHp = monster->getCurrHp();

			currHp = currHp - this->getMaxForce() + monster->getArmor();

			if (currHp <= 0) {
				currHp = 0;
			}
			monster->setCurrHp(currHp);

			//血量槽设为 空
			monster->getHpBar()->setPercentage((currHp / monster->getMaxHp()) * 100);

			if (currHp == 0) {
				//怪物爆炸动画 （即死亡）
				monster->explosion();
			}
		}
	}
	sprite->runAction(Sequence::create(
		Animate::create(AnimationCache::getInstance()->getAnimation("bomb")),
		CallFuncN::create(CC_CALLBACK_0(Bullet::removeFromParent, this))
		, NULL));
}