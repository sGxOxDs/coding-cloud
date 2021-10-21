#include "loading.h"

Map::Map()
{
	loadmapdata();
}
Map::~Map()
{

}
void Map::drawmap()
{
	for (int i = 0; i < txtline; i++)
	{
		for (int j = 0; mymap[i][j] != '\0'; j++)
		{
			//¦â±m®Õ¥¿
			if (mymap[i][j] == ';')
				rlutil::setColor(rlutil::GREEN);
			else if (mymap[i][j] == '!')
				rlutil::setColor(rlutil::BROWN);
			else if (mymap[i][j] == '~')
				rlutil::setColor(rlutil::BLUE);
			else if (mymap[i][j] == '#')
				rlutil::setColor(rlutil::YELLOW);
			else
				rlutil::setColor(rlutil::GREY);
			cout << mymap[i][j];
		}
		rlutil::resetColor();
		cout << endl;
	}
		
}
void Map::loadmapdata()
{
	fstream file("assets/yzumap.txt", ios::in);
	for (txtline = 0; file.getline(mymap[txtline], 150, '\n'); txtline++);
	file.close();
}