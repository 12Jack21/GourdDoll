#pragma once
#include"SystemHeader.h"

USING_NS_CC;

class LoadingScene : public Layer
{
private:
	std::thread* _loadingAudioThread;
	void loadingAudio();
	void delayCall(float dt);
	void loadingTextureCallBack(cocos2d::Texture2D* texture);
	//加载纹理图片的个数
	int m_nNumberOfLoaded = 0;
public:
	// there's no 'id' in cpp, so we recommend returning the class instance pointer
	static Scene* createScene();

	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();
	virtual void onExit();

	// implement the "static create()" method manually
	CREATE_FUNC(LoadingScene);

};