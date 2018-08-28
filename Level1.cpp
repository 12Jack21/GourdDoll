#include"Level1.h"

USING_NS_CC;

Level1* Level1::createGame()
{
	auto layer = new Level1();
	if (layer && layer->init()) {
		layer->autorelease();
		return layer;
	}
	CC_SAFE_DELETE(layer);

	return NULL;
}

bool Level1::init()
{
	if (!Layer::init())
	{
		return false;
	}
	setLevel(1);

	initMap();



	//std::vector<Point> points;
	////road 0提示        技能
	//points.push_back(Point(980, 40));
	////road 1 提示		技能
	//points.push_back(Point(40, 270));
	//addWaveProgressBars(points);
	//waveFlags.at(0)->restartWaveFlag();
	//waveFlags.at(1)->restartWaveFlag();
	SoundManager::playGameBackMusic();
	return true;

}

//装饰物
void Level1::addOrnament()
{

}

void Level1::onExit()
{
	SpriteFrameCache::getInstance()->removeSpriteFrameByName(".plist");
}

////////////////////////////////////////增加葫芦（设塔点）,位置未定
void Level1::addGourds()
{
	auto terrain1 = Gourd::createGourd(1);
	terrain1->setPosition(Point(610, 820));//终点
	terrain1->setTag(1);
	addChild(terrain1, 2);

	auto terrain13 = Gourd::createGourd(1);
	terrain13->setPosition(Point(340, 750));//终点下
	terrain13->setTag(13);
	addChild(terrain13, 3);

	auto terrain12 = Gourd::createGourd(1);
	terrain12->setPosition(Point(650, 650));//水桶旁上
	terrain12->setTag(12);
	addChild(terrain12, 4);

	auto terrain3 = Gourd::createGourd(1);
	terrain3->setPosition(Point(535, 620));//水桶旁
	terrain3->setTag(3);
	addChild(terrain3, 4);

	auto terrain10 = Gourd::createGourd(1);
	terrain10->setPosition(Point(540, 560));//与圆环旁拐角相对相临
	terrain10->setTag(10);
	addChild(terrain10, 5);

	auto terrain7 = Gourd::createGourd(1);
	terrain7->setPosition(Point(590, 460));//与圆环旁拐角相对
	terrain7->setTag(7);
	addChild(terrain7, 6);

	auto terrain9 = Gourd::createGourd(1);
	terrain9->setPosition(Point(310, 440));//与假山旁2
	terrain9->setTag(9);
	addChild(terrain9, 6);

	auto terrain6 = Gourd::createGourd(1);
	terrain6->setPosition(Point(900, 440));//与牛角旁拐角相对
	terrain6->setTag(6);
	addChild(terrain6, 6);

	auto terrain2 = Gourd::createGourd(1);
	terrain2->setPosition(Point(380, 360));//假山旁第一拐角
	terrain2->setTag(2);
	addChild(terrain2, 7);

	auto terrain8 = Gourd::createGourd(1);
	terrain8->setPosition(Point(250, 360));//与假山旁1
	terrain8->setTag(8);
	addChild(terrain8, 7);

	auto terrain4 = Gourd::createGourd(1);
	terrain4->setPosition(Point(590, 300));//圆环旁拐角
	terrain4->setTag(4);
	addChild(terrain4, 7);

	auto terrain5 = Gourd::createGourd(1);
	terrain5->setPosition(Point(920, 260));//牛角旁拐角
	terrain5->setTag(5);
	addChild(terrain5, 8);

	auto terrain11 = Gourd::createGourd(1);
	terrain11->setPosition(Point(530, 220));//圆环旁拐角下
	terrain11->setTag(11);
	addChild(terrain11, 8);

}