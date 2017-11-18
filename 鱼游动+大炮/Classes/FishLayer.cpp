#include "FishLayer.h"
//#include "cocos2d.h"
#include "Fish.h"

#define FISH_MAX_COUNT 50

FishLayer::FishLayer(void)
{
}
FishLayer::~FishLayer(void)
{
}

CCScene* FishLayer::scene(void)
{
	CCScene* scene = CCScene::create();
	FishLayer* fishLayer = FishLayer::create();
	scene->addChild(fishLayer);
	return scene;
}

bool FishLayer::init()
{

	if(!CCLayer::init())
	{
		return false;
	}
	
	//Fish *fish = Fish::create((FishType)16);
	//if(!fish)
	//{
	//	return false;
	//}
	//this->addChild(fish);
	//fish->setPosition(ccp(1000,800));

	_fishes = CCArray::createWithCapacity(50);
	CC_SAFE_RETAIN(_fishes);
	for(int i=0;i<FISH_MAX_COUNT;i++)
	{
		int type = CCRANDOM_0_1()*k_Fish_Type_Count-1;
		CCLOG("FishLayer type = %d",type);
		Fish *fish = Fish::create((FishType)type);
		_fishes->addObject(fish);
	}
	this->schedule(schedule_selector(FishLayer::addFish),3.0f);
	return true;
}

void FishLayer::addFish(float delta)
{
	int addToCount = CCRANDOM_0_1()*5+1;
	int count = 0;
	CCObject *obj;
	CCSize winSize=CCDirector::sharedDirector()->getWinSize();
	CCARRAY_FOREACH(_fishes,obj)
	{
		Fish *fish = (Fish *)obj;
		if(fish->isRunning())
		{
			continue;
		}
		this->addChild(fish);
		fish->setPosition(ccp(CCRANDOM_0_1()*winSize.width,CCRANDOM_0_1()*winSize.height));
		count++;
		if(count==addToCount)
		{
			break;
		}
	}
}

