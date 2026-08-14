#include "Scene_new.h"
#include "tools.h"

Scene_new::Scene_new()
{
		loadimage(&initImg, "pic/menu.png");
		loadimage(&initImg1, "pic/menu1.png");
		loadimage(&initImg2, "pic/menu2.png");
		//loadimage(&startImg, "pic/StartSet.png");
		//loadimage(&startImg1, "pic/StartReady.png");
		//loadimage(&startImg2, "pic/StartPlant.png");
}

void Scene_new::scene_init()
{
	ExMessage msg;
	bool flag = false;
	while (1) {
		BeginBatchDraw();
		putimage(0, 0, &initImg);
		putimagePNG(480, 80, flag ? &initImg2 : &initImg1);
		if (peekmessage(&msg))
		{
			if (msg.message == WM_LBUTTONDOWN && msg.x>=480 && msg.x<= 480+331 && msg.y>=80 && msg.y<= 80+145)
			{
				flag = true;
			}
			else if (msg.message == WM_LBUTTONUP && flag==true)
			{
				break;
			}
		}
		EndBatchDraw();
	}
	//putimage(0, 0, &startImg);
	//putimage(0, 0, &startImg1);
	//putimage(0, 0, &startImg2);
}
