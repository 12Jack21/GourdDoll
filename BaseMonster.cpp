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
	attackBySoldier(true),
	attackByTower(true),
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
	hpBgSprite = Sprite::createWithSpriteFrameName(".png");//—™¡ø≤€±≥æ∞Õº∆¨ ∫Ï—™
	hpBgSprite->setPosition(Point(monsterSprite->getContentSize().width / 2, monsterSprite->getContentSize().height));
	monsterSprite->addChild(hpBgSprite);

	hpBar = ProgressTimer::create(Sprite::createWithSpriteFrameName(".png"));//—™¡ø≤€Õº∆¨ ¬Ã—™
	hpBar->setType(ProgressTimer::Type::BAR);
	hpBar->setMidpoint(Point(0, 0.5f));
	hpBar->setBarChangeRate(Point(1, 0));
	hpBar->setPercentage(hpPercentage);
	hpBar->setPosition(Point(hpBgSprite->getContentSize().width / 2, hpBgSprite->getContentSize().height / 2));
	hpBgSprite->addChild(hpBar);
}

// ‹…À∂Øª≠Œﬁ