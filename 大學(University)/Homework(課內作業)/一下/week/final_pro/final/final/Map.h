#pragma once
#ifndef MAP_H
#define MAP_H

class Map
{
	friend class Move;
public:
	Map();
	~Map();
	void drawmap(); //�eyzu�a��
	void loadmapdata(); //Ū�a�Ϫ�txt��
private:
	char mymap[50][150];
	int txtline = 0; //����txtŪ��X��
};


#endif // !MAP_H
