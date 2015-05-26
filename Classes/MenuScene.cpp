#include "MenuScene.h"
#include "HightScoreScene.h"
#include "GlobalObject.h"
#include "HelpScene.h"
#include "SaveForestScene.h"

USING_NS_CC;

Scene* MenuScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = MenuScene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

bool MenuScene::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}
	//PlatformCenter::callFunc("portrait");
	check = true;
	visibleSize = Director::getInstance()->getVisibleSize();
	origin = Director::getInstance()->getVisibleOrigin();

	//create layer setting
	layerSetting = Layer::create();
	layerSetting->setPosition(visibleSize.width*0.12f, visibleSize.height*0.08f);
	auto bg = Sprite::create("ui/bg_mute.png");
	bg->setScale(0.4f);
	bg->setPosition(layerSetting->getPositionX(), layerSetting->getPositionY());
	layerSetting->addChild(bg);
	layerSetting->setVisible(false);
	this->addChild(layerSetting, LOCAL_ZODER_MENU);

	//button volume
	auto item1 = MenuItemSprite::create(Sprite::createWithSpriteFrameName("volume.png"), Sprite::createWithSpriteFrameName("volume.png"), NULL);
	auto item2 = MenuItemSprite::create(Sprite::createWithSpriteFrameName("volume_1.png"), Sprite::createWithSpriteFrameName("volume_1.png"), NULL);
	item_setting = MenuItemToggle::createWithTarget(this, menu_selector(MenuScene::onVolume), item1, item2,NULL);
	item_setting->setPosition(bg->getPositionX() , bg->getPositionY()+10);
	item_setting->setScale(0.6);
	auto menu1 = Menu::create(item_setting, NULL);
	menu1->setPosition(Point::ZERO);
	layerSetting->addChild(menu1);




	return true;


}

void MenuScene::onEnter(){
	Layer::onEnter();

	//create background
	auto sprite = Sprite::create("ui/background-main.png");
	sprite->setPosition(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y);
	this->addChild(sprite, LOCAL_ZODER_BACKGROUND);

	//create foreground
	foreground_earth = Sprite::createWithSpriteFrameName("earth.png");
	foreground_earth->setPosition(visibleSize.width *0.5f, visibleSize.height*0.4f);
	foreground_earth->setScale(0.38f);
	this->addChild(foreground_earth, LOCAL_ZODER_FOREGROUND);

	//button click share
	item_share = MenuItemSprite::create(Sprite::createWithSpriteFrameName("wind.png"),
		Sprite::createWithSpriteFrameName("wind.png"),
		CC_CALLBACK_1(MenuScene::goShare, this));
	item_share->setPosition(visibleSize.width*0.8f, visibleSize.height*0.7f);
	item_share->setScale(0.4f);
	item_share->setRotation(30);
	Point posBack = item_share->getPosition();
	auto actionDown = MoveTo::create(2, Point(item_share->getPositionX() + 30, item_share->getPositionY() - 30));
	auto actionUp = MoveTo::create(2, Point(posBack.x, posBack.y));
	auto actionShare = Sequence::create(actionDown, actionUp, NULL);
	item_share->runAction(RepeatForever::create(actionShare));
	menu = Menu::create(item_share, NULL);
	menu->setPosition(Point::ZERO);
	

	//button click hight score
	item_hightscore = MenuItemSprite::create(Sprite::createWithSpriteFrameName("cloud.png"),
		Sprite::createWithSpriteFrameName("cloud.png"),
		CC_CALLBACK_1(MenuScene::goHightScore, this));
	item_hightscore->setPosition(visibleSize.width*0.18f, visibleSize.height*0.7f);
	item_hightscore->setScale(0.15f);
	item_hightscore->setRotation(-30);
	menu->addChild(item_hightscore);

	//button click go play
	item_main = MenuItemSprite::create(Sprite::createWithSpriteFrameName("play.png"),
		Sprite::createWithSpriteFrameName("play_1.png"),
		CC_CALLBACK_1(MenuScene::goMainScene, this));
	item_main->setPosition(visibleSize.width*0.5, visibleSize.height*0.8);

	menu->addChild(item_main);

	this->addChild(menu, LOCAL_ZODER_MENU);

	//create animate
	cricle = Sprite::createWithSpriteFrameName("sun-light.png");
	cricle->setPosition(item_main->getPositionX()+item_main->getBoundingBox().size.width*0.35, item_main-> getPositionY());
	cricle->setScale(0.2f);
	auto action = RotateBy::create(4, 360);
	cricle->runAction(RepeatForever::create(action));
	this->addChild(cricle, LOCAL_ZODER_FOREGROUND);

	//create lightning
	lightning = Sprite::createWithSpriteFrameName("flash0.png");
	lightning->setPosition(item_hightscore->getPositionX()+item_hightscore->getBoundingBox().size.width/3, item_hightscore->getPositionY() - item_hightscore->getBoundingBox().size.height*0.26);
	lightning->setScale(0.21f);
	lightning->setRotation(-50);
	lightning->runAction(actionFlash());
	this->addChild(lightning, LOCAL_ZODER_FOREGROUND);

	item_help = MenuItemSprite::create(Sprite::createWithSpriteFrameName("help.png"),
		Sprite::createWithSpriteFrameName("help.png"), CC_CALLBACK_1(MenuScene::onHelp, this));
	item_help->setPosition(visibleSize.width*0.85, visibleSize.height*0.08);
	item_help->setScale(0.8f);
	menu->addChild(item_help);

	auto item_set = MenuItemSprite::create(Sprite::createWithSpriteFrameName("setting.png"), Sprite::createWithSpriteFrameName("setting.png"), CC_CALLBACK_1(MenuScene::onMute, this));
	item_set->setPosition(visibleSize.width*0.15, visibleSize.height*0.08);
	item_set->setScale(0.8f);
	menu->addChild(item_set);
}

void MenuScene::goShare(Ref* pSender){
	string s = "sharefacebook+" + to_string(14);
	wstring wstr;
	wstr.assign(s.begin(), s.end());
	wstr.c_str();
	PlatformCenter::callFunc(ref new Platform::String(wstr.c_str()));
}
void MenuScene::goHightScore(Ref* pSender){
	auto scene = HightScore::createScene(50);
	Director::getInstance()->replaceScene(TransitionFade::create(TIME_TRAN_SCENE, scene));
}
void MenuScene::goMainScene(Ref* pSender){
	PlatformCenter::callFunc("landscape");
	auto scene = SaveForest::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(TIME_TRAN_SCENE, scene));
}
RepeatForever* MenuScene::actionFlash(){
	Vector<SpriteFrame*> animaframe(10);

	char str[20] = { 0 };
	for (int i = 0; i <= 4; i++){
		sprintf(str, "flash%d.png", i);
		auto frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(str);
		animaframe.pushBack(frame);
	}

	auto animation = Animation::createWithSpriteFrames(animaframe, 0.2f);
	Animate *animate = Animate::create(animation);
	return RepeatForever::create(animate);
}

void MenuScene::onBackButtonPressed(){
	Director::getInstance()->end();
	GlobalObject::getInstance()->destroy();
}
void MenuScene::onHelp(Ref* pSender){
	auto scene = HelpScene::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(TIME_TRAN_SCENE, scene));
}

void MenuScene::onVolume(Ref* pSender){

}
void MenuScene::onMute(Ref* pSender)
{
	if (check){
		layerSetting->setVisible(true);
		check = false;
	}
	else{
		layerSetting->setVisible(false);
		check = true;
	}

}