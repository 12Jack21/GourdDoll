#include "DollInfoLayer.h"

DollInfoLayer * DollInfoLayer::createDollInfoLayer(DollType dollType) {
	auto dollInfolayer = new DollInfoLayer();
	if (dollInfolayer && dollInfolayer->init(dollType)) {
		dollInfolayer->autorelease();
		return dollInfolayer;
	}
	CC_SAFE_DELETE(dollInfolayer);
	return NULL;
}

bool DollInfoLayer::init(DollType dollType) {
	if (!Sprite::init()) {
		return false;
	}
	info = Sprite::createWithSpriteFrameName(".png");
	setDollInfo(dollType);
	addChild(info);
	return true;
}

void DollInfoLayer::setDollInfo(DollType dollType) {
	//��Ϣ������ͼƬ
	auto infoBg = Sprite::createWithSpriteFrameName(".png");
	infoBg->setPosition(Point(20,25));
	info->addChild(infoBg);

	auto dollName = Label::createWithTTF("", "", 20);//��������
	dollName->setPosition(Point(60,25));//λ������
	dollName->setAnchorPoint(Point(0,0.5));//ê������
	info->addChild(dollName);

	auto dollAttack = Label::createWithTTF("", "", 18);//��������
	dollAttack->setPosition(Point(325,25));//λ������
	dollAttack->setAnchorPoint(Point(0, 0.5));//ê������
	info->addChild(dollAttack);

	auto dollAttackSprite = Sprite::createWithSpriteFrameName(".png");
	dollAttackSprite->setPosition(Point(300,25));
	info->addChild(dollAttackSprite);

	auto dollRateSprite = Sprite::createWithSpriteFrameName(".png");
	dollRateSprite->setPosition(Point(400,25));
	info->addChild(dollRateSprite);

	auto dollRate = Label::createWithTTF("", "", 18);//��������
	dollRate->setPosition(Point(435,25));//λ������
	dollRate->setAnchorPoint(Point(0,0.5));//ê������
	info->addChild(dollRate);

	auto dollScopeSprite = Sprite::createWithSpriteFrameName(".png");
	dollScopeSprite->setPosition(Point(570,25));
	info->addChild(dollScopeSprite);

	auto dollScope = Label::createWithTTF("", "", 18);//��������
	dollScope->setPosition(Point(605,25));//λ������
	dollScope->setAnchorPoint(Point(0,0.5));//ê������
	info->addChild(dollScope);

	Sprite *showinfo;
	//�ж�doll�Ĺ�����Χ�͹���������BaseDoll.h�е�ö���в����ϸ��ȼ���doll
	switch (dollType)
	{
	case(FIRSTDOLL_1):
		showinfo = Sprite::createWithSpriteFrameName(".png");
		//��������δ��
		dollName->setString();
		dollRate->setString();
		dollScope->setString();
		dollAttack->setString();
	case(FIRSTDOLL_2):
		showinfo = Sprite::createWithSpriteFrameName(".png");
		//��������δ��
		dollName->setString();
		dollRate->setString();
		dollScope->setString();
		dollAttack->setString();
	case(FIRSTDOLL_3):
		showinfo = Sprite::createWithSpriteFrameName(".png");
		//��������δ��
		dollName->setString();
		dollRate->setString();
		dollScope->setString();
		dollAttack->setString();
	case(SECONDDOLL_1):
		showinfo = Sprite::createWithSpriteFrameName(".png");
		//��������δ��
		dollName->setString();
		dollRate->setString();
		dollScope->setString();
		dollAttack->setString();
	case(SECONDDOLL_2):
		showinfo = Sprite::createWithSpriteFrameName(".png");
		//��������δ��
		dollName->setString();
		dollRate->setString();
		dollScope->setString();
		dollAttack->setString();
	case(SECONDDOLL_3):
		showinfo = Sprite::createWithSpriteFrameName(".png");
		//��������δ��
		dollName->setString();
		dollRate->setString();
		dollScope->setString();
		dollAttack->setString();
	case(FOURTHDOLL_1):
		showinfo = Sprite::createWithSpriteFrameName(".png");
		//��������δ��
		dollName->setString();
		dollRate->setString();
		dollScope->setString();
		dollAttack->setString();
	case(FOURTHDOLL_2):
		showinfo = Sprite::createWithSpriteFrameName(".png");
		//��������δ��
		dollName->setString();
		dollRate->setString();
		dollScope->setString();
		dollAttack->setString();
	case(FOURTHDOLL_3):
		showinfo = Sprite::createWithSpriteFrameName(".png");
		//��������δ��
		dollName->setString();
		dollRate->setString();
		dollScope->setString();
		dollAttack->setString();
	case(FIFTHDOLL_1):
		showinfo = Sprite::createWithSpriteFrameName(".png");
		//��������δ��
		dollName->setString();
		dollRate->setString();
		dollScope->setString();
		dollAttack->setString();
	case(FIFTHDOLL_2):
		showinfo = Sprite::createWithSpriteFrameName(".png");
		//��������δ��
		dollName->setString();
		dollRate->setString();
		dollScope->setString();
		dollAttack->setString();
	case(FIFTHDOLL_3):
		showinfo = Sprite::createWithSpriteFrameName(".png");
		//��������δ��
		dollName->setString();
		dollRate->setString();
		dollScope->setString();
		dollAttack->setString();
	case(SEVENTHDOLL_1):
		showinfo = Sprite::createWithSpriteFrameName(".png");
		//��������δ��
		dollName->setString();
		dollRate->setString();
		dollScope->setString();
		dollAttack->setString();
	case(SEVENTHDOLL_2):
		showinfo = Sprite::createWithSpriteFrameName(".png");
		//��������δ��
		dollName->setString();
		dollRate->setString();
		dollScope->setString();
		dollAttack->setString();
	//case(SEVENTHDOLL_3):
	//	showinfo = Sprite::createWithSpriteFrameName(".png");
	//	//��������δ��
	//	dollName->setString();
	//	dollRate->setString();
	//	dollScope->setString();
	//	dollAttack->setString();
	default:
		break;
	}
	showinfo->setPosition(Point(info->getContentSize().width / 2, info->getContentSize().height / 2));
	info->addChild(showinfo);
}