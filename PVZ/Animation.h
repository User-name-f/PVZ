#pragma once

#include<iostream>
#include<easyx.h>
#include<vector>
using namespace std;

class Animation
{
public:
	vector<IMAGE> m_ImageArray;//图片数组
	void addImage(const char* filename);
	int count();
	void setInterval(double a);
	double getInterval();

	double Interval=0;//动画间隔

};

