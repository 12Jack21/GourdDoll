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
	//当前关卡
	CC_SYNTHESIZE(int, level, Level);
	//玩家状态栏
	PlayStateLayer* playerState;
	//绑定按键层（按键层兼顾塔的升级菜单层）
	void bindPlayerStateMenu(PlayStateLayer* playerState);
	//地图精灵
	Sprite* mapSprite;
	TouchLayer* mTouchLayer;

protected:
	//初始化触摸层
	void initTouchLayer();
	//本关难度
	int difficulty;
	//当前波数
	int curwave;
	//最大波数
	int maxWave;
	//葫芦
	int gourd;
	int startGourd;

	int life;
	int maxLife;
	unsigned int time;
	//wave怪物容器容器
	//std::vector<std::vector<Vector<GroupMonster*>>> waveVector;

	//加载路径和关卡数据
	void loadPathFromPlist();
	void loadAndSetLevelData();

	//存储路径的容器 从内到外为点，线路，路线
	//std::vector<std::vector<std::vector<Point>>> path;
	//屏幕尺寸
	Size winSize;

	//下一波提示精灵 0为路线1,1为路线2
	Vector<WaveTip*> waveFlags;
	//波数进度条
	void addWaveProgressBar(std::vector<Point> waveTipLocations);
	void showWaveProgressBar(float dt);

	virtual void onEnterTransitionDidFinish();
	//不同关卡不同的事件处理
	virtual void waveEvent();
	//设置初始地图位置
	void setMapPosition();
	//更新葫芦和生命
	void updateGourdAndLife();
	virtual void update(float dt);
	//胜利函数
	void victory();
	//开始标记
	bool isStart;
	//结束标记
	bool isEnd;

	//开始新的一波敌人
	virtual void addWave(float dt);
	//添加怪物
	virtual void addMonster(float dt);
	//初始化地图
	void initMap();
	//添加不同地图装饰物
	virtual void addOrnament() {};
	//添加建塔点
	virtual void addGourds() {};
	//退出
	virtual void onExitTransitionDidStart();
	virtual void onExit() {};
};


