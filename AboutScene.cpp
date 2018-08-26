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

	//背景
	bg = Sprite::createWithSpriteFrameName(".png");
	bg->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	addChild(bg, -1);

	//初始化装饰精灵
	initOrnamentSprite();

	//初始化字体
	initLabel();

	//返回菜单
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
	//实现装饰精灵动作

}

void AboutScene::initLabel()
{
	//实现标签内容和字体

}

void AboutScene::menuCallBack(Ref* pSender)
{
	Director::getInstance()->replaceScene(WelcomeScene::createScene());
}