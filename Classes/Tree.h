
#ifndef _TREE_H_
#define	_TREE_H_
#include "cocos2d.h"
USING_NS_CC;
class Tree
{

public:
	static Tree* getInstance()
	{
			if(mInstance != nullptr)
		{
				return mInstance;
		}
			else
		{
				mInstance = new Tree();
		}
		
	}

	~Tree();
	
	void Rotation();
	void addToParent(Node* parent);
	void setAddedVelocityWind(float val)
	{
		mAddedVelocityWind = val;
	}
	float getAnpha()
	{
		return mAnpha;
	}
	void setAnpha(float val)
	{
		mAnpha = val;
	}
	int count;
	int mIsTouch;
	bool getIsWindRunning()
	{
		return mIsWindrunning;
	}
	float getOmega()
	{
		return mOmega;
	}
	
	void checkTouches(Vec2 touch);
	float getAddedAnphaTouch()
	{
		return mAddedAnphaTouch;
	}
	void setIsWindRunning(bool val)
	{
		mIsWindrunning = val;
	}
	void setAddedAnphaWind(float val)
	{
		mAddedAnphaWind = val;
	}
	float getmAddedAnphaWind()
	{
		return mAddedAnphaWind;
	}
	float getAddedVelocityCollision()
	{
		return mAddedVelocityCollision;
	}

	int mScore;
	Point mBodyPosition;
	Point mLeavesPosition;
	Node* mBodyNode;
	Node* mLeavesNode;
	float mVelocity;
	const float mMaxAlphaValue;
	const float mGameOVerAlphaValue;
	 

private:
		Tree() :
		mPosition(410, 150 ),
		mLeavesSize( 250 , 150),
		mBodySize (50 , 120 ),
		mRootSize ( 150, 120 ),
		mAddedAnphaTouch(8),
		mAddedVelocityCollision(10),
		mOmega(0.01),
		mAddedAnphaWind(0.0f),
		mVelocity(0.0f),
		mMaxAlphaValue(60),
		mGameOVerAlphaValue(100),
		mScore(0)
		{
			mAnpha = 0.1;
			mDeltaAnpha = 0;
			mVelocity = 0;
			mDeltaVelocity = 0;
			mIsCollision = false;
			count = 0;
			mIsTouch = 0;

			//
			mBodySprite = Sprite::create("Body1.png");
			mBodySprite -> setPosition(mPosition);
			//
			mRootSprite = Sprite::create("Root1.png");
			mRootSprite ->setPosition (Vec2(mPosition.x, mPosition.y - mBodySprite->getContentSize().height / 2 - mRootSprite->getContentSize().height / 2));
			//
			mLeavesSprite = Sprite::create("Leaves1.png");
			mLeavesSprite ->setPosition (Vec2(mPosition.x, mPosition.y + mBodySprite->getContentSize().height / 2 + mLeavesSprite->getContentSize().height / 2));

			mBodyPosition = mPosition;
			mLeavesPosition = (Point(mPosition.x, mPosition.y + mBodySprite->getContentSize().height / 2 + mLeavesSprite->getContentSize().height / 2));
			mBodyNode = Node::create();
			mLeavesNode = Node::create();
		}
	
	
	const Point mPosition; // Position of tree
	const Size mLeavesSize; // Size of leaves
	const Size mBodySize; // Size of body
	const Size mRootSize; // Size of Root
	const float mAddedAnphaTouch;
	float mAddedAnphaWind;
	const float mAddedVelocityCollision;
	const float mOmega;
	float mAddedVelocityWind; // every wind has it own streng
	float mAnpha; // the current anpha of the tree;
	float mDeltaAnpha; // the deltaAnpha every frame added to anpha;
	 // the current velocity of the tree
	float mDeltaVelocity; // the deltaVelocity every frame's added to velocity;
	Sprite* mLeavesSprite;
	Sprite* mBodySprite;
	Sprite* mRootSprite;
	
	bool mIsCollision;
	bool mIsWindrunning;
	
	static Tree* mInstance;
};

#endif