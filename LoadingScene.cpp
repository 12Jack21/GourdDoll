#include"LoadingScene.h"

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
	//±³¾°Í¼Æ¬
	auto bg = Sprite::create(".png");

	bg->setPosition(Point(visibleSize.width / 2, visibleSize.height / 2));
	addChild(bg);

	//Òì²½¼ÓÔØÎÆÀí»º´æ
	m_nNumberOfLoaded = 0;
	Director::getInstance()->getTextureCache()->addImageAsync("texture/.png",
		CC_CALLBACK_1(LoadingScene::loadingTextureCallBack, this));
	Director::getInstance()->getTextureCache()->addImageAsync("texture/.png",
		CC_CALLBACK_1(LoadingScene::loadingTextureCallBack, this));
	Director::getInstance()->getTextureCache()->addImageAsync("texture/.png",
		CC_CALLBACK_1(LoadingScene::loadingTextureCallBack, this));

	//Òì²½Ô¤´¦ÀíÉùÒô
	_loadingAudioThread = new std::thread(&LoadingScene::loadingAudio, this);
	return true;
}

void LoadingScene::loadingTextureCallBack(Texture2D* texture)
{
	switch (m_nNumberOfLoaded++)
	{
	case 0:
		SpriteFrameCache::getInstance()->addSpriteFramesWithFile("texture/home_texture.plist", texture);
		log("home texture ok.");
		break;
	case 1:
		SpriteFrameCache::getInstance()->addSpriteFramesWithFile("texture/setting_texture.plist", texture);
		log("setting texture ok.");
		break;
	case 2:
		SpriteFrameCache::getInstance()->addSpriteFramesWithFile("texture/gameplay_texture.plist", texture);
		log("gameplay texture ok.");
		this->schedule(schedule_selector(LoadingScene::delayCall), 1, 1, 3);
		break;
	}
}

void LoadingScene::delayCall(float dt)
{
	auto sc = WelcomeScene::createScene();
	Director::getInstance()->replaceScene(sc);
}

void LoadingScene::loadingAudio()
{
	log("loadAudio");
	//Ô¤´¦Àí ÒôÀÖ
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadBackgroundMusic();
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadBackgroundMusic();
	//Ô¤´¦Àí ÒôÐ§
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect();

}

void LoadingScene::onExit()
{
	Layer::onExit();
	_loadingAudioThread->join();
	CC_SAFE_DELETE(_loadingAudioThread);
	SpriteFrameCache::getInstance()->removeSpriteFramesFromFile("texture/loading_texture.plist");
	Director::getInstance()->getTextureCache()->removeTextureForKey("texture/loading_texture.png");
	this->unschedule(schedule_selector(LoadingScene::delayCall));
}