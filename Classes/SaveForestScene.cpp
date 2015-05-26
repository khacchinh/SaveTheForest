#include "SaveForestScene.h"
#include "Wind.h"
#include "HightScoreScene.h"
#include "Weapon.h"
USING_NS_CC;

Scene* SaveForest::createScene()
{
    // 'scene' is an autorelease object
	auto scene = Scene::createWithPhysics();
	scene->getPhysicsWorld()->setGravity(Vec2::ZERO);
    // 'layer' is an autorelease object
	auto layer = SaveForest::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool SaveForest::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    srand(time(NULL));
	isGameOver = false;
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto background = Sprite::create("map.png");
	background->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	this->addChild(background);

	Tree::getInstance()->addToParent(this);

	mlabel = LabelTTF::create("", "Marker Felt", 15);
	mlabel->setPosition(Vec2(visibleSize.width / 2 - 100, visibleSize.height / 2));
	mlabel->setColor(Color3B(0,0,0));
	this->addChild(mlabel);
	Weapon::setParent(this);


	// Update
	this->schedule( schedule_selector(SaveForest::update), 1.0f / 60);

	auto contactListener = EventListenerPhysicsContact::create();
	contactListener->onContactBegin = CC_CALLBACK_1(SaveForest::onContactBegin, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(contactListener, this);
	
	auto touchListener = EventListenerTouchOneByOne::create();
	touchListener->onTouchBegan = CC_CALLBACK_2(SaveForest::onTouchBegan, this);
	touchListener->onTouchMoved = CC_CALLBACK_2(SaveForest::onTouchMoved, this);
	touchListener->onTouchEnded = CC_CALLBACK_2(SaveForest::onTouchEnded, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);

    return true;
}


void SaveForest::update(float dt)
{	
	if(!isGameOver)
	{
		Tree::getInstance()->mScore++;
		float deltaAnpha = 0;

		Tree::getInstance()->mVelocity = sqrt( Tree::getInstance()->getOmega() * abs(Tree::getInstance()->getAnpha())) * (Tree::getInstance()->getAnpha()) / abs(Tree::getInstance()->getAnpha());

		mlabel->setString(StringUtils::format("deltaalpha: %3.3f \nalpha: %3.3f \ncount %d \nistouch: %d \nstrength: %3.3f \nwindtime: %3.3f \nmCountTime: %3.3d", deltaAnpha, Tree::getInstance()->getAnpha(), Tree::getInstance()->count, Tree::getInstance()->mIsTouch, Wind::getInstance()->getStrength(), Wind::getInstance()->getWindTime(), Wind::getInstance()->mCountTime));

		if ( Tree::getInstance()->mIsTouch != 0 ) 
		{
			Tree::getInstance()->mVelocity += (Tree::getInstance()->mIsTouch)*Tree::getInstance()->getAddedAnphaTouch();
			Tree::getInstance()-> count = 0;
			Tree::getInstance()->mIsTouch = 0;
		}
		else
		{
			Tree::getInstance() -> count++;
		}



		if (Wind::getInstance()->isRunning() )
		{
			Wind::getInstance()->mCountTime++;
			Wind::getInstance()->mCountTime %= Wind::getInstance()->getEffectTime();

			if(Wind::getInstance()->mCountTime >= Wind::getInstance()->getEffectTime() - 1)
			{
				Tree::getInstance()->setAddedAnphaWind(Wind::getInstance()->getStrength());
			}
			else
			{
				Tree::getInstance()->setAddedAnphaWind(0);
			}
		}
		else
		{
			Wind::getInstance()->mCountTime = 0;
			Tree::getInstance()->setAddedAnphaWind(0);
		}

		Tree::getInstance()->mVelocity += Tree::getInstance()->getmAddedAnphaWind();
		deltaAnpha += Tree::getInstance()->mVelocity;
		Tree::getInstance()->setAnpha(Tree::getInstance()->getAnpha() + deltaAnpha);

		if( abs(Tree::getInstance()->getAnpha()) >= 60)
		{
			//chuyen scene cho qua game over 
			/* auto scene = HightScore::createScene();
			Director::getInstance()->replaceScene(HightScore*/
		}
		Tree::getInstance()->Rotation();
		Weapon::update(dt);
		Wind::getInstance()->update(dt);
		if(abs(Tree::getInstance()->getAnpha()) >=  Tree::getInstance()->mMaxAlphaValue)
		{
			isGameOver = true;
		}
	}
	else
	{


		if((abs(Tree::getInstance()->getAnpha()) <=  Tree::getInstance()->mGameOVerAlphaValue))
		{
			float deltaAnpha = 0;
			Tree::getInstance()->mVelocity = sqrt( Tree::getInstance()->getOmega() * abs(Tree::getInstance()->getAnpha())) * (Tree::getInstance()->getAnpha()) / abs(Tree::getInstance()->getAnpha());
			 deltaAnpha += Tree::getInstance()->mVelocity;
			Tree::getInstance()->setAnpha(Tree::getInstance()->getAnpha() + deltaAnpha);
			Tree::getInstance()->Rotation();
		}
		else
		{
			PlatformCenter::callFunc("portrait"); 
			Director::getInstance()->replaceScene(HightScore::createScene((int)(Tree::getInstance()->mScore / 60)));
		}			
	}

	
}

bool SaveForest::onTouchBegan(Touch *touch, Event *mevent)
{
	Tree::getInstance()->checkTouches(touch->getLocation());

	return true;
}

void SaveForest::onTouchMoved(Touch *touch, Event *mevent)
{

}

void SaveForest::onTouchEnded(Touch *touch, Event *mevent)
{

}

bool SaveForest::onContactBegin(const PhysicsContact &physic)
{
	auto spriteA = (Sprite*)physic.getShapeA()->getBody()->getNode();
	auto spriteB = (Sprite*)physic.getShapeB()->getBody()->getNode();
	isGameOver = true;
	return true;
	
}

void SaveForest::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif

    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
