#pragma once
//#include "d:\c++ʵѵ\c++ʵѵ�������\cocos2d-x-2.2.5\cocos2dx\layers_scenes_transitions_nodes\cclayer.h"

#include "cocos2d.h"
USING_NS_CC;

class MenuLayer :
	public CCLayer
{
public:
	MenuLayer(void);

	CREATE_FUNC(MenuLayer);
	virtual bool init();

	virtual ~MenuLayer(void);
};

