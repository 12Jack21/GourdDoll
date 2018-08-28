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

	//三张图的位置
	auto left = Sprite::createWithSpriteFrameName("left_trans.png");
	left->setPosition(Vec2(-left->getContentSize().width / 2, left->getContentSize().height / 2));
	addChild(left);

	auto mid = Sprite::createWithSpriteFrameName("mid_trans.png");
	mid->setPosition(Vec2(623.5f, -mid->getContentSize().height / 2));
	addChild(mid);

	auto right = Sprite::createWithSpriteFrameName("right_trans.png");
	right->setPosition(Vec2(visibleSize.width + right->getContentSize().width / 2, right->getContentSize().height / 2));
	addChild(right);

	//左图向右
	auto leftAction1 = MoveBy::create(_duration / 3, Vec2(left->getContentSize().width, 0));

	auto leftAction2 = MoveTo::create(_duration / 3, Vec2(-left->getContentSize().width / 2, left->getContentSize().height / 2));
	//中图向上
	auto midAction1 = MoveBy::create(_duration / 3, Vec2(0, mid->getContentSize().height));
	auto midAction2 = MoveTo::create(_duration / 3, Vec2(623.5f, -mid->getContentSize().height / 2));
	//右图向左
	auto rightAction1 = MoveBy::create(_duration / 3, Vec2(-right->getContentSize().width, 0));

	auto rightAction2 = MoveBy::create(_duration / 3, Vec2(visibleSize.width + right->getContentSize().width / 2, right->getContentSize().height / 2));

	//if (UserDefault::getInstance()->getIntegerForKey("backeffect", 1) == 1)
	//{
	//	SimpleAudioEngine::getInstance()->playEffect(".wav");
	//}
	//间隔时间
	auto delayTime = DelayTime::create(1.0f);
	left->runAction(Sequence::create(
		leftAction1,
		CallFuncN::create(CC_CALLBACK_0(TransitionInterface::OnEnterDidFinish, this)),
		delayTime,
		leftAction2,
		CallFuncN::create(CC_CALLBACK_0(TransitionScene::finish, this)),
		NULL));
	right->runAction(Sequence::create(rightAction1, delayTime, rightAction2, NULL));
	mid->runAction(Sequence::create(midAction1, delayTime, midAction2, NULL));
}

void TransitionInterface::OnEnterDidFinish()
{
	//if (UserDefault::getInstance()->getIntegerForKey("backeffect", 1) == 1)
	//{
	//	SimpleAudioEngine::getInstance()->playEffect(".wav");
	//}
	//下个场景设置为可见
	_inScene->setVisible(true);
	//原场景设置为不可见
	_outScene->setVisible(false);
}