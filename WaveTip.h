#pragma once

#include "SystemHeader.h"

USING_NS_CC;
//���ﲨ����ʾ
class WaveTip : public Sprite
{
public:
	virtual bool WaveTipInit();
	CREATE_FUNC(WaveTip);
	static WaveTip* createWaveTip();
	float getWavePercentage();
	void restartWaveTip();

	void stopRespiration();
	void setWavePercentage(float perc);
	ProgressTimer* waveProgressTimer;
	Sprite* selected;
	bool isShown;
	void setSelected();
private:
	//
	float percentage;
	void startRespiration(float dt);
};
