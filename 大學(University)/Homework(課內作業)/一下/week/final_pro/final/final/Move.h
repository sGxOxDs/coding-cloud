#pragma once
#ifndef MOVE_H
#define MOVE_H

class Move
{
public:
	Move(Map& t_map, Player& t_player , PetList& t_petlist)
		:map(t_map), player(t_player),petlist(t_petlist) {};
	void action();
	~Move() {};
private:
	Map& map;
	Player& player;
	PetList& petlist;
};

#endif // !MOVE_H

