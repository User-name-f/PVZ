#include "Zombie.h"
#include "tools.h"

Zombie::Zombie(const char* filename)
{
	loadimage(&m_Image, filename);
}

void Zombie::drawTick()
{
	if (m_IsStartAnimation)
	{
		if(m_IsMove)
		putimagePNG(m_Position.x, m_Position.y, &m_Animation.m_ImageArray[flag]);
		else
		putimagePNG(m_Position.x, m_Position.y, &m_AttackAnimation.m_ImageArray[flag]);
	}
	else {
		putimagePNG(m_Position.x, m_Position.y, &m_Image);
	}

	//È¥³ýÅö×²Ïä±ß¿ò£º
	//Rect rect = getBoundingBox();
	//setlinecolor(TRANSPARENT);
	//setlinestyle(PS_SOLID, 3);
	//rectangle(rect.x, rect.y, rect.x + rect.w, rect.y + rect.h);//´´½¨Åö×²Ïä
}

void Zombie::eventTick(double a)
{
	if(m_IsMove)
	m_Position.x -= 0.02 * a;


	AnimCount += a;
	if (m_IsMove) {
		if (AnimCount >= m_Animation.getInterval())
		{
			flag++;
			if (flag >= m_Animation.count())
				flag = 0;

			AnimCount = 0;
		}
	}
	else
	{
		if (AnimCount >= m_AttackAnimation.getInterval())
		{
			flag++;
			if (flag >= m_AttackAnimation.count())
				flag = 0;

			AnimCount = 0;
		}
	}
}

void Zombie::setPosition(Vec2& pos)
{
	m_Position = pos;
}

void Zombie::setAnimation(Animation& ani)
{
	m_Animation = ani;
}

void Zombie::startAnimation(bool isStartAni)
{
	m_IsStartAnimation = isStartAni;
}

Rect Zombie::getBoundingBox()
{
	return Rect(m_Position.x,m_Position.y,m_Image.getwidth(),m_Image.getheight());
}

void Zombie::setIsMove(bool a)
{
	if (a != m_IsMove) 
	{
		flag = 0;
		AnimCount = 0;
	}

	m_IsMove = a;
}

void Zombie::setAttackAnimation(Animation& ani)
{
	m_AttackAnimation = ani;
}
