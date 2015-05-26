#include "Weapon.h"

float Weapon::mNextWeaponTime = 0.5f * (rand() % 5 + 4) * 60; // 2 - 4 (* 60 count by frame);
Node* Weapon::mParent = nullptr;

Weapon::Weapon()
{
	if(mParent != nullptr)
	{
		mDirection = (LumberDirection) (rand () % 2);
		mType = (Types)(rand() % 2);

		switch (mType)
		{
		case Weapon::Torch :
			this->initWithFile("Torch.png");
			this->setTag(3);

			break;

		case Weapon::Axe :
			this->initWithFile("Axe.png");
			this->setTag(2);
			break;
		default:
			break;
		}
				
		auto body = PhysicsBody::createBox(this->getContentSize());
		body->setCategoryBitmask(0x0001);
		body->setContactTestBitmask(0x0001);
		body->setCollisionBitmask(0x0001);
			this->setPhysicsBody(body);	
		Weapon::mParent->addChild(this);
		CallFunc *func;
		switch (mDirection)
		{
		case Weapon::Left:
			//attack from left
			func = CallFunc::create(CC_CALLBACK_0(Weapon::finishAction, this));
			this->runAction(Sequence::create(MoveTo::create(rand() % (int)WEAPON_TIME +  2, Vec2(350 + rand()% 100, 480 - rand ()% 100)), func, nullptr));
			break;

		case Weapon::Right:
			this->setPosition(800, 0);
			func = CallFunc::create(CC_CALLBACK_0(Weapon::finishAction, this));
			this->runAction(Sequence::create(MoveTo::create(rand() % (int)WEAPON_TIME +  2, Vec2(350 + rand()% 100, 480 - rand ()% 100)), func, nullptr));
			break;
		}

		this->runAction(RepeatForever::create(RotateBy::create(1, 180)));
	}
}

void Weapon::update(float dt)
{
	if(mNextWeaponTime > 0)
	{
		mNextWeaponTime--;
	}
	else
	{
		mNextWeaponTime = 0.5f * (rand() % 5 + 4) * 60; // 2 - 4 (* 60 count by frame);
		Weapon *weapon = new Weapon();
	}
}

void Weapon::setParent(Node* parent)
{
	mParent = parent;
}

void Weapon::finishAction()
{
	//this->getPhysicsBody()->removeFromWorld();
	this->removeAllChildrenWithCleanup(true);
	this->removeFromParentAndCleanup(true);
}
