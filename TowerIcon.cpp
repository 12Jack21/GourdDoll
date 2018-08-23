#include "GameManager.h"
#include "TowerIcon.h"

bool TowerIcon::initIcon() {
	if (!Sprite::init()) {
		return false;
	}
	isSelected = false;
	auto text = String::createWithFormat(/*文件名*/,type)->getCString();
	towerIcon = Sprite::createWithSpriteFrameName(String::createWithFormat(/*文件名*/,type)->getCString());
	addChild(towerIcon);
	gourdIcon = Sprite::createWithSpriteFrameName(/*文件名*/);
	gourdIcon->setPosition(Point(/*位置设置*/));
	addChild(gourdIcon);
	gourdLabel = Label::createWithTTF(String::createWithFormat("%d", gourd)->getCString(),/*字体的选择,大小*/);
	gourdLabel->setPosition(Point(gourdIcon->getContentSize().width/2,gourdIcon->getContentSize().height/2-2));
	gourdLabel->setColor(/*设置字体颜色*/);
	gourdIcon->addChild(gourdLabel);

	okIcon = Sprite::createWithSpriteFrameName(/*文件名*/);
	okIcon->setPosition(Point(towerIcon->getContentSize().width / 2, towerIcon->getContentSize().height / 2));
	towerIcon->addChild(okIcon);
	okIcon->setVisible(false);
	
	setGourd(gourd);
	setType(type);
	this->scheduleUpdate();
	
	return true;
}

void TowerIcon::setNotSelected() {
	isSelected = false;
	okIcon->setVisible(false);
}

void TowerIcon::setNotEnoughGourd() {
	isSelected = false;
	okIcon->setVisible(false);
}

void TowerIcon::update(float dt) {
	if (getGourd() <= GameManager::getInstance()->GOURD) {
		setEnoughGourd();
	}
	else
	{
		setNotEnoughGourd();
	}
}

void TowerIcon::setEnoughGourd() {
	can = true;
	gourdLabel->setColor(/*设置颜色*/);
	okIcon->setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(".png"));
	towerIcon->setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(String::createWithFormat(".png", type)->getCString()));
	gourdIcon->setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(".png"));
}

void TowerIcon::setSelected() {
	can = true;
	okIcon->setVisible(true);
}

void TowerIcon::setUpdateGourd(int Gourd) {
	setGourd(gourd);
	gourdLabel->setString(String::createWithFormat(/*文件名*/,gourd)->getCString());
}

TowerIcon * TowerIcon::createIcon(int type, int gourd) {
	auto baseTowerIcon = new TowerIcon();

	if (baseTowerIcon && baseTowerIcon->initIcon(type, gourd)) {
		baseTowerIcon->autorelease();
		return baseTowerIcon;
	}
	CC_SAFE_DELETE(baseTowerIcon);
	return NULL;
}