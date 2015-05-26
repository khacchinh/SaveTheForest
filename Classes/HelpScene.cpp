#include "HelpScene.h"
#include <string>
#include "MenuScene.h"
#include "confing.h"

using namespace std;

USING_NS_CC;
static int key = 0;

Scene* HelpScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = HelpScene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

bool HelpScene::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}

	visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto itemNext = MenuItemSprite::create(Sprite::createWithSpriteFrameName("next.png"),
		Sprite::createWithSpriteFrameName("next.png"),
		CC_CALLBACK_1(HelpScene::onNext, this));
	itemNext->setPosition(visibleSize.width*0.85, visibleSize.height*0.08);

	auto menu = Menu::create(itemNext, NULL);
	menu->setPosition(Point::ZERO);
	this->addChild(menu,1);

	auto itemPrevious = MenuItemSprite::create(Sprite::createWithSpriteFrameName("previous.png"),
		Sprite::createWithSpriteFrameName("previous.png"),
		CC_CALLBACK_1(HelpScene::onPrevious, this));
	itemPrevious->setPosition(visibleSize.width*0.15, visibleSize.height*0.08);
	menu->addChild(itemPrevious);

	return true;
}
void HelpScene::onEnter(){
	Layer::onEnter();

	char str[20] = { 0 };
	for (int i = 0; i <= 5; i++){
		sprintf(str, "ui/help/help%d.png", i);
		auto sprite = Sprite::create(str);
		sprite->setPosition(visibleSize.width*0.5, visibleSize.height*0.5);
		sprite->setVisible(false);
		this->addChild(sprite,0);
		spriteList.pushBack(sprite);
	}
	spriteList.at(key)->setVisible(true);
}
void HelpScene::onNext(Ref *pSender){
	if (key >= 0 && key < 5){
		spriteList.at(key++)->setVisible(false);
		spriteList.at(key)->setVisible(true);
	}
	if (key >= 5)
		key = 5;
}
void HelpScene::onPrevious(Ref* pSender){

	if (key > 0 && key <= 5){
		spriteList.at(key--)->setVisible(false);
		spriteList.at(key)->setVisible(true);
	}
	if (key <= 0)
		key = 0;
}
void HelpScene::onBackButtonPressed(){
	auto scene = MenuScene::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(TIME_TRAN_SCENE, scene));
}