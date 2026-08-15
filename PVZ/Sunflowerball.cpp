#include "Sunflowerball.h"
#include "iostream"
#include "tools.h"
#include "Scene.h"

Sunflowerball::Sunflowerball()
{
	loadimage(&sfb, "pic/sunshine/1.png");
}

void Sunflowerball::setAnimation(Animation& ani)
{
	s_Animation = &ani;
}

void Sunflowerball::startAnimation(bool isStartAni)
{
	s_IsStartAnimation = isStartAni;
}

void Sunflowerball::eventTick(double a)
{
	if (isUsed)
	{
		if (s_Animation == nullptr)
			return;//动画未初始化时直接返回，避免空指针异常

		count += a;
		if (count >= s_Animation->getInterval())
		{
			flag++;
			if (flag >= s_Animation->count())
				flag = 0;
			count = 0;
		}

		if (v_sun.y < dsty)
		{
			v_sun.y += 0.05 * a;//阳光下落
		}
		else if (v_sun.y >= dsty)
		{
			timer++;
			if (timer >= 2000)
			{
				isUsed = false;
				timer = 0;
			}
		}
	}
	else if (offx)
	{
		double angle = atan((v_sun.y - 0) / (v_sun.x - 278));
		offx = 1 * cos(angle);
		offy = 1 * sin(angle);
		v_sun.x -= offx;
		v_sun.y -= offy;
		if (v_sun.x <= 278 || v_sun.y <= 0)
		{
			offx = 0;
			offy = 0;
			Scene::sunshine += 25;
		}
	}
}

void Sunflowerball::drawTick()
{
	if (s_IsStartAnimation)
	{
		if (s_Animation != nullptr)
			putimagePNG(v_sun.x, v_sun.y, &s_Animation->m_ImageArray[flag]);
	}
	else {
		putimagePNG(v_sun.x, v_sun.y, &sfb);
	}
}




