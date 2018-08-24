#include "DollInfoLayer.h"

DollInfoLayer * DollInfoLayer::createDollInfoLayer(DollType dollType) {
	auto dollInfolayer = new DollInfoLayer();
	if (dollInfolayer && dollInfolayer->init(dollType)) {
		baseInfolayer->autorelease();
		return baseInfolayer;
	}
	CC_SAFE_DELETE(dollInfolayer);
	return NULL;
}

bool DollInfoLayer::init(DollType dollType) {
	if (!Sprite::init()) {
		return false;
	}
	info = Sprite::createWithSpriteFrameName(/*文件名*/);
	setDollInfo(dollType);
	addChild(info);
	return true;
}

void DollInfoLayer::setDollInfo(DollType dollType) {
	//信息栏背景图片
	auto infoBg = Sprite::createWithSpriteFrameName(/*文件名*/);
	dollNameSprite->setPosition(Point(/*坐标待定*/));
	info->addChild(infoBg);

	auto dollName = Label::createWithTTF("", "", );//字体设置
	dollName->setPosition(Point());//位置设置
	dollName->setAnchorPoint(Point());//锚点设置
	info->addChild(dollName);

	auto dollAttack = Label::createWithTTF("", "", );//字体设置
	dollAttack->setPosition(Point());//位置设置
	dollAttack->setAnchorPoint(Point());//锚点设置
	info->addChild(dollAttack);

	auto dollAttackSprite = Sprite::createWithSpriteFrameName(/*文件名*/);
	dollAttackSprite->setPosition(Point(/*坐标待定*/));
	info->addChild(dollAttackSprite);

	auto dollRateSprite = Sprite::createWithSpriteFrameName(/*文件名*/);
	dollRateSprite->setPosition(Point(/*坐标待定*/));
	info->addChild(dollRateSprite);

	auto dollRate = Label::createWithTTF("", "", );//字体设置
	dollRate->setPosition(Point());//位置设置
	dollRate->setAnchorPoint(Point());//锚点设置
	info->addChild(dollRate);

	auto dollScopeSprite = Sprite::createWithSpriteFrameName(/*文件名*/);
	dollScopeSprite->setPosition(Point(/*坐标待定*/));
	info->addChild(dollScopeSprite);

	auto dollScope = Label::createWithTTF("", "", );//字体设置
	dollScope->setPosition(Point());//位置设置
	dollScope->setAnchorPoint(Point());//锚点设置
	info->addChild(dollScope);

	Sprite *showinfo;
	//判断doll的攻击范围和攻击力，已在BaseDoll.h中的枚举中补充上各等级的doll
	switch (dollType)
	{
	case(FIRSTDOLL_1):
		showinfo = Sprite::createWithSpriteFrameName(/*文件名*/);
		//以下名字未定
		dollName->setString();
		dollRate->setString();
		dollScope->setString();
		dollAttack->setString();
	case(FIRSTDOLL_2):
		showinfo = Sprite::createWithSpriteFrameName(/*文件名*/);
		//以下名字未定
		dollName->setString();
		dollRate->setString();
		dollScope->setString();
		dollAttack->setString();
	case(FIRSTDOLL_3):
		showinfo = Sprite::createWithSpriteFrameName(/*文件名*/);
		//以下名字未定
		dollName->setString();
		dollRate->setString();
		dollScope->setString();
		dollAttack->setString();
	case(SECONDDOLL_1):
		showinfo = Sprite::createWithSpriteFrameName(/*文件名*/);
		//以下名字未定
		dollName->setString();
		dollRate->setString();
		dollScope->setString();
		dollAttack->setString();
	case(SECONDDOLL_2):
		showinfo = Sprite::createWithSpriteFrameName(/*文件名*/);
		//以下名字未定
		dollName->setString();
		dollRate->setString();
		dollScope->setString();
		dollAttack->setString();
	case(SECONDDOLL_3):
		showinfo = Sprite::createWithSpriteFrameName(/*文件名*/);
		//以下名字未定
		dollName->setString();
		dollRate->setString();
		dollScope->setString();
		dollAttack->setString();
	case(FOURTHDOLL_1):
		showinfo = Sprite::createWithSpriteFrameName(/*文件名*/);
		//以下名字未定
		dollName->setString();
		dollRate->setString();
		dollScope->setString();
		dollAttack->setString();
	case(FOURTHDOLL_2):
		showinfo = Sprite::createWithSpriteFrameName(/*文件名*/);
		//以下名字未定
		dollName->setString();
		dollRate->setString();
		dollScope->setString();
		dollAttack->setString();
	case(FOURTHDOLL_3):
		showinfo = Sprite::createWithSpriteFrameName(/*文件名*/);
		//以下名字未定
		dollName->setString();
		dollRate->setString();
		dollScope->setString();
		dollAttack->setString();
	case(FIFTHDLL_1):
		showinfo = Sprite::createWithSpriteFrameName(/*文件名*/);
		//以下名字未定
		dollName->setString();
		dollRate->setString();
		dollScope->setString();
		dollAttack->setString();
	case(FIFTHDLL_2):
		showinfo = Sprite::createWithSpriteFrameName(/*文件名*/);
		//以下名字未定
		dollName->setString();
		dollRate->setString();
		dollScope->setString();
		dollAttack->setString();
	case(FIFTHDLL_3):
		showinfo = Sprite::createWithSpriteFrameName(/*文件名*/);
		//以下名字未定
		dollName->setString();
		dollRate->setString();
		dollScope->setString();
		dollAttack->setString();
	case(SEVENTHDOLL_1):
		showinfo = Sprite::createWithSpriteFrameName(/*文件名*/);
		//以下名字未定
		dollName->setString();
		dollRate->setString();
		dollScope->setString();
		dollAttack->setString();
	case(SEVENTHDOLL_2):
		showinfo = Sprite::createWithSpriteFrameName(/*文件名*/);
		//以下名字未定
		dollName->setString();
		dollRate->setString();
		dollScope->setString();
		dollAttack->setString();
	case(SEVENTHDOLL_3):
		showinfo = Sprite::createWithSpriteFrameName(/*文件名*/);
		//以下名字未定
		dollName->setString();
		dollRate->setString();
		dollScope->setString();
		dollAttack->setString();
	default:
		break;
	}
	showinfo->setPosition(Point(info->getContentSize().width / 2, info->getContentSize().height / 2));
	info->addChild(showinfo);
}