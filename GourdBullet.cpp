#include "GourdBullet.h"
#include "GameManager.h"
#include "SeventhDollv1.h"

bool GourdBullet::init() {
	if (!Sprite::init()) {
		return false;
	}
	bulletSprite = Sprite::createWithSpriteFrameName(/*�ļ���*/);
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
	//ʹ�����������͹�������
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
				//�൱��Ѱ�����޵ĺ�«�ӵ�����������޷�����
				if (seventhDoll != NULL && seventhDollRect.intersectsRect(gourdbulletRect)) {
					auto curHpSeventhDoll = seventhDoll->getCurHp();
					//��ȡ���޵ĵ�ǰ����ֵ������ȥ��Ӧ�Ĺ��ﵱǰ����ֵ
					curHpSeventhDoll = curHpSeventhDoll - curHpMonster;
					if (curHpSeventhDoll < 0) {
						//����������޵�ǰ����ֵС�ڹ�������ֵ���ȼ�������������ֵ����ʱ���޵�ǰ����ֵΪ��������Ϊ+��
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
			//ֱ�ӽ�0��������ĵ�ǰ����ֵ,�ж�������
			curHpMonster = 0;
			monster->death();
			break;
	}
	this->removeFromParent();
}

