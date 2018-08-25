#include"PlayStateLayer.h"
#include"GameSetting.h"
#include"DollInfoLayer.h"
#include"MonsterInfoLayer.h"
#include"MonsterIcon.h"
#include"SoundManager.h"
#include"GameManager.h"

bool PlayStateLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}
	Size winSize = Director::getInstance()->getWinSize();

	//״̬������
	stateSprite = Sprite::createWithSpriteFrameName("hud_background.png");
	stateSprite->setAnchorPoint(Point(0, 1));
	stateSprite->setPosition(Point(20, winSize.height - 20 + 100));
	addChild(stateSprite);
	//״̬��Ԫ��
	lifeLabel = Label::createWithTTF("0", "arial.ttf", 20);
	lifeLabel->setPosition(Point(stateSprite->getContentSize().width / 4, stateSprite->getContentSize().height / 4 * 3));
	stateSprite->addChild(lifeLabel);

	gourdLabel = Label::createWithTTF("0", "arial.ttf", 20);
	gourdLabel->setPosition(Point(stateSprite->getContentSize().width / 4 * 3, stateSprite->getContentSize().height / 4 * 3));
	stateSprite->addChild(gourdLabel);

	waveLabel = Label::createWithTTF("", "arial.ttf", 20);
	waveLabel->setPosition(Point(stateSprite->getContentSize().width / 2, stateSprite->getContentSize().height / 4));
	stateSprite->addChild(waveLabel);

	pause = Sprite::createWithSpriteFrameName("hud_buttons_0001.png");
	pause->setAnchorPoint(Point(1, 1));
	pause->setPosition(Point(winSize.width - 20, winSize.height - 20 + 100));
	addChild(pause);

	//���
	kingKongSprite = Sprite::createWithSpriteFrameName("power_portrait_fireball_0001.png");
	kingKongSprite->setAnchorPoint(Point(0, 0));
	kingKongSprite->setPosition(Point(10, -20));
	kingKongSprite->setName("inactive");
	isCompleteKingKong = false;
	addChild(kingKongSprite, 1);

	//���ܵ���ʱ
	kingKongTimer = ProgressTimer::create(Sprite::createWithSpriteFrameName("power_loading.png"));
	kingKongTimer->setAnchorPoint(Point(0, 0));
	kingKongTimer->setReverseDirection(true);
	kingKongTimer->setPosition(Point(10, -20));
	kingKongTimer->setPercentage(100);//��ʾԭ�εİٷֱ�
	this->addChild(kingKongTimer, 1, 100);

	//��ͣ��ť (������Ϸ����)

	auto pause_listener = EventListenerTouchOneByOne::create();
	pause_listener->onTouchBegan = [&](Touch* touch, Event* event) {

		auto target = static_cast<Sprite*>(event->getCurrentTarget());

		Point locationInNode = target->convertTouchToNodeSpace(touch);

		Size size = target->getContentSize();
		Rect rect = Rect(0, 0, size.width, size.height);
		if (rect.containsPoint(locationInNode))
		{
			SoundManager::playClickEffect();
			return true;
		}
		return false;
	};
	pause_listener->onTouchEnded = [&](Touch* touch, Event* event) {
		removeDollInfo();
		removeMonsterInfo();
		addGameSetting();
	};
	pause_listener->setSwallowTouches(true);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(pause_listener, pause);

	//�������
	auto kingKongListener = EventListenerTouchOneByOne::create();
	kingKongListener->onTouchBegan = [&](Touch* touch, Event* event) {

		auto target = static_cast<Sprite*>(event->getCurrentTarget());
		Point locationInNode = target->convertTouchToNodeSpace(touch);
		Size size = target->getContentSize();
		Rect rect = Rect(0, 0, size.width, size.height);
		//�����
		if (rect.containsPoint(locationInNode)) {
			//����ȴ����
			if (isCompleteKingKong == true) {
				touchLayer->removeAllListener();
				if (kingKongSprite->getName() == "inactive") {
					//����Ϊ���״̬
					kingKongSprite->setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("power_portrait_fireball_0002.png"));
					//�ı�״̬TAG
					kingKongSprite->setName("active");
					//�ı���������״̬
					//SixthDollSprite->setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("power_portrait_reinforcement_0001.png"));
					touchLayer->setKingKongTouchShield();
					//�ڶ��ε��
				}
				else {
					kingKongSprite->setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("power_portrait_fireball_0001.png"));
					kingKongSprite->setName("inactive");
				}
			}
			return true;
		}
		return false;
	};

	kingKongListener->onTouchEnded = [&](Touch* touch, Event* event) {
	};
	kingKongListener->setSwallowTouches(true);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(kingKongListener, kingKongSprite);

	return true;
}

void PlayStateLayer::initGameSetting()
{
	gameSetting = GameSetting::create();
	gameSetting->level = this->getLevel();
	gameSetting->setPosition(Vec2(0, Director::getInstance()->getVisibleSize().height));
	addChild(gameSetting, 60);
}

void PlayStateLayer::addGameSetting()
{
	auto color = LayerColor::create(Color4B(0, 0, 0, 60), Director::getInstance()->getVisibleSize().width, Director::getInstance()->getVisibleSize().height);
	color->setTag(501);
	addChild(color);
	auto gameSettingListener = EventListenerTouchOneByOne::create();
	gameSettingListener->onTouchBegan = [&](Touch* touch, Event* event) {
		return true;
	};
	gameSettingListener->setSwallowTouches(true);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(gameSettingListener, color);
	gameSetting->runAction(
		Sequence::create(MoveBy::create(0.2f, Point(0, -Director::getInstance()->getVisibleSize().height)),
			CallFuncN::create(CC_CALLBACK_0(PlayStateLayer::pauseGame, this)), NULL));
}

void PlayStateLayer::removeGameSetting()
{
	Director::getInstance()->resume();
	gameSetting->runAction(MoveBy::create(0.2f, Point(0, Director::getInstance()->getVisibleSize().height)));
	removeChildByTag(501);
}

void PlayStateLayer::pauseGame()
{
	Director::getInstance()->pause();
}

void PlayStateLayer::startProgressTimers()
{
	this->schedule(schedule_selector(PlayStateLayer::updateKingKongProgress));
}

void PlayStateLayer::startKingKong()
{
	isCompleteKingKong = false;
	kingKongSprite->setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("power_portrait_fireball_0001.png"));
	kingKongSprite->setName("inactive");
	kingKongTimer->setPercentage(100.0f);
	this->unschedule(schedule_selector(PlayStateLayer::updateKingKongProgress));
	this->schedule(schedule_selector(PlayStateLayer::updateKingKongProgress));
}

void PlayStateLayer::showDollInfo(DollType dollType)
{
	//removeChildByTag(MONSTER_INFO);
	//removeChildByTag(TOWER_INFO);
	//packSprite->setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("power_portrait_backpack_0001.png"));
	//packSprite->setName("inactive");
	//backPackSprite->setVisible(false);
	auto dollInfoLayer = DollInfoLayer::createDollInfo(dollType);
	//dollInfoLayer->setTag(doll_INFO);
	addChild(dollInfoLayer);
	dollInfoLayer->setAnchorPoint(Point(0, 0));
	dollInfoLayer->setPosition(Point(620, -50));
	dollInfoLayer->runAction(MoveBy::create(0.2f, Point(0, 100)));
}

void PlayStateLayer::removeDollInfo()
{
	//removeChildByTag(TOWER_INFO);
}

void PlayStateLayer::showMonsterInfo(BaseMonster* monster)
{
	removeChildByTag(TOWER_INFO);
	removeChildByTag(MONSTER_INFO);
	auto monsterInfoLayer = MonsterInfoLayer::createMonsterInfo(monster);
	monsterInfoLayer->setTag(MONSTER_INFO);
	addChild(monsterInfoLayer);
	monsterInfoLayer->setAnchorPoint(Point(0, 0));
	monsterInfoLayer->setPosition(Point(620, -50));
	monsterInfoLayer->runAction(MoveBy::create(0.2f, Point(0, 100)));
}

void PlayStateLayer::removeMonsterInfo()
{
	removeChildByTag(MONSTER_INFO);
}

//������������
void PlayStateLayer::setLife(int life)
{
	lifeLabel->setString(String::createWithFormat("%d", life)->getCString());
}

//���ú�«����
void PlayStateLayer::setGourd(int gourd)
{
	gourdLabel->setString(String::createWithFormat("%d", gourd)->getCString());
}

//���ò���
void PlayStateLayer::setWave(int thisWave, int totalWave)
{
	waveLabel->setString(String::createWithFormat("WAVE %d/%d", thisWave, totalWave)->getCString());
}

void PlayStateLayer::onEnterTransitionDidFinish()
{
	stateSprite->runAction(MoveBy::create(0.2f, Point(0, -100)));
	pause->runAction(MoveBy::create(0.2f, Point(0, -100)));

}

//Բ�ε���ʱ������-���
void PlayStateLayer::updateKingKongProgress(float dt) 
{
	kingKongTimer->setPercentage(kingKongTimer->getPercentage() - dt * 2);
	//���½���
	if (kingKongTimer->getPercentage() == 0) 
	{
		//ȡ����ʱ��
		this->unschedule(schedule_selector(PlayStateLayer::updateKingKongProgress));
		isCompleteKingKong = true;
	}
	return;
}

void PlayStateLayer::clearMonsters()
{
	//��ȡ������Ϣ
	auto monstersVector = GameManager::getInstance()->monsterVector;

	for (int i = 0; i<monstersVector.size(); i++) 
	{
		auto monster = monstersVector.at(i);
		if (monster != NULL) 
		{
			
			monster->death();
			//instance->monsterVector.eraseObject(monster);
		}
	}
}
