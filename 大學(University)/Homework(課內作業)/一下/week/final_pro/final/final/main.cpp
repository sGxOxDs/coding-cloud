#include "loading.h"

#define version 5 //������

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
	cout << "�A��o�F�̲ת��ӧQ!!!" << endl;
	system("pause");
	return 0;
}