#include "loading.h"

#define version 5 //版本號

int main()
{
	srand(time(NULL));
	Player p1('@');
	Map map;
	PetList petlist;
	Move move(map, p1, petlist);
	map.drawmap();
	move.action();
	rlutil::cls();
	rlutil::setColor(rlutil::GREY);
	cout << "你獲得了最終的勝利!!!" << endl;
	system("pause");
	return 0;
}