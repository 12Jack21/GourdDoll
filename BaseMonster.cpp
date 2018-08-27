#include "BaseMonster.h"
#include "GameManager.h"
#include "BaseLevel.h"

USING_NS_CC;

BaseMonster::BaseMonster()
	:monsterSprite(NULL),
	pointCounter(0),
	runSpeed(0),
	maxHp(0),
	curHp(0),
	armor(0),
	hpPercentage(100),
	hpBar(NULL),
	lastState(stateNone),
	attackByDoll(true),
	isAttacking(false),
	isSlowed(false),
	gourd(0)
{}

BaseMonster::~BaseMonster()
{}

bool BaseMonster::init() {
	if (!Sprite::init()) {
		return false;
	}
	return true;
}

void BaseMonster::setListener()
{
	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(BaseMonster::onTouchBegan, this);
	listener->onTouchEnded = CC_CALLBACK_2(BaseMonster::onTouchEnded, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, monsterSprite);
}

void BaseMonster::createAndSetHpBar() {
	hpBgSprite = Sprite::createWithSpriteFrameName(".png");//Ѫ���۱���ͼƬ ��Ѫ
	hpBgSprite->setPosition(Point(monsterSprite->getContentSize().width / 2, monsterSprite->getContentSize().height));
	monsterSprite->addChild(hpBgSprite);

	hpBar = ProgressTimer::create(Sprite::createWithSpriteFrameName(".png"));//Ѫ����ͼƬ ��Ѫ
	hpBar->setType(ProgressTimer::Type::BAR);
	hpBar->setMidpoint(Point(0, 0.5f));
	hpBar->setBarChangeRate(Point(1, 0));
	hpBar->setPercentage(hpPercentage);
	hpBar->setPosition(Point(hpBgSprite->getContentSize().width / 2, hpBgSprite->getContentSize().height / 2));
	hpBgSprite->addChild(hpBar);
}

//���˶�����

Point BaseMonster::currPoint()
{
	return pointsVector.at(pointCounter);
}

Point BaseMonster::getNextPoint()
{
	auto temp = pointCounter + 5;
	auto maxCount = int(pointsVector.size());
	if (temp < maxCount) {
		auto node = this->pointsVector.at(temp);
		return node;
	}
	return currPoint();
}

Point BaseMonster::nextPoint()
{
	auto maxCount = int(pointsVector.size());
	pointCounter++;
	if (pointCounter < maxCount) {
		auto node = this->pointsVector.at(pointCounter);
		return node;
	}
	else {
		pointCounter = maxCount - 1;
	}
	return currPoint();
}

//��Ҫ�о�
void BaseMonster::setMonsterZorder(int yOrder)
{
	int hunder = (yOrder / 100);
	switch (hunder)
	{
	case(0):
		this->setLocalZOrder(10);
		break;
	case(1):
		this->setLocalZOrder(9);
		break;
	case(2):
		this->setLocalZOrder(8);
		break;
	case(3):
		this->setLocalZOrder(7);
		break;
	case(4):
		this->setLocalZOrder(6);
		break;
	case(5):
		this->setLocalZOrder(5);
		break;
	case(6):
		this->setLocalZOrder(4);
		break;
	case(7):
		this->setLocalZOrder(3);
		break;
	case(8):
		this->setLocalZOrder(2);
		break;
	case(9):
		this->setLocalZOrder(1);
		break;
	case(10):
		this->setLocalZOrder(0);
		break;
	default:

		break;
	}
}

void BaseMonster::runNextPoint()
{
	auto tempCurrPoint = currPoint();

	monsterSprite->setPosition(tempCurrPoint);

	tempNextPoint = nextPoint();
	setMonsterZorder(tempNextPoint.y);
	if (fabs(tempNextPoint.y - tempCurrPoint.y)>5 && tempNextPoint.y > tempCurrPoint.y)//����������
	{
		setState(stateWalkUp);
	}
	else if (fabs(tempNextPoint.y - tempCurrPoint.y)>5 && tempNextPoint.y <= tempCurrPoint.y)//����������
	{
		setState(stateWalkDown);
	}
	else if (tempNextPoint.x >= tempCurrPoint.x)//����������
	{
		setState(stateWalkRight);
	}
	else if (tempNextPoint.x < tempCurrPoint.x)//����������
	{
		setState(stateWalkLeft);
	}
	if (tempNextPoint != tempCurrPoint)
	{
		//�ƶ����¸�������ʱ��
		auto duration = tempCurrPoint.getDistance(tempNextPoint) / getRunSpeed();

		monsterSprite->runAction(Sequence::create(MoveTo::create(duration, tempNextPoint)
			, CallFuncN::create(CC_CALLBACK_0(BaseMonster::runNextPoint, this))
			, NULL));
	}
	else
	{
		//�ߵ��յ�
		GameManager::getInstance()->LIFE--;
		GameManager::getInstance()->monsterVector.eraseObject(this);
		unscheduleAllCallbacks();
		setCurHp(0);
		//removeFromParent();
	}
}

void BaseMonster::update(float dt)
{
	//��״̬����
	if(lastState!=getState()){
		//����״̬�ж�
		switch (getState())
		{
		case(stateWalkRight):{
			lastState = stateWalkRight;
			//ֹ֮ͣǰ����
			stopMonsterAnimation();
			monsterSprite->setFlippedX(false);
			auto action = RepeatForever::create(Animate::create(AnimationCache::getInstance()->getAnimation(getName()+"walk")));
			action->setTag(stateWalkRight);
			monsterSprite->runAction(action);}
			break;
		case(stateWalkLeft):{
			lastState = stateWalkLeft;
			stopMonsterAnimation();
			monsterSprite->setFlippedX(true);
			auto action = RepeatForever::create(Animate::create(AnimationCache::getInstance()->getAnimation(getName()+"walk")));
			action->setTag(stateWalkLeft);
			monsterSprite->runAction(action);}
			break;
		case(stateWalkUp):{
			lastState = stateWalkUp;
			stopMonsterAnimation();
			monsterSprite->setFlippedX(false);
			auto action = RepeatForever::create(Animate::create(AnimationCache::getInstance()->getAnimation(getName()+"walk")));
			action->setTag(stateWalkUp);
			monsterSprite->runAction(action);}
			break;
		case(stateWalkDown):{
			lastState = stateWalkDown;
			stopMonsterAnimation();
			monsterSprite->setFlippedX(false);
			auto action = RepeatForever::create(Animate::create(AnimationCache::getInstance()->getAnimation(getName()+"walk")));
			action->setTag(stateWalkDown);
			monsterSprite->runAction(action);}
			break;
		case(stateAttackRight):{
			//Ĭ�����ұ߹���
			lastState = stateAttackRight;
			stopMonsterAnimation();
			monsterSprite->setFlippedX(false);
			auto action = RepeatForever::create(Animate::create(AnimationCache::getInstance()->getAnimation(getName()+"attack")));
			action->setTag(stateAttackRight);
			monsterSprite->runAction(action);}
			break;
		case(stateAttackLeft):{
			lastState = stateAttackLeft;
			stopMonsterAnimation();
			monsterSprite->setFlippedX(true);
			auto action = RepeatForever::create(Animate::create(AnimationCache::getInstance()->getAnimation(getName()+"attack")));
			action->setTag(stateAttackLeft);
			monsterSprite->runAction(action);}
			break;
		case(stateNone):{
			lastState = stateNone;}
			break;
		case(stateDeath):{
			lastState = stateDeath;}
			break;
		}

	}
}

//��Ҫ�о�
void BaseMonster::stopMonsterAnimation()
{
	for (int i = 1; i <= 6; i++)
	{
		monsterSprite->stopActionByTag(i);
	}
}

void BaseMonster::death()
{
	if (GameManager::getInstance()->monsterVector.contains(this))
		GameManager::getInstance()->monsterVector.eraseObject(this);
	if (getState() != stateDeath) {
		setCurHp(0);
		setState(stateDeath);
		hpBgSprite->setVisible(false);
		monsterSprite->stopAllActions();
		unscheduleUpdate();

		GameManager::getInstance()->GOURD = GameManager::getInstance()->GOURD+ getGourd();
		//������������
		monsterSprite->runAction(Animate::create(AnimationCache::getInstance()->getAnimation(getName() + "death")));
	}
}
void BaseMonster::stopWalking()
{
	tempState = lastState;
	monsterSprite->stopAllActions();
}

void BaseMonster::restartWalking() {
	lastState = stateNone;
	monsterSprite->stopAllActions();
	setState(tempState);
	auto tempCurrPoint = monsterSprite->getPosition();
	auto duration = tempCurrPoint.getDistance(tempNextPoint) / getRunSpeed();
	monsterSprite->runAction(Sequence::create(MoveTo::create(duration, tempNextPoint)
		, CallFuncN::create(CC_CALLBACK_0(BaseMonster::runNextPoint, this))
		, NULL));
}

void BaseMonster::slowRunSpeed(float dt, float dis)
{
	if (!isSlowed) {
		isSlowed = true;
		auto temp = this->getRunSpeed();
		//disΪ���ٵ��ٶ�
		this->setRunSpeed(temp - dis);
		runAction(Sequence::create(
			DelayTime::create(dt),
			CallFuncN::create(CC_CALLBACK_0(BaseMonster::setRunSpeed, this, temp)),
			CallFuncN::create(CC_CALLBACK_0(BaseMonster::setIsSlowed, this, false)),
			NULL));
	}
}

//?
bool BaseMonster::onTouchBegan(Touch* touch, Event* event)
{
	auto target = static_cast<Sprite*>(event->getCurrentTarget());

	Point locationInNode = target->convertTouchToNodeSpace(touch);

	Size size = target->getContentSize();
	Rect rect = Rect(0, 0, size.width, size.height);
	if (rect.containsPoint(locationInNode) && this->isVisible()) {

		return true;
	}
	return false;
}

void BaseMonster::onTouchEnded(Touch* touch, Event* event)
{
	static_cast<BaseLevel*>(this->getParent())->playState->showMonsterInfo(this);
}