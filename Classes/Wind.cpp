#include "Wind.h"

Wind* Wind::minstance = nullptr;

Wind::Wind()
	:
	mEffectTime(60),
	mCountTime(0)
{
	mwindTime = 0;
	mnextWindTime = WIND_RANDNEXTTIME_STEP * (rand() % 5 + 4) * 60; // 2 - 4 (* 60 count by frame)
	mstrength =  WIND_RANDSTRENGTH_STEP * (rand() % 8 + 3); //rand from 1.5 to 5 step: 0.5f, wind strength
}

Wind* Wind::getInstance()
{
	if(minstance == nullptr)
		minstance = new Wind();

	return minstance;
}

float Wind::getNextWindTime()
{
	return mnextWindTime;
}

float Wind::getStrength()
{
	return mstrength;
}

float Wind::getWindTime()
{
	return mwindTime;
}

bool Wind::isRunning()
{
	return misRunning;
}

Wind::Direction Wind::getDirection()
{
	return mDirection;
}

void Wind::update(float dt)
{
	if(mwindTime == 0)
	{
		mstrength = 0;
		misRunning = false; // dont have any wind
		//count to next wind
		if(mnextWindTime == 0)
		{
			//init next wind time
			mnextWindTime = WIND_RANDNEXTTIME_STEP * (rand() % 5 + 4) * 60; // 2 - 4 (* 60 count by frame)
			mDirection = (Direction)(rand() % 2);	
		}
		else
		{
			mnextWindTime--;

			if(mnextWindTime == 0)
			{
				mwindTime = WIND_RANDTIME_STEP * (rand() % 9 + 2) * 60; // 1- 5 s 
				int val;

				switch (mDirection)
				{
					case Wind::Left:
					mstrength =  WIND_RANDSTRENGTH_STEP * (rand() % 8 + 10);
					break;

					case Wind::Right:
					mstrength =  -WIND_RANDSTRENGTH_STEP * (rand() % 8 + 10);
					break;
				}			
			}
		}			
	}
	else
	{
		misRunning = true; // wind is running
		mwindTime--;
	}
}