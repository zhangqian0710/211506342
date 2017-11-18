#include "Fish.h"


Fish::Fish(void)
{
}


Fish::~Fish(void)
{
}


Fish *Fish::create(FishType type)
{
	Fish *fish = new Fish;
	if(fish && fish->init(type))
	{

		fish->autorelease();
		return fish;
	}
	else
	{
		CC_SAFE_DELETE(fish);
		return NULL;
	}
}

bool Fish::init(FishType type)
{
	do
	{
		if(!CCNode::init())
			{
				break;
			}
		if(type <k_Fish_Type_SmallFish || type>=k_Fish_Type_Count)
		{
			type=k_Fish_Type_SmallFish;
		}
		setType(type);
		CCString *animationName = CCString::createWithFormat("fish_animation_%02d",_type+1);
		CC_BREAK_IF(!animationName);
		CCAnimation *animation = CCAnimationCache::sharedAnimationCache()->animationByName(animationName->getCString());
		CC_BREAK_IF(!animation);
		CCAnimate *animate = CCAnimate::create(animation);
		CC_BREAK_IF(!animate);
		//animate->setTag(k_Action_Animate);
		_fishSprite=CCSprite::create();
		CC_BREAK_IF(!_fishSprite);
		this->addChild(_fishSprite);
		_fishSprite->runAction(CCRepeatForever::create(animate));
		return true;
	}while(0);
	return false;
	
}
int Fish::getScore()
{
	return 0;
}
int Fish::getSpeed()
{
	return 200;
}