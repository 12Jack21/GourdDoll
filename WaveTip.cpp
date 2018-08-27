#include "WaveTip.h"

WaveTip* WaveTip::createWaveTip()
{
	auto waveFlag = new WaveTip();

	if (waveFlag && waveFlag->WaveTipInit())
	{
		waveFlag->autorelease();
		return waveFlag;
	}
	CC_SAFE_DELETE(waveFlag);
	return NULL;
}

bool WaveTip::WaveTipInit()
{
	if (!Sprite::init())
	{
		return false;
	}
	waveProgressTimer = ProgressTimer::create(Sprite::createWithSpriteFrameName("waveFlag_0003.png"));
	waveProgressTimer->setType(ProgressTimer::Type::RADIAL);
	auto flag = Sprite::createWithSpriteFrameName("waveFlag_0001.png");
	flag->setPosition(Point(waveProgressTimer->getContentSize().width / 2, waveProgressTimer->getContentSize().height / 2));
	selected = Sprite::createWithSpriteFrameName("waveFlag_selected.png");
	selected->setPosition(Point(waveProgressTimer->getContentSize().width / 2, waveProgressTimer->getContentSize().height / 2));
	waveProgressTimer->addChild(flag);
	waveProgressTimer->addChild(selected);
	selected->setVisible(false);
	addChild(waveProgressTimer);
	setScale(0.8f);
	setVisible(false);
	isShown = false;
	return true;
}

//开始计时
void WaveTip::startRespiration(float dt)
{
	waveProgressTimer->setPercentage(percentage);
	runAction(Sequence::create(ScaleTo::create(0.25f, 0.6f, 0.6f), ScaleTo::create(0.25f, 0.8f, 0.8f), NULL));
	percentage = percentage + 2.5f;
	if (percentage >100) {
		isShown = false;
		setVisible(false);
		unschedule(schedule_selector(WaveTip::startRespiration));
	}
}

void WaveTip::stopRespiration()
{
	waveProgressTimer->setPercentage(100);
	isShown = false;
	setVisible(false);
	unschedule(schedule_selector(WaveTip::startRespiration));
}

void WaveTip::restartWaveTip()
{
	isShown = true;
	setVisible(true);
	waveProgressTimer->setPercentage(0);
	percentage = 0;
	schedule(schedule_selector(WaveTip::startRespiration), 0.5f);
}

float WaveTip::getWavePercentage()
{
	return waveProgressTimer->getPercentage();
}

void WaveTip::setWavePercentage(float per)
{
	waveProgressTimer->setPercentage(per);
}

void WaveTip::setSelected()
{
	if (selected->isVisible()) 
	{
		selected->setVisible(false);
	}
	else 
	{
		selected->setVisible(true);
	}
}

