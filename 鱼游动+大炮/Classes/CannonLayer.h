#pragma once
//#include "d:\c++ʵѵ\c++\cocos2d-x-2.2.5\cocos2dx\layers_scenes_transitions_nodes\cclayer.h"

#define _CANNONLAYER_H
#include "cocos2d.h"
#include "Weapon.h"
class CannonLayer :
	public CCLayer
{
public:
	CannonLayer(void);
	virtual ~CannonLayer(void);

	virtual bool init();
	void switchCannonCallback(cocos2d::CCObject *sender);

	CREATE_FUNC(CannonLayer);

	CC_SYNTHESIZE_READONLY(Weapon *,_weapon,Weapon);
protected:
	cocos2d::CCMenuItemImage *_addMenuItem,*_subMenuItem;

};

