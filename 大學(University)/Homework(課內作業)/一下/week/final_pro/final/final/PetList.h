#pragma once
#include <vector>
using namespace std;

#ifndef PETLIST_H
#define PETLIST_H

class PetList
{
	friend class Player;
public:
	PetList();
	~PetList();
private:
	void loadpetdata(); //Ū��Pet��csv��
	vector<Pet> petlist;
};


#endif // !PETLIST_H
