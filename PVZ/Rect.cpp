#include "Rect.h"

Rect::Rect()
{
	x = 0;
	y = 0;
	w = 0;
	h = 0;
}

Rect::Rect(double x, double y, double w, double h)
{
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;
}

bool Rect::isOverlay(const Rect& rect)
{
	if (x <= rect.x + rect.w && rect.x <= x + w
		&& y <= rect.y + rect.h && rect.y <= y + h)
	{
		return true;
	}
	else
	return false;
}

bool Rect::isOverlay(const Vec2& pos)
{
	if (x <= pos.x && pos.x <= x + w
		&& y <= pos.y && pos.y <= y + h)
		return true;
	return false;
}
