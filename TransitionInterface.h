#pragma once
#include"SystemHeader.h"
#include"WelcomeScene.h"
#include"AboutScene.h"

class TransitionInterface :public TransitionScene
{
public:

	void onEnter();
	static TransitionInterface* create(float t, Scene* scene);
	//static TransitionInterface* createWithRenderTexture(float t, Scene* scene, RenderTexture* sqr);
private:
	//void initRenderTexture(RenderTexture* sqr);

	//�����������ʱ����
	void OnEnterDidFinish();
private:

};
