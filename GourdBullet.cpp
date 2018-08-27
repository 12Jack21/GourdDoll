#include "GourdBullet.h"
#include "GameManager.h"
#include "SeventhDollv1.h"

bool GourdBullet::init() {
	if (!Sprite::init()) {
		return false;
	}
	bulletSprite = Sprite::createWithSpriteFrameName(/*文件名*/);
	addChild(bulletSprite);
	return true;
}

void GourdBullet::shoot() {
	runAction(Sequence::create(bulletAction, CallFuncN::create(CC_CALLBACK_0(GourdBullet::removeGourdBullet, this)), NULL));
}

void GourdBullet::removeGourdBullet() {
	GameManager * instance = GameManager::getInstance();
	auto gourdbulletRect = Rect(this->getPositionX() + this->getParent()->getPositionX() - this->getContentSize().width / 2,
		this->getPositionY() + this->getParent()->getPositionY() - this->getContentSize().height / 2,
		this->bulletSprite->getContentSize().width,
		this->bulletSprite->getContentSize().height);
	//使用七娃容器和怪物容器
	auto monsterVector = instance->monsterVector;
	auto seventhDollv1Vector = instance->seventhDollv1Vector;

	for (int i = 0; i < monsterVector.size(); i++) {
		auto monster = monsterVector.at(i);
		auto monsterRect = monster->monsterSprite->getBoundingBox();

		if (monster != NULL && monsterRect.intersectsRect(gourdbulletRect) && monster->getAttackByTower()) {
			auto curHpMonster = monster->getCurHp();
			
			for (int j = 0; j <seventhDollv1Vector.size(); j++) {
				auto seventhDoll = seventhDollv1Vector.at(j);
				auto seventhDollRect = seventhDoll->baseSprite->getBoundingBox();
				//相当于寻找七娃的葫芦子弹中最近的七娃防御塔
				if (seventhDoll != NULL && seventhDollRect.intersectsRect(gourdbulletRect)) {
					auto curHpSeventhDoll = seventhDoll->getCurHp();
					//获取七娃的当前生命值，并减去相应的怪物当前生命值
					curHpSeventhDoll = curHpSeventhDoll - curHpMonster;
					if (curHpSeventhDoll < 0) {
						//如果出现七娃当前生命值小于怪物生命值，先计算它们相差的数值（此时七娃当前生命值为负数，故为+）
						monster->setCurHp(curHpMonster - (curHpMonster + curHpSeventhDoll));
						curHpSeventhDoll = 0;
					}
					seventhDoll->setCurHp(curHpSeventhDoll);
					seventhDoll->getHpBar()->setPercentage((curHpSeventhDoll / seventhDoll->getMaxHp()) * 100);
					if (curHpSeventhDoll == 0) {
						seventhDoll->seventhdollv1Death();
					}
					break;
			     }
		    }
			//直接将0赋给怪物的当前生命值,判断其死亡
			curHpMonster = 0;
			monster->death();
			break;
	}
	this->removeFromParent();
}

