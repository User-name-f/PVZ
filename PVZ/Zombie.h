#pragma once
#include <easyx.h>
#include "Vec2.h"
#include "Animation.h"
#include "Rect.h"

class Zombie
{
public:
	Zombie(const char* filename);
	void drawTick();
	void eventTick(double a);
	void setPosition(Vec2& pos);
	void setAnimation(Animation& ani);
	void startAnimation(bool isStartAni = true);
	Rect getBoundingBox();//µÃµ½Åö×²Ïä
	void setIsMove(bool a);
	void setAttackAnimation(Animation& ani);
	int row;
	int z_health;

	bool m_IsMove = true;
	IMAGE m_Image;
	Vec2 m_Position;
	Animation m_Animation;
	Animation m_AttackAnimation;
	bool m_IsStartAnimation = false;
	int flag = 0;
	double AnimCount = 0;
};

