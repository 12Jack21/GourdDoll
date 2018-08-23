#include "ThirdDoll.h"
#include "GameManager.h"


bool BaseThirdDoll::init() {
	if (!Sprite::init()) {
		return false;
	}
	nearestMonster = NULL;
	return true;
}

void BaseThirdDoll::createAndSetHpBar() {
	hpBgSprite = Sprite::createWithSpriteFrameName(".png");
	hpBgSprite->setPosition(Point(baseSprite->getContentSize().width / 2, baseSprite->getContentSize().height / 3 * 2));
	BaseDoll->addChild(hpBgSprite);
	
	hpBar = ProgressTimer::create(Sprite::createWithSpriteFrameName(".png"));
	hpBar->setType(ProgressTimer::Type::BAR);
	//保留(hpPercentage?)
	hpBar->setPercentage(100);
	//数据未加
	hpBar->setMidPoint(Point());
	
	hpBar->setPosition(Point(hpBgSprite->getContentSize().width/2, hpBgSprite->getContentSize().height / 2));
	//数据未加
	hpBar->setBarChangeRate(Point());
	hpBgSprite->addChild(hpBar);

}
float BaseThirdDoll::caculateTime(Point point) {
	return point.getDistance(this->getPosition()) / 100;
}
void BaseThirdDoll::runToMonster() {
	Point destination;
	if (!checkDirectionForMonster()) {
		destination.x = nearestMonster->baseSprite->getPositionX() + nearestMonster->baseSprite->getContentSize().width / 2
			- this->getParent()->getParent()->getPositionX() - this->baseSprite->getContentSize().width / 2;
		destination.y = nearestMonster->BaseThirdDoll->getPositionY() - this->getParent()->getParent()->getPositionY()
			- this->baseSprite->getContentSize().height / 4;
	}
	else
	{
		destination.x = nearestMonster->baseSprite->getPositionX() - nearestMonster->baseSprite->getContentSize().width / 2
			- this->getParent()->getParent()->getPositionX() + this->baseSprite->getContentSize().width / 2;
		destination.y = nearestMonster->baseSprite->getPositionY() - this->getParent()->getParent()->getPositionY()
			- this->baseSprite->getContentSize().height / 4;
	}
	setState(ThirdDollStateAttack);
	//动作待定
	runAction(Sequence::create());
	schedule(schedule_selector(BaseThirdDoll::attackMonster), 1.0f, -1, caculateTime(destination));

}

void BaseThirdDoll::runToLocation(Point point) {
	if (getState() != ThirdDollStateDeath) {
		unscheduleAllCallbacks();
		scheduleUpdate();
		stopAllActions();
		if ((point.x - this->getPositionX() )> 0) {
			baseSprite->setFlippedX(false);//向右边移动
		}
		else
		{
			baseSprite->setFlippedX(true);
		}
		setState(ThirdDollStateWalk);
		runAction(Sequence::create(), CallFuncN::create(CC_CALLLBACK_0(BaseThirdDoll::setState, this, ThirdDollStateSearch), NULL));
		schedule(schedule_selector(BaseThirdDoll::ThirdDollStateSearch), 1.0f, -1, caculateTime(point));
	}
}
void BaseThirdDoll::SearchingMonster(float dt) {
	setState(ThirdDollStateSearch);
	baseSprite->setFlippedX(!(baseSprite->isFlippedX()));
	checkDirectionForMonster();
	if (nearestMonster != NULL && nearestMonster->getCurHp() > 0) {
		attack();
	}
}

void BaseThirdDoll::checkNearestMonster() {
	auto instance = GameManager::getInstance();
	auto monsterVector = instance->monsterVector;
	nearestMonster = NULL;

	for (int i = 0; i < monsterVecotr.size(); i++) {
		auto monster = monsterVector.at(i);
		double distance = (this->getParent()->getParent()->getPostion() + this->getPosition()).getDistance(monster->baseSprite->getPosition());

		if (monster->getAttackBySoldier() && distance < 50 && (!monster->getIsAttacking())) {
			nearestMonster = monster;
			nearestMonster->stopWalking();
			nearestMonster->setIsAttacking(true);
			break;
		}
	}
}
bool BaseThirdDoll::checkDirectionForMonster() {
	if ((nearestMonster->baseSprite->getPositionX() - (this->getParent()->getParent()->getPositionX() + this->getPositionX())) > 0) {
		bsaeSprite->setFlippedX(false);
	}
	else
	{
		bsaeSprite->setFlippedX(true);
	}
}

void baseThirdDoll::stopThirdDollAnimation() {
	//动作数待定
	for (int i = 1; i <= 8; i++) {
		baseSprite->stopActionByTag(i);
	}
}