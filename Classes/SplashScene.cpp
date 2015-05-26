#include "SplashScene.h"
#include "MenuScene.h"

USING_NS_CC;

Scene* SplashScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = SplashScene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

bool SplashScene::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}

	visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	this->scheduleOnce(schedule_selector(SplashScene::onGo), 1);
	return true;
}

void SplashScene::onEnter(){
	Layer::onEnter();

	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("ui/Menu.plist");

	auto sprite = Sprite::create("ui/bg_waitting.png");
	sprite->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	this->addChild(sprite);
}

void SplashScene::onGo(float dt){
	auto scene = MenuScene::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(TIME_TRAN_SCENE, scene));
}