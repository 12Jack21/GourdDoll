#include"BaseFosterIcon.h"
#include "BaseFosterIcon.h"
#include "GameManager.h"

bool BaseFosterIcon::initIcon(int type, int gourd)
{
	if (!Sprite::init())
	{
		return false;
	}
	isSelected = false;
	auto baseIconString = String::createWithFormat("main_icons_00%02d.png", type)->getCString();
	baseIcon = Sprite::createWithSpriteFrameName(String::createWithFormat("main_icons_00%02d.png", type)->getCString());
	addChild(baseIcon);

	priceIcon = Sprite::createWithSpriteFrameName("price_tag.png");
	priceIcon->setPosition(Point(0, -baseIcon->getContentSize().height / 2));
	addChild(priceIcon);

	priceLabel = Label::createWithTTF(String::createWithFormat("%d", gourd)->getCString(), "arial.ttf", 20);
	priceLabel->setColor(Color3B(255, 153, 0));
	priceLabel->setPosition(Point(priceIcon->getContentSize().width / 2, priceIcon->getContentSize().height / 2 - 2));
	priceIcon->addChild(priceLabel);

	okIcon = Sprite::createWithSpriteFrameName("main_icons_0019.png");
	okIcon->setPosition(Point(baseIcon->getContentSize().width / 2, baseIcon->getContentSize().height / 2));
	baseIcon->addChild(okIcon);
	okIcon->setVisible(false);

	setGourd(gourd);
	setType(type);
	this->scheduleUpdate();

	return true;
}

void BaseFosterIcon::setUpdateGourd(int gourd)
{
	setGourd(gourd);
	priceLabel->setString(String::createWithFormat("%d", gourd)->getCString());
}

BaseFosterIcon* BaseFosterIcon::createIcon(int type, int gourd)
{
	auto baseFosterIcon = new BaseFosterIcon();

	if (baseFosterIcon && baseFosterIcon->initIcon(type, gourd))
	{
		baseFosterIcon->autorelease();
		return baseFosterIcon;
	}
	CC_SAFE_DELETE(baseFosterIcon);
	return NULL;
}

void BaseFosterIcon::setNotEnoughGourd()
{
	isAble = false;
	priceLabel->setColor(Color3B(102, 102, 102));
	baseIcon->setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(String::createWithFormat("main_icons_disabled_00%02d.png", type)->getCString()));
	priceIcon->setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("price_tag_disabled.png"));
	okIcon->setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("main_icons_disabled_0019.png"));
}

void BaseFosterIcon::setEnoughGourd()
{
	isAble = true;
	priceLabel->setColor(Color3B(255, 153, 0));
	okIcon->setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("main_icons_0019.png"));
	baseIcon->setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(String::createWithFormat("main_icons_00%02d.png", type)->getCString()));
	priceIcon->setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("price_tag.png"));
}

void BaseFosterIcon::setSelected()
{
	isSelected = true;
	okIcon->setVisible(true);
}

void BaseFosterIcon::setNotSelected()
{
	isSelected = false;
	okIcon->setVisible(false);
}

void BaseFosterIcon::update(float dt)
{
	if (getGourd() <= GameManager::getInstance()->GOURD) 
	{
		setEnoughGourd();
	}
	else {
		setNotEnoughGourd();
	}
}