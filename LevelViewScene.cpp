#include"LevelViewScene.h"
#include"GameScene.h"

Scene* LevelViewScene::createScene()
{
	auto scene = Scene::create();
	auto layer = LevelViewScene::create();
	scene->addChild(layer);
	return scene;
}

bool LevelViewScene::init()
{
	if (!Layer::init())
	{
		return false;
	}
	visibleSize = Director::getInstance()->getVisibleSize();

	//背景
	auto bg = Sprite::createWithSpriteFrameName("");
	bg->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	addChild(bg);

	//初始化菜单
	initLevelMenu();

	//接触监测
	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(LevelViewScene::onTouchBegan, this);
	listener->onTouchEnded = CC_CALLBACK_2(LevelViewScene::onTouchEnded, this);

	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
	return true;
}

//七个葫芦菜单精灵
void LevelViewScene::initLevelMenu()
{
	//动作创建
	auto rotate1 = RotateTo::create(1.0f, 40.0f);
	auto roatat2 = RotateTo::create(2.0f, -40.0f);
	auto delay = DelayTime::create(0.3f);

	auto sequence1 = Sequence::create(rotate1, delay, roatat2, NULL);
	auto gourdAction = RepeatForever::create(sequence1);

	//实现葫芦绕顶部左右晃动（旋转
	auto gourd1 = Sprite::createWithSpriteFrameName("");
	gourd1->setPosition(Vec2());
	//葫芦绕 锚点 旋转
	gourd1->setAnchorPoint(Vec2());
	addChild(gourd1);
	gourd1->runAction(gourdAction);

	auto gourd2 = Sprite::createWithSpriteFrameName("");
	gourd2->setPosition(Vec2());
	gourd2->setAnchorPoint(Vec2());
	addChild(gourd2);

	auto gourd3 = Sprite::createWithSpriteFrameName("");
	gourd3->setPosition(Vec2());
	gourd3->setAnchorPoint(Vec2());
	addChild(gourd3);

	auto gourd4 = Sprite::createWithSpriteFrameName("");
	gourd4->setPosition(Vec2());
	gourd4->setAnchorPoint(Vec2());
	addChild(gourd4);

	auto gourd5 = Sprite::createWithSpriteFrameName("");
	gourd5->setPosition(Vec2());
	gourd5->setAnchorPoint(Vec2());
	addChild(gourd5);

	auto gourd6 = Sprite::createWithSpriteFrameName("");
	gourd6->setPosition(Vec2());
	gourd6->setAnchorPoint(Vec2());
	addChild(gourd6);

	auto gourd7 = Sprite::createWithSpriteFrameName("");
	gourd7->setPosition(Vec2());
	gourd7->setAnchorPoint(Vec2());
	addChild(gourd7);

}

bool LevelViewScene::onTouchBegan(Touch* touch, Event* event)
{
	auto target = static_cast<Sprite*>(event->getCurrentTarget());
	Point locationInNode = target->convertTouchToNodeSpace(touch);
	Rect rect = target->getBoundingBox();

	if (rect.containsPoint(locationInNode))
	{
		target->pauseSchedulerAndActions();
	}
	return true;
}

void LevelViewScene::onTouchEnded(Touch* touch, Event* event)
{
	auto target = static_cast<Sprite*>(event->getCurrentTarget());
	Point locationInNode = target->convertTouchToNodeSpace(touch);
	Rect rect = target->getBoundingBox();

	if (rect.containsPoint(locationInNode))
	{
		Director::getInstance()->replaceScene(GameScene::create());
	}
	else
	{
		target->resumeSchedulerAndActions();
	}

}