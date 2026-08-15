#pragma once
#include "easyx.h"
class Bullet
{
public:
	IMAGE bullet_normal;
	IMAGE bullet_blast;
	int x;
	int y;
	int row;
	bool isUsed = false;
	Bullet();
	void drawtick();
	bool eventTick(double a);
	int speed = 5;
	int count = 0;
};

