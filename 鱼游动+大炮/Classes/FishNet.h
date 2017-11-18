#pragma once

#define _FishNet_H
#include "cocos2d.h"
USING_NS_CC;
class FishNet :
	public CCNode
{
public:
	FishNet(void);
	virtual ~FishNet(void);

	CREATE_FUNC(FishNet);
	bool init();
protected:
	float getSpeed(int type);
	CCSprite *_fishNetSprite;
};

