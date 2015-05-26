#ifndef __PLUMBER__OBJECT__
#define __PLUMBER__OBJECT__

#include "cocos2d.h"
using namespace cocos2d;

float const DISTANCE_WALKIN = 30; // distance from screen edge to.
float const MOVE_TIME = 1; // time move to 
float const WEAPON_TIME = 1; //time finish weapon move



class Lumber : Sprite
{
public:		
	enum  Weapon
	{
		Torch, Axe
	};

	enum LumberDirection
	{
		Left, Right
	};

	Lumber();
	void walkIn(); // move into screen
	void walkOut(); // move out screen
	void attack(); // attack, throw weapon to the tree
	Rect getWeapon(); //get bound of weapon, use to check collision with tree
	void finishAction(); //finish Action when weapon collide or move out screen
	LumberDirection getLumberDirection();

private:
	void setWeaponBody();
	Weapon mweapon;
	LumberDirection direction;
	Sprite *mweaponSprite;
};

#endif