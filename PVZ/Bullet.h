#pragma once
#include "easyx.h"
#include "Animation.h"
class Bullet
{
public:
	IMAGE bullet_normal;
	IMAGE bullet_blast[4];
	int flag;
	bool isBlast = false;
	int x;
	int y;
	int row;
	bool isUsed = false;
	Bullet();
	void drawtick();
	bool eventTick(double a);
	int speed = 5;
	int count = 0;
	bool b_IsStartAnimation = false;
	double AnimCount = 0;//(¼ÆÊ±Æ÷)
	Animation m_Animation;
	void startAnimation(bool isStartAni = true);
};

