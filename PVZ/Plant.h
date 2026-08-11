#pragma once

#include <easyx.h>
#include <iostream>
#include <string>
#include "Vec2.h"
#include "Animation.h"
#include "Rect.h"
using namespace std;

class Plant
{
public:
	Plant(const char* filename);
	void drawTick();
	void eventTick(double a);
	void setPosition(Vec2& pos);
	void setAnimation(Animation& ani);
	void startAnimation(bool isStartAni =true);
	//Rect getBoundingBox();//得到碰撞箱


	IMAGE m_Image;
	Vec2 m_Position;
	int type;
	Animation m_Animation;
	bool m_IsStartAnimation = false;
	int flag = 0;//动画目前播到的帧数
	double AnimCount=0;//(计时器)
};

