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
	info = Sprite::createWithSpriteFrameName(/*�ļ���*/);
	setDollInfo(dollType);
	addChild(info);
	return true;
}

void DollInfoLayer::setDollInfo(DollType dollType) {
	//��Ϣ������ͼƬ
	auto infoBg = Sprite::createWithSpriteFrameName(/*�ļ���*/);
	dollNameSprite->setPosition(Point(/*�������*/));
	info->addChild(infoBg);

	auto dollName = Label::createWithTTF("", "", );//��������
	dollName->setPosition(Point());//λ������
	dollName->setAnchorPoint(Point());//ê������
	info->addChild(dollName);

	auto dollAttack = Label::createWithTTF("", "", );//��������
	dollAttack->setPosition(Point());//λ������
	dollAttack->setAnchorPoint(Point());//ê������
	info->addChild(dollAttack);

	auto dollAttackSprite = Sprite::createWithSpriteFrameName(/*�ļ���*/);
	dollAttackSprite->setPosition(Point(/*�������*/));
	info->addChild(dollAttackSprite);

	auto dollRateSprite = Sprite::createWithSpriteFrameName(/*�ļ���*/);
	dollRateSprite->setPosition(Point(/*�������*/));
	info->addChild(dollRateSprite);

	auto dollRate = Label::createWithTTF("", "", );//��������
	dollRate->setPosition(Point());//λ������
	dollRate->setAnchorPoint(Point());//ê������
	info->addChild(dollRate);

	auto dollScopeSprite = Sprite::createWithSpriteFrameName(/*�ļ���*/);
	dollScopeSprite->setPosition(Point(/*�������*/));
	info->addChild(dollScopeSprite);

	auto dollScope = Label::createWithTTF("", "", );//��������
	dollScope->setPosition(Point());//λ������
	dollScope->setAnchorPoint(Point());//ê������
	info->addChild(dollScope);

	Sprite *showinfo;
	//�ж�doll�Ĺ�����Χ�͹�����������BaseDoll.h�е�ö���в����ϸ��ȼ���doll
	switch (dollType)
	{
	case(FIRSTDOLL_1):
		showinfo = Sprite::createWithSpriteFrameName(/*�ļ���*/);
		//��������δ��
		dollName->setString();
		dollRate->setString();
		dollScope->setString();
		dollAttack->setString();
	case(FIRSTDOLL_2):
		showinfo = Sprite::createWithSpriteFrameName(/*�ļ���*/);
		//��������δ��
		dollName->setString();
		dollRate->setString();
		dollScope->setString();
		dollAttack->setString();
	case(FIRSTDOLL_3):
		showinfo = Sprite::createWithSpriteFrameName(/*�ļ���*/);
		//��������δ��
		dollName->setString();
		dollRate->setString();
		dollScope->setString();
		dollAttack->setString();
	case(SECONDDOLL_1):
		showinfo = Sprite::createWithSpriteFrameName(/*�ļ���*/);
		//��������δ��
		dollName->setString();
		dollRate->setString();
		dollScope->setString();
		dollAttack->setString();
	case(SECONDDOLL_2):
		showinfo = Sprite::createWithSpriteFrameName(/*�ļ���*/);
		//��������δ��
		dollName->setString();
		dollRate->setString();
		dollScope->setString();
		dollAttack->setString();
	case(SECONDDOLL_3):
		showinfo = Sprite::createWithSpriteFrameName(/*�ļ���*/);
		//��������δ��
		dollName->setString();
		dollRate->setString();
		dollScope->setString();
		dollAttack->setString();
	case(FOURTHDOLL_1):
		showinfo = Sprite::createWithSpriteFrameName(/*�ļ���*/);
		//��������δ��
		dollName->setString();
		dollRate->setString();
		dollScope->setString();
		dollAttack->setString();
	case(FOURTHDOLL_2):
		showinfo = Sprite::createWithSpriteFrameName(/*�ļ���*/);
		//��������δ��
		dollName->setString();
		dollRate->setString();
		dollScope->setString();
		dollAttack->setString();
	case(FOURTHDOLL_3):
		showinfo = Sprite::createWithSpriteFrameName(/*�ļ���*/);
		//��������δ��
		dollName->setString();
		dollRate->setString();
		dollScope->setString();
		dollAttack->setString();
	case(FIFTHDLL_1):
		showinfo = Sprite::createWithSpriteFrameName(/*�ļ���*/);
		//��������δ��
		dollName->setString();
		dollRate->setString();
		dollScope->setString();
		dollAttack->setString();
	case(FIFTHDLL_2):
		showinfo = Sprite::createWithSpriteFrameName(/*�ļ���*/);
		//��������δ��
		dollName->setString();
		dollRate->setString();
		dollScope->setString();
		dollAttack->setString();
	case(FIFTHDLL_3):
		showinfo = Sprite::createWithSpriteFrameName(/*�ļ���*/);
		//��������δ��
		dollName->setString();
		dollRate->setString();
		dollScope->setString();
		dollAttack->setString();
	case(SEVENTHDOLL_1):
		showinfo = Sprite::createWithSpriteFrameName(/*�ļ���*/);
		//��������δ��
		dollName->setString();
		dollRate->setString();
		dollScope->setString();
		dollAttack->setString();
	case(SEVENTHDOLL_2):
		showinfo = Sprite::createWithSpriteFrameName(/*�ļ���*/);
		//��������δ��
		dollName->setString();
		dollRate->setString();
		dollScope->setString();
		dollAttack->setString();
	case(SEVENTHDOLL_3):
		showinfo = Sprite::createWithSpriteFrameName(/*�ļ���*/);
		//��������δ��
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