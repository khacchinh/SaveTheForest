#include "Lumber.h"

Lumber::Lumber()
{
	mweapon = (Weapon)(rand() % 2);
	direction = (LumberDirection)(rand() % 2);
	
	//init weapon
	switch(mweapon)
	{
		case Weapon::Torch:
			break;

		case Weapon::Axe:
			break;
	}
}

void Lumber::walkIn()
{
	switch (direction)
	{
		case Lumber::Left:
			this->runAction(MoveBy::create(MOVE_TIME, Vec2(DISTANCE_WALKIN, this->getPosition().y)));
			break;

		case Lumber::Right:
			this->runAction(MoveBy::create(MOVE_TIME, Vec2(480 - DISTANCE_WALKIN, this->getPosition().y)));
			break;
	}
}

void Lumber::walkOut()
{
	switch (direction)
	{
		case Lumber::Left:
			this->runAction(MoveBy::create(MOVE_TIME, Vec2(480 - DISTANCE_WALKIN, this->getPosition().y)));
			break;

		case Lumber::Right:
			this->runAction(MoveBy::create(MOVE_TIME, Vec2(DISTANCE_WALKIN, this->getPosition().y)));
			break;
	}
}

void Lumber::attack()
{
	CallFunc *func = CallFunc::create(CC_CALLBACK_0(Lumber::finishAction, this));
	mweaponSprite->runAction(Sequence::create(MoveTo::create(WEAPON_TIME, Vec2(480 - rand ()% 100, 0)), func, nullptr));
}

Rect Lumber::getWeapon()
{
	float width = mweaponSprite->getContentSize().width;
	float height = mweaponSprite->getContentSize().height;
	Vec2 pos = mweaponSprite->getPosition();

	return Rect(pos.x, pos.y, width, height);
}

void Lumber::finishAction()
{
	mweaponSprite->removeFromParentAndCleanup(true);
	this->removeFromParentAndCleanup(true);
}

void Lumber::setWeaponBody()
{
	PhysicsBody *body = PhysicsBody::createBox(mweaponSprite->getContentSize(), PHYSICSBODY_MATERIAL_DEFAULT);
	body->setCategoryBitmask(0x0001);
	body->setContactTestBitmask(0x0001);
	body->setCollisionBitmask(0x0001);
	mweaponSprite->setPhysicsBody(body);
}

Lumber::LumberDirection Lumber::getLumberDirection()
{
	return direction;
}