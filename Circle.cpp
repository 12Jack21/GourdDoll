#include "Circle.h"

bool Circle::init()
{
	if (!Sprite::init())
	{
		return false;
	}

	auto circle1 = Sprite::createWithSpriteFrameName("range_circle.png");
	auto circle2 = Sprite::createWithSpriteFrameName("range_circle.png");
	auto circle3 = Sprite::createWithSpriteFrameName("range_circle.png");
	auto circle4 = Sprite::createWithSpriteFrameName("range_circle.png");
	circle1->setAnchorPoint(Point(1, 0));

	circle1->setScaleX(1.25f);
	circle2->setScaleX(1.25f);
	circle3->setScaleX(1.25f);
	circle4->setScaleX(1.25f);

	circle2->setFlippedX(true);
	circle2->setAnchorPoint(Point(0, 0));
	circle3->setFlippedX(true);
	circle3->setFlippedY(true);
	circle3->setAnchorPoint(Point(0, 1));
	circle4->setFlippedY(true);
	circle4->setAnchorPoint(Point(1, 1));

	addChild(circle1);
	addChild(circle2);
	addChild(circle3);
	addChild(circle4);

	return true;
}