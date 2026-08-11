#include "Plant.h"
#include "tools.h"

Plant::Plant(const char* filename)
{
	loadimage(&m_Image, filename);
}

void Plant::drawTick()
{
	if (m_IsStartAnimation)
	{
		putimagePNG(m_Position.x, m_Position.y, &m_Animation.m_ImageArray[flag]);

	}
	else {
		putimagePNG(m_Position.x, m_Position.y, &m_Image);
	}



	//Rect rect = getBoundingBox();
	setlinecolor(RED);
	setlinestyle(PS_SOLID,3);
	//rectangle(rect.x, rect.y, rect.x + rect.w, rect.y + rect.h);//创建碰撞箱
}

void Plant::eventTick(double a)
{
	AnimCount += a;
	if (AnimCount >= m_Animation.getInterval())//控制动画频率
	{
		flag++;
		if (flag >= m_Animation.count())
			flag = 0;

		AnimCount = 0;
	}
}

void Plant::setPosition(Vec2& pos)
{
	m_Position = pos;
}

void Plant::setAnimation(Animation& ani)
{
	m_Animation = ani;
}

void Plant::startAnimation(bool isStartAni)
{
	m_IsStartAnimation = isStartAni;
}

//Rect Plant::getBoundingBox()
//{
//	return Rect(m_Position.x, m_Position.y, m_Image.getwidth(), m_Image.getheight());
//
//}


