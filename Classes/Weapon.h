#ifndef __WEAPON__OBJECT__
#define __WEAPON__OBJECT__
#include "cocos2d.h"
using namespace cocos2d;

float const MOVE_TIME = 1; // time move to 
float const WEAPON_TIME = 2; //time finish weapon move

class Weapon : Sprite
{
public:
	enum Types
	{
		Torch, Axe
	};

	enum LumberDirection
	{
		Left, Right
	};

	Weapon();

	static void update(float dt);
	static void setParent(Node* parent);
	void finishAction();
	LumberDirection mDirection;

private:
	static Node* mParent;
	static float mNextWeaponTime;
	
	Types mType;
};
#endif
