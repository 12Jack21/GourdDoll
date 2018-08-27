#include "GameManager.h"
#include "BaseLevel.h"
#include "SeventhDollv2.h"
#include "GourdBullet.h"

bool SeventhDollv2::init() {
	if (!Sprite::init()) {
		return false;
	}
	setDollType(SEVENTHDOLL_2);
	setLevel(2);
	addGourd();
	setScope(180.0f);
	setFosterGourd(120);
	nearestMonster = NULL;
	return true;
}

void SeventhDollv2::createAndSetHpBar() {
	hpBgSprite = Sprite::createWithSpriteFrameName(".png");
	hpBgSprite->setPosition(Point(baseSprite->getContentSize().width / 2, baseSprite->getContentSize().height / 3 * 2));
	baseSprite->addChild(hpBgSprite);

	hpBar = ProgressTimer::create(Sprite::createWithSpriteFrameName(".png"));
	hpBar->setType(ProgressTimer::Type::BAR);
	hpBar->setPercentage(100);
	hpBar->setMidpoint(Point(0, 0.5f));
	hpBar->setPosition(Point(hpBgSprite->getContentSize().width / 2, hpBgSprite->getContentSize().height / 2));
	hpBar->setBarChangeRate(Point(1, 0));
	hpBgSprite->addChild(hpBar);

}

BaseBullet * SeventhDollv2::SeventhDollBullet() {
	auto seventhDollBullet = GourdBullet::create();
	seventhDollBullet->setPosition(Point(40, 45));
	seventhDollBullet->setMaxForce(0);
	this->getParent()->addChild(seventhDollBullet);
	return seventhDollBullet;
}

void SeventhDollv2::death() {
	if (GameManager::getInstance()->seventhDollv1Vector.contains(this))
		GameManager::getInstance()->seventhDollv1Vector.eraseObject(this);
	if (getState() != SevenDollStateDeath) {
		setCurHp(0);
		setState(SevenDollStateDeath);
		hpBgSprite->setVisible(false);
		baseSprite->stopAllActions();
		unscheduleUpdate();
		auto decal_blood = Sprite::createWithSpriteFrameName(".png");
		decal_blood->setPosition(Point(baseSprite->getContentSize().width / 2, -baseSprite->getContentSize().height / 4));
		baseSprite->addChild(decal_blood);

		decal_blood->runAction(Sequence::create(FadeOut::create(1.0f)
			, CallFuncN::create(CC_CALLBACK_0(SeventhDollv1::setVisible, this, false))
			, NULL));
	}
}