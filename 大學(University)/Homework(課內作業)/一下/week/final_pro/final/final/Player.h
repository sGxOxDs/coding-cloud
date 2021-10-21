#pragma once
#include <vector>
using namespace std;
#ifndef PLAYER_H
#define PLAYER_H

//���a�򥻸�Ʈ榡
struct PlayerInfo
{
	char mapicon; //�a�Ϥ��N���a���Ÿ�

	//����y��
	int x = 0;
	int y = 0;

	vector<Pet> pet; //�֦����d��
};

//���a����
class Player
{
	friend class Move;
public:
	Player(char);
	~Player();
	void catchpet(int, const  PetList&); //���d�y�{ int����a��
	void fight(const PetList&); //�԰��y�{ �C���H���ͦ��ĤH
private:
	int win = 0;
	PlayerInfo myinfo;
	void displayhave(int, int); //��ܾ֦���pet
	int survival_count(); //���pet���s����
	void round(Pet&, Pet&, int&); //�C�Ӧ^�X
};


#endif // !PLAYER_H
