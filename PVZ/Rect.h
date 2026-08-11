#pragma once
#include "Vec2.h"
class Rect
{
public:
	Rect();
	Rect(double x, double y, double w, double h);
	bool isOverlay(const Rect& rect);
	bool isOverlay(const Vec2& pos);
	double x, y, w, h;

};//Åö×²Ïä

