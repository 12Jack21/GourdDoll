#include"AboutScene.h"
#include"WelcomeScene.h"



Scene* AboutScene::createScene()
{
	auto scene = Scene::create();
	auto layer = AboutScene::create();
	scene->addChild(layer);
	return scene;
}

bool AboutScene::init()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();

	//����
	bg = Sprite::createWithSpriteFrameName(".png");
	bg->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	addChild(bg, -1);

	//��ʼ��װ�ξ���
	initOrnamentSprite();

	//��ʼ������
	initLabel();

	//���ز˵�
	auto backSprite1 = Sprite::createWithSpriteFrameName("");
	auto backSprite2 = Sprite::createWithSpriteFrameName("");
	auto backMenu = MenuItemSprite::create(backSprite1, backSprite2,
		CC_CALLBACK_1(AboutScene::menuCallBack, this));
	backMenu->setPosition();
	auto mn = Menu::create(backMenu, NULL);

	return true;
}

void AboutScene::initOrnamentSprite()
{
	//ʵ��װ�ξ��鶯��

}

void AboutScene::initLabel()
{
	//ʵ�ֱ�ǩ���ݺ�����

}

void AboutScene::menuCallBack(Ref* pSender)
{
	Director::getInstance()->replaceScene(WelcomeScene::createScene());
}