#pragma once
//#include "d:\c++ʵѵ\c++ʵѵ�������\cocos2d-x-2.2.5\cocos2dx\layers_scenes_transitions_nodes\cclayer.h"

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

