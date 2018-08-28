#include"DollInfoLayer.h"

DollInfoLayer* DollInfoLayer::createDollInfo(DollType dollType)
{
	auto dollInfo = new DollInfoLayer();
	if (dollInfo && dollInfo->init(dollType))
	{
		dollInfo->autorelease();
		return dollInfo;
	}
	CC_SAFE_DELETE(dollInfo);
	return nullptr;
}

bool DollInfoLayer::init(DollType dollType)
{
	if (!Sprite::init())
	{
		return false;
	}
	//³õÊ¼»¯±³¾°
	infoBg = Sprite::createWithSpriteFrameName("");
	addChild(infoBg);
	setDollInfo(dollType);
	return true;
}

void DollInfoLayer::setDollInfo(DollType dollType)
{
	auto dollBorder = Sprite::createWithSpriteFrameName("");
	dollBorder->setPosition();
	infoBg->addChild(dollBorder);

	auto dollName = Label::createWithTTF("", "", 20);
	dollName->setPosition();
	infoBg->addChild(dollName);

	auto forceIcon = Sprite::createWithSpriteFrameName("");
	forceIcon->setPosition();
	infoBg->addChild(forceIcon);

	auto forceLabel = Label::createWithTTF("", "", 20);
	forceLabel->setPosition();
	infoBg->addChild(forceLabel);

	auto speedIcon = Sprite::createWithSpriteFrameName("");
	speedIcon->setPosition();
	infoBg->addChild(speedIcon);

	auto speedLabel = Label::createWithTTF("", "", 20);
	speedLabel->setPosition();
	infoBg->addChild(speedLabel);

	auto scopeIcon = Sprite::createWithSpriteFrameName("");
	scopeIcon->setPosition();
	infoBg->addChild(scopeIcon);

	auto scopeLabel = Label::createWithTTF("", "", 20);
	scopeLabel->setPosition();
	infoBg->addChild(scopeLabel);

	Sprite* dollIcon;
	switch (dollType)
	{
	case(FIRSTDOLL_1):
		dollIcon = Sprite::createWithSpriteFrameName("portraits_towers_0001.png");
		dollName->setString("ARCHER TOWER");
		forceLabel->setString("8");
		speedLabel->setString("AVERAGE");
		scopeLabel->setString("SHORT");
		break;
	case(SECONDDOLL_1):
		dollIcon = Sprite::createWithSpriteFrameName("portraits_towers_0001.png");
		dollName->setString("MARKSMEN");
		forceLabel->setString("12");
		speedLabel->setString("FAST");
		scopeLabel->setString("AVERAGE");
		break;
	case(FOURTHDOLL_1):
		dollIcon = Sprite::createWithSpriteFrameName("portraits_towers_0001.png");
		dollName->setString("SHARPSHOOTER");
		forceLabel->setString("16");
		speedLabel->setString("FAST");
		scopeLabel->setString("LONG");
		break;
	case(FIFTHDOLL_1):
		dollIcon = Sprite::createWithSpriteFrameName("portraits_towers_0009.png");
		dollName->setString("CROSSBOW");
		forceLabel->setString("24");
		speedLabel->setString("FAST");
		scopeLabel->setString("GREAT");
		break;
	case(SEVENTHDOLL_1):
		dollIcon = Sprite::createWithSpriteFrameName("portraits_towers_0010.png");
		dollName->setString("TOTEM TOWER");
		forceLabel->setString("24");
		speedLabel->setString("FAST");
		scopeLabel->setString("GREAT");
		break;
	default:
		break;
	}
	
}

