#include"GameFailLayer.h"
#include"SoundManager.h"

bool GameFailLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}
	//��ʼ��ѡ��
	initOption();

	Size visibleSize = Director::getInstance()->getVisibleSize();
	//����ɫ
	auto layerColor = LayerColor::create(Color4B(0, 0, 0, 50),
		visibleSize.width, visibleSize.height);
	addChild(layerColor);

	//ʧ�ܲ���붯��


	//ʧ����Ч
	SoundManager::playGameFail();
	return true;
}


void GameFailLayer::initOption()
{
	//���¿�ʼ
	auto restart = Sprite::createWithSpriteFrameName("options_buttons_0003.png");
	restart->setPosition(Point(-145, -100));
	restart->setTag(0);
	//�˳�
	auto exit = Sprite::createWithSpriteFrameName("options_buttons_0001.png");
	exit->setPosition(Point(145, -100));
	exit->setTag(1);

	option->addChild(restart);
	option->addChild(exit);

	auto listener = EventListenerTouchOneByOne::create();
	listener->setSwallowTouches(true);
	listener->onTouchBegan = CC_CALLBACK_2(Failure::onTouchBegan, this);
	listener->onTouchEnded = CC_CALLBACK_2(Failure::onTouchEnded, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, restart);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener->clone(), exit);

}
