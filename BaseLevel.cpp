#include"BaseLevel.h"
#include "WaveTip.h"
#include "GameManager.h"
#include "GameWinLayer.h"
#include"GameFailLayer.h"
#include "SoundManager.h"
#include"WayPoint.h"

//#include "RespirationSprite.h"

//��Ҫ���ϸ��ֹ����ͷ�ļ�

USING_NS_CC;
				
//��ʼ����Ƭ��ͼ
void BaseLevel::initMap()
{
	isStart = false;
	isEnd = false;
	GameManager::getInstance()->LEVEL = level;
	
	auto format = String::createWithFormat("map/levelmap%d.tmx", level);
	tiledMap = TMXTiledMap::create(format->getCString());
	tiledMap->setAnchorPoint(Point(0, 0));
	tiledMap->setPosition(Point(0, 0));
	addChild(tiledMap);

	loadAndSetLevelData();
	//����·��
	addWayPoint();

	addOrnament();

	curWave = -1;
	time = 0;

	addGourds();               //δ��
	initTouchLayer();
	//��ֹ��ͼ����Ļ
	setMapPosition();

}

void BaseLevel::addWayPoint()
{
	GameManager* instance = GameManager::getInstance();
	auto *objects = this->tiledMap->objectGroupNamed("wayPoint");
	WayPoint *wp = NULL;
	int wayPointCounter = 1;
	ValueMap wayPoint;
	wayPoint = objects->objectNamed(std::to_string(wayPointCounter));

	while (wayPointCounter <= 8)
	{
		int x = wayPoint.at("x").asInt();
		int y = wayPoint.at("y").asInt();
		wp = WayPoint::create();
		wp->setPosition(Vec2(x, y));
		instance->wayPoints.pushBack(wp);
		wayPointCounter++;
		wayPoint = objects->objectNamed(std::to_string(wayPointCounter));
	}
	wp = NULL;
}

//��ʱ������
void BaseLevel::update(float dt)
{
	updateGourdAndLife();
	//��Ϸ�����ж�
	if (isStart && isEnd && GameManager::getInstance()->monsterVector.size() == 0)
	{
		isStart = false;
		isEnd = false;
		gameWin();
	}
}

//			//��plist�ļ��м����ƶ�·��
//void BaseLevel::loadPathFromPlist()
//{
//	winSize = Director::getInstance()->getWinSize();
//	auto plistDic = Dictionary::createWithContentsOfFile(String::createWithFormat("level%d_paths.plist",
//		getLevel())->getCString());
//
//	auto path_array = dynamic_cast<__Array*>(plistDic->objectForKey("paths"));
//
//	for (int i = 0; i<path_array->count(); i++)
//	{
//		//���� ����  ���� �����
//		std::vector<std::vector<Point>> tempPathVector;
//		auto path_array2 = dynamic_cast<__Array*>(path_array->getObjectAtIndex(i));
//		for (int j = 0; j<path_array2->count(); j++)
//		{
//			std::vector<Point> tempRandomPathVector;
//			auto path_array3 = dynamic_cast<__Array*>(path_array2->getObjectAtIndex(j));
//			for (int k = 0; k<path_array3->count(); k++)
//			{
//				auto tempDic = dynamic_cast<__Dictionary*>(path_array3->getObjectAtIndex(k));
//				Point tempPath = Point();
//				tempPath.x = dynamic_cast<__String*>(tempDic->objectForKey("x"))->floatValue()*1.15;
//				tempPath.y = dynamic_cast<__String*>(tempDic->objectForKey("y"))->floatValue()*1.20 + 50;
//				tempRandomPathVector.push_back(tempPath);
//			}
//			tempPathVector.push_back(tempRandomPathVector);
//		}
//		path.push_back(tempPathVector);
//	}
//}
//
//void BaseLevel::showWaveProgressBar(float dt)
//{
//	for (int i = 0; i<waveTips.size(); i++) 
//	{
//		waveTips.at(i)->restartWaveTip();
//	}
//}
//
//void BaseLevel::addWaveProgressBar(std::vector<Point> waveTipLocations)
//{
//	for (unsigned int i = 0; i<waveTipLocations.size(); i++) 
//	{
//		auto waveTip = WaveTip::createWaveTip();
//		waveTip->setPosition(waveTipLocations.at(i));
//		addChild(waveTip, 20);
//		auto waveflag_listener = EventListenerTouchOneByOne::create();
//		waveflag_listener->onTouchBegan = [&](Touch* touch, Event* event) {
//
//			auto target = static_cast<WaveTip*>(event->getCurrentTarget());
//
//			Point locationInNode = target->convertTouchToNodeSpace(touch);
//
//			Size size = target->waveProgressTimer->getContentSize();
//			Rect rect = Rect(0 - size.width / 2, 0 - size.height / 2, size.width, size.height);
//			if (rect.containsPoint(locationInNode) && target->isShown)
//			{
//				if (target->selected->isVisible())
//				{
//					for (int i = 0; i<waveTips.size(); i++) {
//						waveTips.at(i)->stopRespiration();
//					}
//				}
//				for (int i = 0; i<waveTips.size(); i++) {
//					waveTips.at(i)->setSelected();
//				}
//				return true;
//			}
//			return false;
//		};
//		waveflag_listener->setSwallowTouches(true);
//		_eventDispatcher->addEventListenerWithSceneGraphPriority(waveflag_listener, waveTip);
//		waveTips.pushBack(waveTip);
//	}
//}

//����ؿ�ʱ����һЩ��ʼֵ
void BaseLevel::onEnterTransitionDidFinish()
{
	GameManager::getInstance()->GOURD = startGourd;
	GameManager::getInstance()->LIFE = maxLife;
	playState->setGold(startGourd);
	playState->setLife(maxLife);
	playState->setWave(0, maxWave);
	playState->startProgressTimers();
	scheduleUpdate();
	schedule(schedule_selector(BaseLevel::addWaves), 0.5f);
}

//�� plist �ļ��м�������
void BaseLevel::loadAndSetLevelData()
{
	//���س�ʼѪ����Ǯ��
	auto dataDic = Dictionary::createWithContentsOfFile(String::createWithFormat("level%d_%d_monsters.plist", getLevel()));
	auto data_array = dynamic_cast<__Array*>(dataDic->objectForKey("data"));
	auto data_tempDic = dynamic_cast<__Dictionary*>(data_array->getObjectAtIndex(0));
	startGourd = dynamic_cast<__String*>(data_tempDic->objectForKey("gold"))->intValue();
	maxLife = dynamic_cast<__String*>(data_tempDic->objectForKey("life"))->intValue();
	maxWave = dynamic_cast<__String*>(data_tempDic->objectForKey("wave"))->intValue();
	//���ع�������
	auto monsters_array = dynamic_cast<__Array*>(dataDic->objectForKey("monsters"));

	for (int i = 0; i < monsters_array->count(); i++)
	{
		auto monster_array = dynamic_cast<__Array*>(monsters_array->getObjectAtIndex(i));
		std::vector<Vector<GroupMonster*>> thisTimeMonster;
		for (int j = 0; j<monster_array->count(); j++)
		{
			auto tempArray = dynamic_cast<__Array*>(monster_array->getObjectAtIndex(j));
			Vector<GroupMonster*> monsterVector;
			for (int k = 0; k<tempArray->count(); k++)
			{
				auto tempDic = dynamic_cast<__Dictionary*>(tempArray->getObjectAtIndex(k));
				monsterVector.pushBack(GroupMonster::initGroupEnemy(
					dynamic_cast<__String*>(tempDic->objectForKey("type"))->intValue(),
					dynamic_cast<__String*>(tempDic->objectForKey("road"))->intValue(),
					dynamic_cast<__String*>(tempDic->objectForKey("path"))->intValue()));
			}
			thisTimeMonster.push_back(monsterVector);
			monsterVector.clear();
		}
		waveVector.push_back(thisTimeMonster);
		thisTimeMonster.clear();
	}
}

		//����Ϊ�˷�ֹ��ͼ�ܵ���Ļ�����õģ� ����ȥ��
void BaseLevel::setMapPosition()
{
	Point location = Point();
	auto mapSize = mapSprite->getBoundingBox().size;
	location.x = winSize.width / 2 - mapSize.width / 2;
	location.y = winSize.height / 2 - mapSize.height / 2;
	location.x = MIN(location.x, 0);
	location.x = MAX(location.x, -mapSize.width + winSize.width);
	location.y = MIN(location.y, 0);
	location.y = MAX(location.y, -mapSize.height + winSize.height);
	this->setPosition(location);
}


void BaseLevel::updateGourdAndLife()
{
	if (GameManager::getInstance()->LIFE>0) 
	{
		playState->setGourd(GameManager::getInstance()->GOURD);
		playState->setLife(GameManager::getInstance()->LIFE);
	}
	else if (isStart) 
	{
		//ʵʱ����������0�� ��Ϸʧ��
		isStart = false;
		playState->setLife(0);

		unscheduleAllCallbacks();

		for (int i = 0; i<waveTips.size(); i++) 
		{
			waveTips.at(i)->stopRespiration();
		}
		auto failure = GameFailLayer::create();
		mTouchLayer->removeAllChildren();
		failure->level = getLevel();
		playState->addChild(failure, 99);
	}
}

void BaseLevel::onExitTransitionDidStart()
{
	GameManager::eraseAll();
	this->unscheduleAllCallbacks();
}

void BaseLevel::initTouchLayer()
{
	//���÷����������˵��㣨�����㣩
	mTouchLayer = TouchLayer::create();
	mTouchLayer->setContentSize(mapSprite->getContentSize());
	mTouchLayer->setAnchorPoint(Point(0, 0));
	mTouchLayer->setPosition(Point(0, 0));
	addChild(mTouchLayer, 99);
}

void BaseLevel::bindPlayState(PlayStateLayer* playState)
{
	this->playState = playState;
	this->playState->touchLayer = this->mTouchLayer;
}

void BaseLevel::addWaves(float dt)
{
	bool newWave = false;
	for (int i = 0; i<waveTips.size(); i++) 
	{
		if (waveTips.at(i)->getWavePercentage() == 100.0f) 
		{
			newWave = true;
			break;
		}
	}
	if (newWave && curWave<maxWave)
	{
		isStart = true;
		SoundManager::playIncomingWave();
		curWave++;
		for (int i = 0; i<waveTips.size(); i++) 
		{
			waveTips.at(i)->setWavePercentage(0.0f);
		}
		playState->setWave(curWave + 1, maxWave);
		waveEvent();
	}
}

void BaseLevel::waveEvent()
{
	schedule(schedule_selector(BaseLevel::addMonsters), 1.0f, waveVector.at(wave).size(), 0);
}

void BaseLevel::gameWin()
{
	//ֹͣ��ʱ��
	auto instance = GameManager::getInstance();
	auto dataInstance = UserDefault::getInstance();
	unscheduleUpdate();
	unschedule(schedule_selector(BaseLevel::addWaves));
	unschedule(schedule_selector(BaseLevel::addMonsters));

	auto win = GameWinLayer::createGameWin();
	mTouchLayer->removeAllChildren();

}

void BaseLevel::addMonsters(float dt)
{
	//waveVector.size����Ϊ����
	//waveVector.at()�����wave���sizeΪ�������
	//waveVector.at().at()�����0.5s����Ҫ�����Ĺ���,.sizeΪ�������
	if (time < waveVector.at(curWave).size())
	{
		for (int i = 0; i<waveVector.at(wave).at(time).size(); i++)
		{
			auto monsterData = waveVector.at(wave).at(time).at(i);
			switch (monsterData->getType())
			{
			case(0): {
				auto thug = Thug::createMonster(path.at(monsterData->getRoad()).at(monsterData->getPath()));
				addChild(thug);
				GameManager::getInstance()->monsterVector.pushBack(thug); }
					 break;
			case(1): {
				auto raider = Raider::createMonster(path.at(monsterData->getRoad()).at(monsterData->getPath()));
				addChild(raider);
				GameManager::getInstance()->monsterVector.pushBack(raider); }
					 break;
			case(2): {
				auto wolf = Wolf::createMonster(path.at(monsterData->getRoad()).at(monsterData->getPath()));
				GameManager::getInstance()->monsterVector.pushBack(wolf);
				addChild(wolf); }
					 break;
			case(3): {
				auto Immortal = Immortal::createMonster(path.at(monsterData->getRoad()).at(monsterData->getPath()));
				GameManager::getInstance()->monsterVector.pushBack(Immortal);
				addChild(Immortal); }
					 break;
			case(4): {
				auto fallen = Fallen::createMonster(path.at(monsterData->getRoad()).at(monsterData->getPath()));
				GameManager::getInstance()->monsterVector.pushBack(fallen);
				addChild(fallen); }
					 break;
			case(5): {
				auto waspHornet = WaspHornet::createMonster(path.at(monsterData->getRoad()).at(monsterData->getPath()));
				GameManager::getInstance()->monsterVector.pushBack(waspHornet);
				addChild(waspHornet); }
					 break;
			case(6): {
				auto waspQueen = WaspQueen::createMonster(path.at(monsterData->getRoad()).at(monsterData->getPath()));
				GameManager::getInstance()->monsterVector.pushBack(waspQueen);
				addChild(waspQueen); }
					 break;
			case(7): {
				auto scorpion = Scorpion::createMonster(path.at(monsterData->getRoad()).at(monsterData->getPath()));
				GameManager::getInstance()->monsterVector.pushBack(scorpion);
				addChild(scorpion); }
					 break;
			case(8): {
				auto tremor = Tremor::createMonster(path.at(monsterData->getRoad()).at(monsterData->getPath()));
				GameManager::getInstance()->monsterVector.pushBack(tremor);
				addChild(tremor); }
					 break;
			case(9): {
				auto munra = Munra::createMonster(path.at(monsterData->getRoad()).at(monsterData->getPath()));
				GameManager::getInstance()->monsterVector.pushBack(munra);
				addChild(munra); }
					 break;
			case(10): {
				auto executioner = Executioner::createMonster(path.at(monsterData->getRoad()).at(monsterData->getPath()));
				GameManager::getInstance()->monsterVector.pushBack(executioner);
				addChild(executioner); }
					  break;
			case(11): {
				auto canibal = Canibal::createMonster(path.at(monsterData->getRoad()).at(monsterData->getPath()));
				GameManager::getInstance()->monsterVector.pushBack(canibal);
				addChild(canibal); }
					  break;
			case(12): {
				auto gorilla = Gorilla::createMonster(path.at(monsterData->getRoad()).at(monsterData->getPath()));
				GameManager::getInstance()->monsterVector.pushBack(gorilla);
				addChild(gorilla); }
					  break;
			case(13): {
				auto hunter = Hunter::createMonster(path.at(monsterData->getRoad()).at(monsterData->getPath()));
				GameManager::getInstance()->monsterVector.pushBack(hunter);
				addChild(hunter); }
					  break;
			case(14): {
				auto priest = Priest::createMonster(path.at(monsterData->getRoad()).at(monsterData->getPath()));
				GameManager::getInstance()->monsterVector.pushBack(priest);
				addChild(priest); }
					  break;
			case(15): {
				auto shaman = Shaman::createMonster(path.at(monsterData->getRoad()).at(monsterData->getPath()));
				GameManager::getInstance()->monsterVector.pushBack(shaman);
				addChild(shaman); }
					  break;
			case(16): {
				auto shield = Shield::createMonster(path.at(monsterData->getRoad()).at(monsterData->getPath()));
				GameManager::getInstance()->monsterVector.pushBack(shield);
				addChild(shield); }
					  break;
			case(17): {
				auto wingRider = WingRider::createMonster(path.at(monsterData->getRoad()).at(monsterData->getPath()));
				GameManager::getInstance()->monsterVector.pushBack(wingRider);
				addChild(wingRider); }
					  break;
			case(18): {
				auto blazefang = Blazefang::createMonster(path.at(monsterData->getRoad()).at(monsterData->getPath()));
				GameManager::getInstance()->monsterVector.pushBack(blazefang);
				addChild(blazefang); }
					  break;
			case(19): {
				auto broodguard = Broodguard::createMonster(path.at(monsterData->getRoad()).at(monsterData->getPath()));
				GameManager::getInstance()->monsterVector.pushBack(broodguard);
				addChild(broodguard); }
					  break;
			case(20): {
				auto elite = Elite::createMonster(path.at(monsterData->getRoad()).at(monsterData->getPath()));
				GameManager::getInstance()->monsterVector.pushBack(elite);
				addChild(elite); }
					  break;
			case(21): {
				auto myrmidon = Myrmidon::createMonster(path.at(monsterData->getRoad()).at(monsterData->getPath()));
				GameManager::getInstance()->monsterVector.pushBack(myrmidon);
				addChild(myrmidon); 
			}
					  break;
			case(22): {
				auto nightscale = Nightscale::createMonster(path.at(monsterData->getRoad()).at(monsterData->getPath()));
				GameManager::getInstance()->monsterVector.pushBack(nightscale);
				addChild(nightscale); 
			}
					  break;
			case(23): {
				auto quetzal = Quetzal::createMonster(path.at(monsterData->getRoad()).at(monsterData->getPath()));
				GameManager::getInstance()->monsterVector.pushBack(quetzal);
				addChild(quetzal); 
			}
					  break;
			case(100): {
				auto Boss_Efreeti = Boss_Efreeti::createMonster(path.at(monsterData->getRoad()).at(monsterData->getPath()), path);
				GameManager::getInstance()->monsterVector.pushBack(Boss_Efreeti);
				addChild(Boss_Efreeti); 
			}
					   break;
			case(101): {
				auto Boss_Canibal = Boss_Canibal::createMonster(path.at(monsterData->getRoad()).at(monsterData->getPath()), path);
				GameManager::getInstance()->monsterVector.pushBack(Boss_Canibal);
				addChild(Boss_Canibal); 
			}
					   break;
			default:
				break;
			}
		}
		time++;
	}
	else 
	{
		time = 0;
		if (curWave != maxWave - 1)	
		{
			//15�����ʾWaveProgressBar
			SoundManager::playNextWaveReady();
			scheduleOnce(schedule_selector(BaseLevel::showWaveProgressBar), 15.0f);
		}
		else 
		{
			isEnd = true;
		}
	}
}
