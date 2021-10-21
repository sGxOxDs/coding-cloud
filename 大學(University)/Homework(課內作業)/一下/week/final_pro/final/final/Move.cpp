#include "loading.h"

void Move::action()
{
	auto &x = player.myinfo.x;
	auto &y = player.myinfo.y;
	auto &mapicon = player.myinfo.mapicon;
	x = 20;
	y = 30;
	unsigned int cnt = 0;
	rlutil::hidecursor();
	rlutil::locate(75, 30);
	cout << "Turn count: " << cnt << endl;
	rlutil::locate(x, y);
	rlutil::setColor(rlutil::RED);
	cout << mapicon << endl; // Output player
	rlutil::setColor(rlutil::GREY);

	while (true) {
		rlutil::resetColor();
		rlutil::locate(75, 30);
		rlutil::hidecursor();
		cout << "Turn count: " << cnt;
		rlutil::locate(75, 29);
		cout << "win count: " << player.win;
		if (kbhit()) {
			char k = getch(); // Get character
			rlutil::locate(x, y);

			//色彩校正
			if (map.mymap[y - 1][x - 1] == ';')
				rlutil::setColor(rlutil::GREEN);
			else if (map.mymap[y - 1][x - 1] == '~')
				rlutil::setColor(rlutil::BLUE);
			else if (map.mymap[y - 1][x - 1] == '#')
				rlutil::setColor(rlutil::YELLOW);
			else
				rlutil::setColor(rlutil::GREY);
			cout << map.mymap[y - 1][x - 1]; // Erase player

			//基本移動
			if (k == 'a') --x;
			else if (k == 'd') ++x;
			else if (k == 'w') --y;
			else if (k == 's') ++y;
			else if (k == ' ') break;

			//撞不可穿越的物體後回到原點
			if (map.mymap[y - 1][x - 1] == '*'
				|| map.mymap[y - 1][x - 1] == '!'
				|| map.mymap[y - 1][x - 1] == '1'
				|| map.mymap[y - 1][x - 1] == '2'
				|| map.mymap[y - 1][x - 1] == '3'
				|| map.mymap[y - 1][x - 1] == '4'
				|| map.mymap[y - 1][x - 1] == '5'
				|| map.mymap[y - 1][x - 1] == '6'
				|| map.mymap[y - 1][x - 1] == '7'
				|| map.mymap[y - 1][x - 1] == '8'
				|| map.mymap[y - 1][x - 1] == '9'
				|| map.mymap[y - 1][x - 1] == 'A'
				|| map.mymap[y - 1][x - 1] == 'B'
				|| map.mymap[y - 1][x - 1] == 'C'
				|| map.mymap[y - 1][x - 1] == 'D')
			{
				if (k == 'a') ++x;
				else if (k == 'd') --x;
				else if (k == 'w') ++y;
				else if (k == 's') --y;
			}

			//遭遇事件(抓寵或對戰)
			if (map.mymap[y - 1][x - 1] == '#')
			{
				player.fight(petlist);
				map.drawmap();
			}
			else
			{
				if ((rand() + cnt) % 10 == 0)
				{
					int type = 0;
					if (map.mymap[y - 1][x - 1] == '~')
						type = 2;
					else if (map.mymap[y - 1][x - 1] == ';')
						type = 1;
					player.catchpet(type, petlist);
					map.drawmap();
				}
			}	

			rlutil::locate(x, y);
			rlutil::setColor(rlutil::RED);
			cout << mapicon; // Output player
		}
		if (player.win >= 7) //勝利條件
			break;
		cnt++;
		cout.flush();
	}
	rlutil::showcursor();
}