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

void Bullet::eventTick(double a,Bullet *b)
{
	static int count = 0;
	count += a;
	if (count >= 200)
	{
		b->x += speed;
		if (b->x > 1050)//×î´ó¿í
		{
			delete b;
			b = NULL;
		}
	}


}




