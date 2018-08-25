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
	baseSprite->addChild(hpBgSprite);
	
	hpBar = ProgressTimer::create(Sprite::createWithSpriteFrameName(".png"));
	hpBar->setType(ProgressTimer::Type::BAR);
	hpBar->setPercentage(100);
	hpBar->setMidpoint(Point(0, 0.5f));	
	hpBar->setPosition(Point(hpBgSprite->getContentSize().width/2, hpBgSprite->getContentSize().height / 2));
	hpBar->setBarChangeRate(Point(1,0));
	hpBgSprite->addChild(hpBar);

}
float BaseThirdDoll::caculateTime(Point point) {
	return point.getDistance(this->getPosition()) / 100;
}
void BaseThirdDoll::runToMonster() {
	Point destination;
	if (!checkDirectionForMonster()) {
		destination.x = nearestMonster->monsterSprite->getPositionX() + nearestMonster->monsterSprite->getContentSize().width / 2
			- this->getParent()->getParent()->getPositionX() - this->baseSprite->getContentSize().width / 2;
		destination.y = nearestMonster->monsterSprite->getPositionY() - this->getParent()->getParent()->getPositionY()
			- this->baseSprite->getContentSize().height / 4;
	}
	else
	{
		destination.x = nearestMonster->monsterSprite->getPositionX() - nearestMonster->monsterSprite->getContentSize().width / 2
			- this->getParent()->getParent()->getPositionX() + this->baseSprite->getContentSize().width / 2;
		destination.y = nearestMonster->monsterSprite->getPositionY() - this->getParent()->getParent()->getPositionY()
			- this->baseSprite->getContentSize().height / 4;
	}
	setState(ThirdDollStateNone);
	//动作待定
	runAction(Sequence::create(MoveTo::create(caculateTime(destination), destination),NULL));
	/*schedule(schedule_selector(BaseThirdDoll::attackMonster), 1.0f, -1, caculateTime(destination));*/

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
		runAction(Sequence::create(MoveTo::create(caculateTime(point), point),
			CallFuncN::create(CC_CALLBACK_0(BaseThirdDoll::setState, this, ThirdDollStateSearch)),
			NULL));
		schedule(schedule_selector(BaseThirdDoll::SearchingMonster), 1.0f, -1, caculateTime(point));
	}
}
void BaseThirdDoll::SearchingMonster(float dt) {
	setState(ThirdDollStateSearch);
	baseSprite->setFlippedX(!(baseSprite->isFlippedX()));
	checkDirectionForMonster();
	if (nearestMonster != NULL && nearestMonster->getCurHp() > 0) {
		setState(ThirdDollStateWalk);
	}
}

void BaseThirdDoll::checkNearestMonster() {
	auto instance = GameManager::getInstance();
	auto monsterVector = instance->monsterVector;
	nearestMonster = NULL;

	for (int i = 0; i < monsterVector.size(); i++) {
		auto monster = monsterVector.at(i);
		double distance = (this->getParent()->getParent()->getPosition() + this->getPosition()).getDistance(monster->monsterSprite->getPosition());

		if (monster->getAttackBySoldier() && distance < 50 && (!monster->getIsAttacking())) {
			nearestMonster = monster;
			nearestMonster->stopWalking();
			nearestMonster->setIsAttacking(true);
			break;
		}
	}
}
bool BaseThirdDoll::checkDirectionForMonster() {
	if ((nearestMonster->monsterSprite->getPositionX() - (this->getParent()->getParent()->getPositionX() + this->getPositionX())) > 0) {
		baseSprite->setFlippedX(false);
	}
	else
	{
		baseSprite->setFlippedX(true);
	}
}

void BaseThirdDoll::stopThirdDollAnimation() {
	//动作数待定
	for (int i = 1; i <= 8; i++) {
		baseSprite->stopActionByTag(i);
	}
}