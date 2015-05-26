#ifndef __SAVEFOREST_SCENE_H__
#define __SAVEFOREST_SCENE_H__

#include "cocos2d.h"
#include "Tree.h"
class SaveForest : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
	// update
	virtual void update(float dt);

	bool onContactBegin(const PhysicsContact &physic);
	bool onTouchBegan(Touch *touch, Event *mevent);
	void onTouchMoved(Touch *touch, Event *mevent);
	void onTouchEnded(Touch *touch, Event *mevent);
	bool isGameOver;

	LabelTTF *mlabel;
    
    // implement the "static create()" method manually
	CREATE_FUNC(SaveForest);
};

#endif // __SAVEFOREST_SCENE_H__
