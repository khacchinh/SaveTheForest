#ifndef __WIND__OBJECT__
#define __WIND__OBJECT__
#include "cocos2d.h"
using namespace cocos2d;

float const WIND_RANDNEXTTIME_STEP = 0.5f;
float const WIND_RANDSTRENGTH_STEP = 0.5f;
float const WIND_RANDTIME_STEP = 0.5f;

class Wind : Sprite
{
public:
	enum Direction
	{
		Left, Right
	};

	Direction getDirection();
	static Wind* getInstance();
	float getNextWindTime();
	float getWindTime();
	float getStrength();
	bool isRunning();
	void update(float dt); 
	int mCountTime;
	int getEffectTime()
	{
		return mEffectTime;
	}	

private:
	Wind();
	float mwindTime, mstrength, mnextWindTime;
	bool misRunning;
	static Wind* minstance;
	const int mEffectTime;
	Direction mDirection;
};
#endif
