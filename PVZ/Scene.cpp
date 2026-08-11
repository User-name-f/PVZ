#include "Scene.h"
#include <easyx.h>
#include <iostream>
#include "Vec2.h"
#include <string>
#include "tools.h"

using namespace std;

Scene::Scene()//场景初始化
{
	loadimage(&m_BackgroundImg,"pic/bgi/bg.jpg");
	loadimage(&barImg, "pic/bar5.png");

	char name[200] = { 0 };
	for (int i = 1; i <= plant_num; i++)
	{
		sprintf(name, "pic/cards/card_%d.png", i);
		loadimage(&bars[i-1], name);
	}//加载卡牌


	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 9; j++)
		{
			m_PlantTable[i][j] = NULL;
		}

	m_PlantAnimation = new Animation();
	m_PlantAnimation->setInterval(95);//设置动画频率
	for (int i = 1; i <= 13; i++)
	{
		char buff[200] = { 0 };
		sprintf(buff, "pic/plant/bean_shooter/%d.png", i);
		m_PlantAnimation->addImage(buff);
	}//创建一个植物动画

	m_ZombieAnimation = new Animation();
	m_ZombieAnimation->setInterval(95);
	for (int i = 0; i <= 21; i++)
	{
		char buff[200] = { 0 };
		sprintf(buff, "pic/zombie/zm/%d.png", i);
		m_ZombieAnimation->addImage(buff);
	}//创建僵尸动画



	m_ZombieAttackAnimation = new Animation();
	m_ZombieAttackAnimation->setInterval(95);
	for (int i = 1; i <= 21; i++)
	{
		char buff[200] = { 0 };
		sprintf(buff, "pic/zombie/zm_eat/%d.png", i);
		m_ZombieAttackAnimation->addImage(buff);
	}//创建僵尸攻击动画


}

void Scene::drawTick()//场景实现
{
	putimage(0, 0, &m_BackgroundImg);
	putimagePNG(258, 0, &barImg);

	drawPlant_Mouse(selected, current);
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 9; j++)
		{
			if (m_PlantTable[i][j])
				m_PlantTable[i][j]->drawTick();
		}//绘制已种植的植物


	for (int i = 0; i < plant_num; i++)
	{
		putimagePNG(345+66*i, 5, &bars[i]);
	}//实现卡牌




	for (int i = 0; i < 3; i++)
		for (auto& zombie : m_Zombies[i])
		{
			zombie->drawTick();
		}//绘制僵尸

}

void Scene::eventTick(double a)
{

	userClick();//为实现移动和种植提供坐标帮助

	if (planted >= 0)
	{
		Plant* plant = drawPlant(planted, v);
		if (plant)
		{
			if (planted == bean)
			{
				plant->setAnimation(*m_PlantAnimation);
				plant->startAnimation(true);
			}
			m_PlantTable[row][col] = plant;
			planted = -1;
		}
	}

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 9; j++)
		{
			if (m_PlantTable[i][j])
			{
				m_PlantTable[i][j]->eventTick(a);
			}
		}//植物进入事件循环


	for(int i=0;i<3;i++)
		for (auto& zombie : m_Zombies[i])
		{
			zombie->eventTick(a); 
		}//僵尸进入事件循环


	//for (int i = 0; i < 3; i++)
	//{
	//	for (auto &zombie : m_Zombies[i])
	//	{
	//		bool is = false;
	//		for (int j = 0; j < 9; j++)
	//		{
	//			if (m_PlantTable[i][j])
	//				if (m_PlantTable[i][j]->getBoundingBox().isOverlay(zombie->getBoundingBox()))
	//				{
	//					is = true;
	//					zombie->setIsMove(false);
	//				}
	//		}
	//		if(!is)
	//		zombie->setIsMove(true);//没碰到植物
	//	}
	//}//判断僵尸是否碰到了植物


	m_CreateZombieCount += a;
	if (m_CreateZombieCount >= 2000)
	{
		Zombie *zombie = new Zombie("pic/zombie/zm/0.png");//初始化僵尸

		zombie->setAnimation(*m_ZombieAnimation);
		zombie->setAttackAnimation(*m_ZombieAttackAnimation);
		zombie->startAnimation(true);
		//作为信号指向其他函数

		int row = rand() % 3;

		Vec2 v1 = Vec2(910, 150+row *100);
		zombie->setPosition(v1);
		m_Zombies[row].push_back(zombie);

		m_CreateZombieCount = 0;
	}
	
}


Plant* Scene::drawPlant(int type, Vec2& v2)
{
	switch (type)
	{
	case bean: {
		Plant *p0 = new Plant("pic/plant/bean_shooter/1.png");
		p0->setPosition(v2);
		p0->drawTick();
		return p0;
	}
	case sunflower: {
		Plant* p1 = new Plant("pic/plant/sunshine_producer/1.png");
		p1->setPosition(v2);
		p1->drawTick();
		return p1;

	}
	default: {
		return NULL;
	}
	}
}



void Scene::drawPlant_Mouse(int type, Vec2 v2)
{
	switch (type)
	{
	case bean: {
		Plant p0("pic/plant/bean_shooter/1.png");
		p0.setPosition(v2);
		p0.drawTick();
		break;
	}
	case sunflower: {
		Plant p1("pic/plant/sunshine_producer/1.png");
		p1.setPosition(v2);
		p1.drawTick();
		break;
	}
	}
}

void Scene::userClick()
{
	if (peekmessage(&msg))
	{
		if (msg.message == WM_LBUTTONDOWN)
		{
			if (msg.x > 348 && msg.x < 348 + 65 * 8 && msg.y>5 && msg.y < 5 + 90)
			{
				int index = (msg.x - 348) / 65;
				selected = index;
				status = 1;
			}
		}
		else if (msg.message == WM_MOUSEMOVE && status == 1)
		{
			current.x = msg.x - 40;
			current.y = msg.y - 40;
			/*cout << current.x << current.y << endl;*///测试

		}
		else if (msg.message == WM_LBUTTONUP)
		{
			if (selected >= 0)
			{
				col = (msg.x - 250) / 87;
				row = (msg.y - 180) / 108;
				if (row >= 0 && row < 3 && col >= 0 && col < 9)
				{
					v.x = 255 + 82 * col;
					v.y = 190 + 100 * row;
					cout << v.x << ',' << v.y << endl;
					planted = selected;
				}
			}
			/*cout << planted << endl;*/
			status = 0;
			selected = -1;
		}
	}
}


//Vec2 v(255 + 82 * row, 190 + 100 * col);
//void Scene::evevtTick(const ExMessage* msg)
//{
//	if (msg->message == WM_LBUTTONDOWN)//鼠标点击事件
//	{
//		for (int i = 0; i < 3; i++)
//		{
//			for (int j = 0; j < 9; j++)
//			{
//				if (m_PlantTable[i][j])
//				{
//					if (m_PlantTable[i][j]->getBoundingBox().isOverlay(Vec2(msg->x, msg->y)))
//					{
//						delete m_PlantTable[i][j];
//						m_PlantTable[i][j] = nullptr;
//					}
//				}
//			}
//		}
//	}

//}

