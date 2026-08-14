#pragma once
#include "Vec2.h"
#include "easyx.h"
#include "Animation.h"


class Sunflowerball
{
public:
	IMAGE sfb;
	Sunflowerball();
	void setAnimation(Animation& ani);
	void startAnimation(bool isStartAni = true);
	Animation* s_Animation = nullptr;
	bool s_IsStartAnimation = false;
	Vec2 v_sun;
	int dsty;//220-510
	bool isUsed = false;
	int count = 0;
	int flag = 0;
	int timer = 0;
	void eventTick(double a);
	void drawTick();
};

