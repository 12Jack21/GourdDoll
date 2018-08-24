#pragma once

#include "PlaystateLayer.h"
#include "SystemHeader.h"
#include "WaveTip.h"
#include "TouchLayer.h"

USING_NS_CC;

class BaseLevel : public Layer
{
public:
	CREATE_FUNC(BaseLevel);
	//��ǰ�ؿ�
	CC_SYNTHESIZE(int, level, Level);
	//���״̬��
	PlayStateLayer* playerState;
	//�󶨰����㣨�����������������˵��㣩
	void bindPlayerStateMenu(PlayStateLayer* playerState);
	//��ͼ����
	Sprite* mapSprite;
	TouchLayer* mTouchLayer;

protected:
	//��ʼ��������
	void initTouchLayer();
	//�����Ѷ�
	int difficulty;
	//��ǰ����
	int curwave;
	//�����
	int maxWave;
	//��«
	int gourd;
	int startGourd;

	int life;
	int maxLife;
	unsigned int time;
	//wave������������
	//std::vector<std::vector<Vector<GroupMonster*>>> waveVector;

	//����·���͹ؿ�����
	void loadPathFromPlist();
	void loadAndSetLevelData();

	//�洢·�������� ���ڵ���Ϊ�㣬��·��·��
	//std::vector<std::vector<std::vector<Point>>> path;
	//��Ļ�ߴ�
	Size winSize;

	//��һ����ʾ���� 0Ϊ·��1,1Ϊ·��2
	Vector<WaveTip*> waveFlags;
	//����������
	void addWaveProgressBar(std::vector<Point> waveTipLocations);
	void showWaveProgressBar(float dt);

	virtual void onEnterTransitionDidFinish();
	//��ͬ�ؿ���ͬ���¼�����
	virtual void waveEvent();
	//���ó�ʼ��ͼλ��
	void setMapPosition();
	//���º�«������
	void updateGourdAndLife();
	virtual void update(float dt);
	//ʤ������
	void victory();
	//��ʼ���
	bool isStart;
	//�������
	bool isEnd;

	//��ʼ�µ�һ������
	virtual void addWave(float dt);
	//��ӹ���
	virtual void addMonster(float dt);
	//��ʼ����ͼ
	void initMap();
	//��Ӳ�ͬ��ͼװ����
	virtual void addOrnament() {};
	//��ӽ�����
	virtual void addGourds() {};
	//�˳�
	virtual void onExitTransitionDidStart();
	virtual void onExit() {};
};


