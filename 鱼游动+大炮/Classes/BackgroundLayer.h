#pragma once
//#include "d:\c++实训\c++实训软件工具\cocos2d-x-2.2.5\cocos2dx\layers_scenes_transitions_nodes\cclayer.h"

#include "cocos2d.h"
#include "StaticData.h"
USING_NS_CC;


class BackgroundLayer :
	public CCLayer
{
public:
	BackgroundLayer(void);

	CREATE_FUNC(BackgroundLayer);
	virtual bool init();

	virtual ~BackgroundLayer(void);
};

