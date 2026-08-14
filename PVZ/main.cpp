#include <easyx.h>
#include <time.h>
#include "Scene.h"
#include <iostream>
#include <string>
#include "tools.h"
#include "Scene_new.h"
#include "Sunflowerball.h"

using namespace std;


int main(void)
{
	srand(time(nullptr));
	initgraph(1050, 600, EX_SHOWCONSOLE);

	Scene_new *scene_new = new Scene_new;
	Scene* scene = new Scene;

	double fps = 1000.0 /120; ///后面会设置刷新频率，此处无用
	clock_t begin_time = clock(), end_time;
	scene_new->scene_init();
	BeginBatchDraw();
	while (true)
	{
		end_time = clock();
		if (double(end_time - begin_time) >= fps)
		{
			scene->drawTick();
			FlushBatchDraw();
			scene->eventTick(double(end_time - begin_time));
			begin_time = end_time;
		}


		//if (peekmessage(&msg))//得到消息
		//{
		//	scene->evevtTick(&msg);
		//}

	}
	//EndBatchDraw();


	return 0;
}
