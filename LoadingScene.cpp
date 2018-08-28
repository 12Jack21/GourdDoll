#include"LoadingScene.h"
#include"WelcomeScene.h"

using namespace CocosDenshion;

Scene* LoadingScene::createScene()
{
	Scene* scene = Scene::create();
	Layer* layer = LoadingScene::create();
	scene->addChild(layer);
	return scene;
}

bool LoadingScene::init()
{
	if (!Layer::init())
	{
		return false;
	}
	auto visibleSize = Director::getInstance()->getVisibleSize();
	//背景图片
	auto bg = Sprite::create("my/LoadingScene.jpg");

	bg->setPosition(Point(visibleSize.width / 2, visibleSize.height / 2));
	addChild(bg);

	//异步加载纹理缓存
	m_nNumberOfLoaded = 0;
	Director::getInstance()->getTextureCache()->addImageAsync("WelcomeScene.png",
		CC_CALLBACK_1(LoadingScene::loadingTextureCallBack, this));
	Director::getInstance()->getTextureCache()->addImageAsync("AboutScene.png",
		CC_CALLBACK_1(LoadingScene::loadingTextureCallBack, this));
	Director::getInstance()->getTextureCache()->addImageAsync("LevelView.png",
		CC_CALLBACK_1(LoadingScene::loadingTextureCallBack, this));
	Director::getInstance()->getTextureCache()->addImageAsync("TransitionInterface.png",
		CC_CALLBACK_1(LoadingScene::loadingTextureCallBack, this));

	////异步预处理声音
	//_loadingAudioThread = new std::thread(&LoadingScene::loadingAudio, this);

	return true;
}

void LoadingScene::loadingTextureCallBack(Texture2D* texture)
{
	switch (m_nNumberOfLoaded++)
	{
	case 0:
		SpriteFrameCache::getInstance()->addSpriteFramesWithFile("WelcomeScene.plist", texture);
		log("Welcome texture ok.");

		break;
	case 1:
		SpriteFrameCache::getInstance()->addSpriteFramesWithFile("AboutScene.plist", texture);
		log("About texture ok.");

		break;
	case 2:
		SpriteFrameCache::getInstance()->addSpriteFramesWithFile("LevelView.plist", texture);
		log("Level texture ok.");

		break;
	case 3:
		SpriteFrameCache::getInstance()->addSpriteFramesWithFile("TransitionInterface.plist", texture);
		log("Transition texture ok.");
		this->schedule(schedule_selector(LoadingScene::delayCall), 1, 1, 1);
		break;
	}
}

void LoadingScene::delayCall(float dt)
{
	auto sc = WelcomeScene::createScene();

	//消失转场切换
	auto transScene = TransitionFade::create(1.0f, sc);
	Director::getInstance()->replaceScene(transScene);
}

void LoadingScene::loadingAudio()
{
	log("loadAudio");
	//预处理 音乐
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadBackgroundMusic("");
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadBackgroundMusic("");
	//预处理 音效
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("");

}

void LoadingScene::onExit()
{
	Layer::onExit();
	//_loadingAudioThread->join();
	//CC_SAFE_DELETE(_loadingAudioThread);
	//SpriteFrameCache::getInstance()->removeSpriteFramesFromFile("texture/loading_texture.plist");
	//Director::getInstance()->getTextureCache()->removeTextureForKey("texture/loading_texture.png");
	this->unschedule(schedule_selector(LoadingScene::delayCall));
}