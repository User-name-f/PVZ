#include "Animation.h"

void Animation::addImage(const char* filename)
{
	IMAGE img;
	loadimage(&img, filename);
	m_ImageArray.push_back(img);
}

int Animation::count()
{
	return m_ImageArray.size();
}

void Animation::setInterval(double a)
{
	Interval = a;
}

double Animation::getInterval()
{
	return Interval;
}
