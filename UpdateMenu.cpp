#include "UpdateMenu.h"
#include "GameManager.h"
#include "BaseFosterIcon.h"
#include "BaseLevel.h"

USING_NS_CC;

bool UpdateMenu::init()
{
	if (!Sprite::init())
	{
		return false;
	}
	isBuilt = false;

	borderSprite = Sprite::createWithSpriteFrameName("gui_ring.png");
	borderSprite->setPosition(Point(0, 0));
	borderSprite->setScale(0.5f);
	addChild(borderSprite);

	updateIcon = BaseFosterIcon::createIcon(5, 0);
	updateIcon->setPosition(Point(0, borderSprite->getContentSize().height / 2));
	updateIcon->setVisible(false);
	updateIcon->setTag(1);
	addChild(updateIcon);

	sellIcon = SellIcon::create();
	sellIcon->setPosition(Point(0, -borderSprite->getContentSize().height / 2));
	sellIcon->setVisible(false);
	sellIcon->setTag(2);
	addChild(sellIcon);

	couldUpdate = true;

	//提示其无法继续升级（锁）
	lock = Sprite::createWithSpriteFrameName("main_icons_0014.png");
	lock->setPosition(Point(0, borderSprite->getContentSize().height / 2));
	addChild(lock);
	lock->setVisible(false);
	return true;
}

void UpdateMenu::inAnimation()
{
	SoundManager::playDollMenu();
	borderSprite->runAction(Sequence::create(ScaleTo::create(0.1f, 1.0f, 1.0f),
		CallFuncN::create(CC_CALLBACK_0(UpdateMenu::addIcons, this)),
		NULL));
}

void UpdateMenu::addIcons()
{
	thisLvlCircle = Circle::create();
	nextLvlCircle = Circle::create();

	thisLvlCircle->setScale(doll->getScope() / 160.0f);
	addChild(thisLvlCircle, -1);
	nextLvlCircle->setScale((doll->getScope() + 20) / 160.0f);
	addChild(nextLvlCircle, -1);
	nextLvlCircle->setVisible(false);
	sellIcon->setVisible(true);

	auto touchListener = EventListenerTouchOneByOne::create();
	touchListener->setSwallowTouches(true);
	touchListener->onTouchBegan = CC_CALLBACK_2(UpdateMenu::onTouchBegan, this);
	touchListener->onTouchEnded = CC_CALLBACK_2(UpdateMenu::onTouchEnded, this);

	_eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, sellIcon);
	if (couldUpdate) {
		_eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener->clone(), updateIcon);
		updateIcon->setVisible(true);
		updateIcon->setUpdateGourd(doll->getUpdateGourd());
	}
	else {
		lock->setVisible(true);
	}


}

bool UpdateMenu::onTouchBegan(Touch *touch, Event *event)
{
	auto target = static_cast<BaseFosterIcon*>(event->getCurrentTarget());
	Point locationInNode = target->convertTouchToNodeSpace(touch);
	Size size = target->baseIcon->getContentSize();
	Rect rect = Rect(0 - size.width / 2, 0 - size.height / 2, size.width, size.height);
	if (rect.containsPoint(locationInNode))
	{
		if (target->getIsSelected())//如果已经选中（第二次按下）
		{
			if (target->getIsAble())//如果钱够用
			{
				static_cast<BaseLevel*>(this->getParent()->getParent())->playState->removeDollInfo();
				switch (target->getTag())
				{
				case(1)://升级
					SoundManager::playDollUpdate();
					GameManager::getInstance()->GOURD = GameManager::getInstance()->GOURD - doll->getUpdateGourd();
					doll->updateDoll();
					break;
				case(2)://售出
					SoundManager::playDollSell();
					GameManager::getInstance()->GOURD = GameManager::getInstance()->GOURD + (doll->getFosterGourd() / 2);
					doll->sellDoll();
					break;
				}
				this->setVisible(false);
				isBuilt = true;
			}
		}
		else
		{//第一次按下
			static_cast<BaseLevel*>(this->getParent()->getParent())->playState->removeDollInfo();
			updateIcon->setNotSelected();
			sellIcon->setNotSelected();
			target->setSelected();//设置为选中状态
			switch (target->getTag())
			{
			case(1)://升级
				showDollInfo();
				nextLvlCircle->setVisible(true);
				break;
			case(2)://售出
				nextLvlCircle->setVisible(false);
				break;
			}
		}
		return true;
	}
	return false;
}

void UpdateMenu::showDollInfo()
{
						/////////////////////////增加娃娃类型
	switch (doll->getDollType())
	{
	case(FIRSTDOLL_1):
		static_cast<BaseLevel*>(this->getParent()->getParent())->playState->showDollInfo();
		break;
	case():
		static_cast<BaseLevel*>(this->getParent()->getParent())->playState->showDollInfo();
		break;
	case():
		static_cast<BaseLevel*>(this->getParent()->getParent())->playState->showDollInfo();
		break;
	case():
		static_cast<BaseLevel*>(this->getParent()->getParent())->playState->showDollInfo();
		break;
	case():
		static_cast<BaseLevel*>(this->getParent()->getParent())->playState->showDollInfo();
		break;
	case():
		static_cast<BaseLevel*>(this->getParent()->getParent())->playState->showDollInfo();
		break;
	default:
		break;
	}
}

void UpdateMenu::onTouchEnded(Touch* touch, Event* event)
{
	if (isBuilt)
	{
		removeFromParent();
	}
}
