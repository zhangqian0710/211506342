#include "GameScene.h"

#include "CannonLayer.h"

GameScene::GameScene(void)
{
}

CCScene* GameScene::scene(void)
{
	CCScene* scene = CCScene::create();
	GameScene* gameScene = GameScene::create();
	scene->addChild(gameScene);
	return scene;
}

bool GameScene::init()
{
	do
	{
		if (!CCScene::init())
		{
			break;
		}
		preloadResources();

		backgroundLayer = BackgroundLayer::create();
		CC_BREAK_IF(!backgroundLayer);
		this->addChild(backgroundLayer);
		fishLayer = FishLayer::create();
		//CC_BREAK_IF(!fishLayer);
		if(!fishLayer)
		{
			break;
		}
		this->addChild(fishLayer);
		CannonLayer * cannonLayer = CannonLayer::create();
		this->addChild(cannonLayer);
		menuLayer = MenuLayer::create();
		CC_BREAK_IF(!menuLayer);
		CC_SAFE_RETAIN(menuLayer);
		//this->addChild(menuLayer);
		return true;
	}while(0);
	return false;
}

void GameScene::preloadResources(void)
{
	CCSpriteFrameCache *spriteFrameCache = CCSpriteFrameCache::sharedSpriteFrameCache();
	spriteFrameCache->addSpriteFramesWithFile("FishActor-Large-ipadhd.plist");
	spriteFrameCache->addSpriteFramesWithFile("FishActor-Marlin-ipadhd.plist");
	spriteFrameCache->addSpriteFramesWithFile("FishActor-Shark-ipadhd.plist");
	spriteFrameCache->addSpriteFramesWithFile("FishActor-Small-ipadhd.plist"); 
	spriteFrameCache->addSpriteFramesWithFile("FishActor-Mid-ipadhd.plist");

	spriteFrameCache->addSpriteFramesWithFile("cannon-ipadhd.plist");//直接写resources里的文件名
	spriteFrameCache->addSpriteFramesWithFile("Item-chaojiwuqi-ipadhd.plist");


	CCTextureCache *textureCache = CCTextureCache::sharedTextureCache();
	//textureCache->addImage(STATIC_DATA_STRING("button_add")
	textureCache->addImage("ui_button_63-ipadhd.png");
	textureCache->addImage("ui_button_65-ipadhd.png");

	char str[][50]={"SmallFish","Croaker","AngelFish","Amphiprion","PufferS",
		"Bream","Porgy","Chelonian","Lantern","Ray","Shark","GoldenTrout","GShark",
		"GMarlinsFish","GrouperFish","JadePerch","MarlinsFish","PufferB"};
	for(int i = 0;i < 18;i++)
	{
		CCArray *array1 = CCArray::createWithCapacity(10);
		for(int j=0;j<10;j++)
		{
			CCString *spriteFrameName=CCString::createWithFormat("%s_actor_%03d.png",str[i],j+1);
			CCSpriteFrame * spriteFrame = spriteFrameCache->spriteFrameByName(spriteFrameName->getCString());
			if(spriteFrame==NULL)
			{
				break;
			}
			array1->addObject(spriteFrame);
		}
		if(array1->count()==0)
		{
			continue;
		}
		CCAnimation *animation =CCAnimation::createWithSpriteFrames(array1,0.15f);
		CCString *animationName = CCString::createWithFormat("fish_animation_%02d",i + 1);
		CCAnimationCache::sharedAnimationCache()->addAnimation(animation,animationName->getCString());

	}
}


GameScene::~GameScene(void)
{
	CC_SAFE_RELEASE_NULL(menuLayer);
}
