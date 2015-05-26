#include "Tree.h"
USING_NS_CC;

Tree* Tree::mInstance = nullptr;
void Tree::addToParent(Node* parent)
{	

		parent -> addChild( mLeavesSprite);
		mLeavesSprite->setTag(1);
		PhysicsBody* mLeavesBody = PhysicsBody::createCircle(mLeavesSize.width / 4, PHYSICSBODY_MATERIAL_DEFAULT);
		
		mLeavesBody->setContactTestBitmask(1);
		mLeavesBody->setCollisionBitmask(0);
		mLeavesBody->setCategoryBitmask(1);
		mLeavesNode -> setPhysicsBody( mLeavesBody);
		parent->addChild(mLeavesNode);
		mLeavesNode->setPosition(mLeavesPosition);

		parent -> addChild( mBodySprite);
		mBodySprite->setTag(1);
		PhysicsBody* mBodyBody = PhysicsBody::createBox(mBodySize, PHYSICSBODY_MATERIAL_DEFAULT);
		mBodyBody->setContactTestBitmask(1);
		mBodyBody->setCollisionBitmask(0);
		mBodyBody->setCategoryBitmask(1);
		mBodyNode -> setPhysicsBody( mBodyBody);
		parent->addChild(mBodyNode);
		mBodyNode->setPosition(mPosition);

		parent -> addChild( mRootSprite);

		mLeavesSprite->setAnchorPoint(Vec2(0.5, -0.8));
		mBodySprite -> setAnchorPoint(Vec2(0.5, 0));
		
		mBodySprite -> setPosition(Vec2(mBodyPosition.x, mBodyPosition.y - mBodySprite->getContentSize().height / 2));
		mLeavesSprite -> setPosition(mBodySprite->getPosition());
		Rotation();
		
}

void Tree:: Rotation()
{
	mLeavesSprite -> setRotation(mAnpha);
	mBodySprite -> setRotation(mAnpha);

	mBodyNode->getPhysicsBody()->setRotationOffset(mAnpha);
	mBodyNode->setPosition(mPosition.x + (mBodySprite ->getContentSize().height / 2)*( sin ((mAnpha) * 3.14 / 180)), mBodySprite->getPosition().y + (mBodySprite ->getContentSize().height / 2) * (cos ( (mAnpha) * 3.14 / 180)));

	mLeavesNode ->getPhysicsBody()->setRotationOffset(mAnpha);
	mLeavesNode->setPosition(mPosition.x + (mLeavesSprite->getContentSize().height / 2 + mBodySprite ->getContentSize().height)*( sin ((mAnpha) * 3.14 / 180)), mBodySprite->getPosition().y + (mLeavesSprite->getContentSize().height / 2 + mBodySprite ->getContentSize().height ) * (cos ( (mAnpha) * 3.14 / 180)));
	/*mBodyNode->getPhysicsBody()->setRotationOffset(mAnpha);
	mBodyNode->setPosition(mPosition.x + (75)*( sin ((mAnpha) * 3.14 / 180)), 127.5 + (75) * (cos ( (mAnpha) * 3.14 / 180)));

	mLeavesNode ->getPhysicsBody()->setRotationOffset(mAnpha);
	mLeavesNode->setPosition(mPosition.x + (75 + 150)*( sin ((mAnpha) * 3.14 / 180)), 127.5 + (75 + 150) * (cos ( (mAnpha) * 3.14 / 180)));*/
}
		
Tree::~Tree()
{
	return;
	if(mInstance != nullptr)
		{
			delete mInstance;
			mInstance = nullptr;
		}
		if(mLeavesSprite)
		{
			mLeavesSprite -> autorelease();
			mLeavesSprite = nullptr;
		}

		if(mBodySprite)
		{
			mBodySprite -> autorelease(); 
			mBodySprite = nullptr;
		}
		if(mRootSprite)
		{
			mRootSprite -> autorelease();
			mRootSprite = nullptr;
		}
}
void Tree::checkTouches(Vec2 touch)
{
	if(touch.x < 400)
		mIsTouch = 1; //touch on left
	else
		mIsTouch = -1; //touch on right
}
