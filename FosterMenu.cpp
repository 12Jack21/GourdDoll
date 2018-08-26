#include "FosterMenu.h"
#include "SimpleArrowTowerlvl1.h"
#include "SimpleArtilleryTowerlvl1.h"
#include "SimpleMageTowerlvl1.h"
#include "BaseBarracksTower.h"
#include "Terrain.h"
#include "GameManager.h"
#include "BaseLevel.h"

USING_NS_CC;


bool FosterMenu::init()
{
	if (!Sprite::init())
	{
		return false;
	}
	circle = Circle::create();
	addChild(circle);
	circle->setVisible(false);

	//菜单边框
	borderSprite = Sprite::createWithSpriteFrameName("gui_ring.png");
	borderSprite->setPosition(Point(0, 0));
	borderSprite->setScale(0.5f);
	addChild(borderSprite);

	isBuilt = false;
	return true;
}

void FosterMenu::addTower(int type)
{
	static_cast<BaseLevel*>(this->getParent()->getParent())->playState->removeDollInfo();

	//根据类型创建 娃娃
	switch (type)
	{
	 break;
	case(1): {
		auto firstDoll =  ::create();
		firstDoll->setPosition(Point(0, 20));
		firstDoll->setTag(terrain->getTag());
		firstDoll->setMyTerrain(terrain);
		terrain->addChild(firstDoll);
		GameManager::getInstance()->GOURD = GameManager::getInstance()->GOURD - firstDoll->getFosterGourd();
	}
			 break;
	case(2): {
		auto secondDollDoll = ::create();
		secondDollDoll->setPosition(Point(0, 20));
		secondDollDoll->setTag(terrain->getTag());
		secondDollDoll->setMyTerrain(terrain);
		terrain->addChild(secondDollDoll);
		GameManager::getInstance()->GOURD = GameManager::getInstance()->GOURD - secondDollDoll->getFosterGourd();
	}
			 break;	
	case(3): {
		auto ThirdDollDoll = ::create();
		ThirdDollDoll->setPosition(Point(0, 20));
		ThirdDollDoll->setTag(terrain->getTag());
		ThirdDollDoll->setMyTerrain(terrain);
		terrain->addChild(ThirdDollDoll);
		ThirdDollDoll->buildingAnimation();
		GameManager::getInstance()->GOURD = GameManager::getInstance()->GOURD - ThirdDollDoll->getFosterGourd();
	}
		
	case(4):
		auto mageDoll = SimpleMageDolllvl1::create();
		mageDoll->setPosition(Point(0, 20));
		mageDoll->setTag(terrain->getTag());
		mageDoll->setMyTerrain(terrain);
		terrain->addChild(mageDoll);
		GameManager::getInstance()->GOURD = GameManager::getInstance()->GOURD - mageDoll->getFosterGourd();
		break;
	}
	SoundManager::playDollFostering();
	isBuilt = true;
	terrain->terrain->setVisible(false);
	this->setVisible(false);
}

//菜单边框 动画实现
void FosterMenu::inAnimation()
{
	SoundManager::playDollMenu();
	borderSprite->runAction(Sequence::create(ScaleTo::create(0.1f, 1.0f, 1.0f),
		CallFuncN::create(CC_CALLBACK_0(FosterMenu::addIcons, this)),
		NULL));
}

void FosterMenu::addIcons()
{
	firstDollIcon = BaseFosterIcon::createIcon(1, 70);
	firstDollIcon->setGourd(70);
	firstDollIcon->setPosition(Point(-(borderSprite->getContentSize().width / 4 + 20), borderSprite->getContentSize().height / 4 + 30));
	addChild(firstDollIcon);

	secondDollIcon = BaseFosterIcon::createIcon(4, 120);
	secondDollIcon->setPosition(Point(borderSprite->getContentSize().width / 4 + 20, -(borderSprite->getContentSize().height / 4 + 30)));
	addChild(secondDollIcon);

	thirdDollIcon = BaseFosterIcon::createIcon(2, 100);
	thirdDollIcon->setPosition(Point(borderSprite->getContentSize().width / 4 + 20, borderSprite->getContentSize().height / 4 + 30));
	addChild(thirdDollIcon);

	fourthDollIcon = BaseFosterIcon::createIcon(3, 100);
	fourthDollIcon->setPosition(Point(-(borderSprite->getContentSize().width / 4 + 20), -(borderSprite->getContentSize().height / 4 + 30)));
	addChild(fourthDollIcon);

	//监听触摸
	auto touchListener = EventListenerTouchOneByOne::create();
	touchListener->setSwallowTouches(true);
	touchListener->onTouchBegan = CC_CALLBACK_2(FosterMenu::onTouchBegan, this);
	touchListener->onTouchEnded = CC_CALLBACK_2(FosterMenu::onTouchEnded, this);

	_eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, firstDollIcon);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener->clone(), secondDollIcon);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener->clone(), thirdDollIcon);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener->clone(), fourthDollIcon);
}

bool FosterMenu::onTouchBegan(Touch* touch, Event* event)
{
	auto target = static_cast<BaseFosterIcon*>(event->getCurrentTarget());
	Point locationInNode = target->convertTouchToNodeSpace(touch);
	Size size = target->baseIcon->getContentSize();
	Rect rect = Rect(0 - size.width / 2, 0 - size.height / 2, size.width, size.height);

	if (rect.containsPoint(locationInNode))
	{
		if (target->getIsSelected())
		{
			//如果已经选中（第二次按下）
			if (target->getIsAble())
			{
				//如果葫芦够用
				addTower(target->getType());
			}
		}
		else 
		{
			//第一次按下
			firstDollIcon->setNotSelected();
			secondDollIcon->setNotSelected();
			thirdDollIcon->setNotSelected();
			fourthDollIcon->setNotSelected();
			//设置为选中状态
			target->setSelected();

		}
		return true;
	}
	return false;
}

void FosterMenu::onTouchEnded(Touch* touch, Event* event)
{
	if (isBuilt)
	{
		removeFromParent();
	}
}