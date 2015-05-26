#ifndef _HIGHTSCORE_SCENE__
#define _HIGHTSCORE_SCENE__

#include "cocos2d.h"
#include "confing.h"
#include "CallBackWP.h"

USING_NS_CC;

class HightScore : public cocos2d::Layer, BackButtonPressed
{
public:
	// there's no 'id' in cpp, so we recommend returning the class instance pointer
	static cocos2d::Scene* createScene(unsigned int _tempScore);

	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();

	void virtual onEnter();
	void setHightScoreKey(unsigned int score);
	CREATE_FUNC(HightScore); 
private:
	
	Size visibleSize;
	Vec2 origin;
	void onBackButtonPressed();
	

};

#endif //_HIGHTSCORE_SCENE__