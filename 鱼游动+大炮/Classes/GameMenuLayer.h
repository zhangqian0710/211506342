#pragma once
//#include "d:\c++实训\c++实训软件工具\cocos2d-x-2.2.5\cocos2dx\layers_scenes_transitions_nodes\cclayer.h"
#include "cocos2d.h"
#include "StaticData.h"
USING_NS_CC;
class GameMenuLayer :
	public CCLayer
{
public:
	GameMenuLayer(void);

	CREATE_FUNC(GameMenuLayer);
	static CCScene* scene(void);
	void menuCallbackSelectScene(CCObject* sender);
	void menuCallbackStartGame(CCObject* sender);
	virtual bool init();

	virtual ~GameMenuLayer(void);

protected:
	void createMenu(void);
};

