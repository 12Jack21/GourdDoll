#include"TransitionInterface.h"

using namespace CocosDenshion;

TransitionInterface* TransitionInterface::create(float t, Scene* scene)
{
	TransitionInterface* transitionScene = new TransitionInterface();
	if (transitionScene && transitionScene->initWithDuration(t, scene))
	{
		transitionScene->autorelease();
		return transitionScene;
	}
	CC_SAFE_DELETE(transitionScene);
	return nullptr;
}

void TransitionInterface::onEnter()
{

	//要切入的场景
	_inScene->setVisible(false);
	TransitionScene::onEnter();
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 stLeftBegin, stLeftEnd, stRightBegin, stRightEnd;

	stLeftBegin.setPoint(0, visibleSize.height / 2.0f);
	stLeftEnd.setPoint(visibleSize.width / 2.0f, visibleSize.height / 2.0f);

	stRightBegin.setPoint(visibleSize.width, visibleSize.height / 2.0f);
	stRightEnd.setPoint(visibleSize.width / 2.0f, visibleSize.height / 2.0f);

	auto pLeft1 = Sprite::createWithSpriteFrameName(".png");
	pLeft1->setScaleX();
	auto pRight1 = Sprite::createWithSpriteFrameName(".png");
	pRight1->setScaleX();
	auto pLeft2 = Sprite::createWithSpriteFrameName(".png");
	auto pRight2 = Sprite::createWithSpriteFrameName(".png");

	pLeft1->setAnchorPoint(Vec2(1.0f, 0.5f));
	pRight1->setAnchorPoint(Vec2(0, 0.5f));

	pLeft2->setAnchorPoint(Vec2(1.0f, 0.5f));
	pRight2->setAnchorPoint(Vec2(0, 0.5f));

	pLeft2->setPosition(Vec2(pLeft1->getContentSize().width, pLeft1->getContentSize().height / 2));
	pRight2->setPosition(Vec2(0, pRight1->getContentSize().height / 2));

	addChild(pLeft1, 1);
	addChild(pRight1, 1);

	//左图翻转
	pRight1->setFlippedX(true);
	pLeft1->setPosition(stLeftBegin);
	pRight1->setPosition(stRightBegin);

	pLeft1->addChild(pLeft2);
	pRight1->addChild(pRight2);
	//左图向右移动
	auto pActionLeft1 = MoveTo::create(_duration / 3, stLeftEnd);
	//右图向左移动
	auto pActionRight1 = MoveTo::create(_duration / 3, stRightEnd);

	//两图反向
	auto pActionLeft2 = MoveTo::create(_duration / 3, stLeftBegin);
	auto pActionRight2 = MoveTo::create(_duration / 3, stRightBegin);

	if (UserDefault::getInstance()->getIntegerForKey("backeffect", 1) == 1)
	{
		SimpleAudioEngine::getInstance()->playEffect(".wav");
	}
	//间隔时间
	auto delayTime = DelayTime::create(1.0f);
	pLeft1->runAction(Sequence::create(
		pActionLeft1,
		CallFuncN::create(CC_CALLBACK_0(TransitionInterface::OnEnterDidFinish, this)),
		delayTime,
		pActionLeft2,
		CallFuncN::create(CC_CALLBACK_0(TransitionScene::finish, this)),
		NULL));
	pRight1->runAction(Sequence::create(pActionRight1, delayTime, pActionRight2, NULL));
}

void TransitionInterface::OnEnterDidFinish()
{
	if (UserDefault::getInstance()->getIntegerForKey("backeffect", 1) == 1)
	{
		SimpleAudioEngine::getInstance()->playEffect(".wav");
	}
	//下个场景设置为可见
	_inScene->setVisible(true);
	//原场景设置为不可见
	_outScene->setVisible(false);
}