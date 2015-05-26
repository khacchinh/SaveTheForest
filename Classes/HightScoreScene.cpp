#include "HightScoreScene.h"
#include "GlobalObject.h"
#include "MenuScene.h"
USING_NS_CC;

unsigned int score;

Scene* HightScore::createScene(unsigned int _tempScore)
{
	score = _tempScore;
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = HightScore::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

bool HightScore::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}

	visibleSize = Director::getInstance()->getVisibleSize();
	origin = Director::getInstance()->getVisibleOrigin();

	auto sprite = Sprite::create("ui/bg_score.png");
	sprite->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	this->addChild(sprite);
	


}
void HightScore::onEnter(){
	Layer::onEnter();

	this->setHightScoreKey(score);
}

void HightScore::onBackButtonPressed()
{
	auto scene = MenuScene::createScene();
	Director::getInstance()->pushScene(TransitionFade::create(TIME_TRAN_SCENE, scene));
}

void HightScore::setHightScoreKey(unsigned int score){
	bool check = true;
	GlobalObject* globalScore = GlobalObject::getInstance();
	for (int i = 0; i < globalScore->getHightScoreList().size(); i++)
		if (score == globalScore->getHightScoreList().at(i)){
			check = false;
			break;
		}
	if (check)
		globalScore->addNewHigtScore(score);

	char str[50] = { 0 };
	for (int i = globalScore->getHightScoreList().size() - 1; i > 0; i--){
		if (globalScore->getHightScoreList().at(i) != 0){
			sprintf(str, "Score: %d", globalScore->getHightScoreList().at(i));
			auto label = LabelTTF::create(str, "Marker Felt",40);
			label->setPosition(visibleSize.width*0.5, visibleSize.height*0.07*(globalScore->getHightScoreList().size() - 1 - i) + 100);
			this->addChild(label);
		}
	}
	sprintf(str, "Hight Score: %d", globalScore->getHightScoreList().at(0));
	auto label = LabelTTF::create(str, "Marker Felt", 50);
	label->setPosition(visibleSize.width*0.5, visibleSize.height*0.07*(globalScore->getHightScoreList().size() - 1) + 100);
	this->addChild(label);
}
