#ifndef _HELP_SCENE__
#define _HELP_SCENE__

#include "cocos2d.h"
#include "CallBackWP.h"

USING_NS_CC;

class HelpScene : public cocos2d::Layer, BackButtonPressed
{
public:
	// there's no 'id' in cpp, so we recommend returning the class instance pointer
	static cocos2d::Scene* createScene();

	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();

	// implement the "static create()" method manually
	CREATE_FUNC(HelpScene);

	virtual void onEnter();

	void onGo(float dt);
private:
	Size visibleSize;
	Vector<Sprite*> spriteList;
	void onNext(Ref* pSender);
	void onPrevious(Ref* pSender);
	void onBackButtonPressed();


};

#endif //_HELP_SCENE__