#include "Bullet.h"
#include "tools.h"
#include "easyx.h"
#include "iostream"

Bullet::Bullet()
{
	loadimage(&bullet_normal, "pic/bullets/bullet_normal.png");
	loadimage(&bullet_blast, "pic/bullets/bullet_blast.png");
}

void Bullet::drawtick()
{
	putimagePNG(x, y, &bullet_normal);
}

bool Bullet::eventTick(double a)
{
	count += a;
	if (count >= 50)
	{
		count = 0;
		x += speed;
		if (x > 1025)//最大宽
		{
			return true;//飞出屏幕，通知调用者删除
		}
	}
	return false;
}




