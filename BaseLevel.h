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
	PlayStateLayer* playState;
	//����Ϸ״̬�㣨�����������������˵��㣩
	void bindPlayState(PlayStateLayer* playerState);
	//��Ƭ��ͼ
	TMXTiledMap* tiledMap;
	//������
	TouchLayer* mTouchLayer;

protected:
	//��ʼ��������
	void initTouchLayer();
	//�����Ѷ�
	int difficulty;
	//��ǰ����
	int curWave;

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
	
	//�洢·�������� ���ڵ���Ϊ�㣬��·��·��
	//std::vector<std::vector<std::vector<Point>>> path;
	
	//����·���͹ؿ�����
	void loadPathFromPlist();
	void loadAndSetLevelData();

	//��Ļ�ߴ�
	Size winSize;

	//��һ����ʾ���� 0Ϊ·��1,1Ϊ·��2

	Vector<WaveTip*> waveTips;

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
	void gameWin();

	//��ʼ���
	bool isStart;
	//�������
	bool isEnd;

	//��ʼ�µ�һ������
	virtual void addWaves(float dt);
	//��ӹ���
	virtual void addMonsters(float dt);
	//��ʼ����ͼ
	void initMap();
	//��Ӳ�ͬ��ͼװ����
	virtual void addOrnament() {};

				//��Ӻ�«
	virtual void addGourds() {};
	
	//�˳�
	virtual void onExitTransitionDidStart();
	virtual void onExit() {};
};


