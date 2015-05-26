#ifndef _MENU_SCENE__
#define _MENU_SCENE__

#include "cocos2d.h"
#include "CallBackWP.h"

USING_NS_CC;

class MenuScene : public cocos2d::Layer, BackButtonPressed
{
public:
	// there's no 'id' in cpp, so we recommend returning the class instance pointer
	static cocos2d::Scene* createScene();

	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();

	virtual void onEnter();

	// implement the "static create()" method manually
	CREATE_FUNC(MenuScene);
private:
	bool check;
	Size visibleSize;
	Vec2 origin;
	Sprite* foreground_earth;
	MenuItemSprite* item_share;
	MenuItemSprite* item_hightscore;
	MenuItemSprite* item_main;
	MenuItemToggle* item_setting;
	MenuItemSprite* item_help;
	Sprite* cricle;
	Sprite* lightning;
	Menu * menu;

	//
	void goShare(Ref* pSender);
	void goMainScene(Ref* pSender);
	void goHightScore(Ref* pSender);
	void onBackButtonPressed();
	void onHelp(Ref* pSender);
	void onVolume(Ref* pSender);
	void onMute(Ref* pSender);
	RepeatForever* actionFlash();

	Layer* layerSetting;
};

#endif //_MENU_SCENE__