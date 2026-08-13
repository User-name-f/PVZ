#pragma once

#include <easyx.h>
#include "Plant.h"
#include "Zombie.h"
#include <list>
class Scene
{
public:
	Scene();
	void drawTick();
	void eventTick(double a);
	//void evevtTick(const ExMessage* msg);//鼠标消息事件
	void drawPlant_Mouse(int type, Vec2 v2);
	Plant* drawPlant(int type, Vec2 &v2);
	void userClick();

	IMAGE m_BackgroundImg;
	Plant *m_PlantTable [3][9];
	int row=0;//行
	int col=0;//列
	IMAGE barImg;
	enum { bean, sunflower, plant_num };

	IMAGE bars[plant_num];
	Animation* m_PlantAnimation;
	Animation* m_ZombieAnimation;
	Animation* s_PlantAnimation;

	ExMessage msg;
	int selected = -1;//卡牌位
	int planted = -1;//种植位
	int status = 0;//状态位
	Vec2 current;//跟随鼠标位置
	Vec2 v;

	Animation* m_ZombieAttackAnimation;
	list<Zombie*> m_Zombies[3];//僵尸结构
	/*Zombie *m_Zombie;*/  //测试

	double m_CreateZombieCount = 0; //创建僵尸累加器(计时器)
};

