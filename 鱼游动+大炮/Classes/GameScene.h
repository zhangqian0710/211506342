#pragma once
//#include "d:\c++实训\c++实训软件工具\cocos2d-x-2.2.5\cocos2dx\layers_scenes_transitions_nodes\ccscene.h"

#include "cocos2d.h"
#include "BackgroundLayer.h"
#include "FishLayer.h"
#include "MenuLayer.h"
USING_NS_CC;

class GameScene :
	public CCScene
{
public:
	GameScene(void);
	
	CREATE_FUNC(GameScene)
	virtual bool init();

	static CCScene* scene(void);

	virtual ~GameScene(void);
protected:
	BackgroundLayer *backgroundLayer;
	FishLayer *fishLayer;
	MenuLayer *menuLayer;

	void preloadResources(void);
};

