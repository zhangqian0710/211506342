#pragma once
//#include "d:\c++ʵѵ\c++\cocos2d-x-2.2.5\cocos2dx\base_nodes\ccnode.h"

#define _WEAPON_H
#include "cocos2d.h"
#include "Cannon.h"
#include "Bullet.h"
#include "FishNet.h"

USING_NS_CC;

class Weapon :
	public CCNode
{
public:
	static Weapon * create(CannonType type=k_Cannon_Type_1);
	bool init(CannonType type=k_Cannon_Type_1);
	CannonType getCannonType();
	CCSize getCannonSize();
	void changeCannon(CannonOperate operate);

	//Weapon(void);
	//virtual ~Weapon(void);
	~Weapon();
protected:
	CC_SYNTHESIZE_READONLY(Cannon *,_cannon,Cannon);
	CC_SYNTHESIZE_READONLY(CCArray *,_bullets,Bullets);
	CC_SYNTHESIZE_READONLY(CCArray *,_fishNets,FishNets);
private:

};

