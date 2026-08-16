#include "Bullet.h"
#include "tools.h"
#include "easyx.h"
#include "iostream"
#include "Animation.h"

Bullet::Bullet()
{
	loadimage(&bullet_normal, "pic/bullets/bullet_normal.png");
	loadimage(&bullet_blast[3], "pic/bullets/bullet_blast.png");
	for (int i = 0; i < 3; i++)
	{
		double k = (i + 1) * 0.2;
		loadimage(&bullet_blast[i], "pic/bullets/bullet_blast.png", bullet_blast[3].getwidth()*k, bullet_blast[3].getheight()*k,true);
	}
}

void Bullet::drawtick()
{
	if (b_IsStartAnimation)
	{
		putimagePNG(x, y, &bullet_blast[flag]);

	}
	else {
		putimagePNG(x, y, &bullet_normal);
	}
}

bool Bullet::eventTick(double a)
{
	count += a;
	if (count >= 50)
	{
		count = 0;
		x += speed;
		if (isBlast)
		{
			b_IsStartAnimation = true;
			flag++;
		}

		if (x > 1025 || flag>=3)//最大宽
		{
			return true;//飞出屏幕，通知调用者删除
		}
	}
	return false;
}

void Bullet::startAnimation(bool isStartAni)
{
	b_IsStartAnimation = isStartAni;
}




