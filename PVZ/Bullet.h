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
	void eventTick(double a,Bullet *b);
	int speed;
};

