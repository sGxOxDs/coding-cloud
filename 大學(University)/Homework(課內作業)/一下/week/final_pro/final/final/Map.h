#pragma once
#ifndef MAP_H
#define MAP_H

class Map
{
	friend class Move;
public:
	Map();
	~Map();
	void drawmap(); //畫yzu地圖
	void loadmapdata(); //讀地圖的txt檔
private:
	char mymap[50][150];
	int txtline = 0; //紀錄txt讀到幾行
};


#endif // !MAP_H
