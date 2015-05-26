#ifndef _SPLASH_SCENE__
#define _SPLASH_SCENE__

#include "cocos2d.h"
#include "confing.h"

USING_NS_CC;

class SplashScene : public cocos2d::Layer
{
public:
	// there's no 'id' in cpp, so we recommend returning the class instance pointer
	static cocos2d::Scene* createScene();

	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();

	// implement the "static create()" method manually
	CREATE_FUNC(SplashScene);

	virtual void onEnter();

	void onGo(float dt);
private:
	Size visibleSize;


};

#endif //_SPLASH_SCENE__