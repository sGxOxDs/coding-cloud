#pragma once
#include <vector>
using namespace std;
#ifndef PLAYER_H
#define PLAYER_H

//玩家基本資料格式
struct PlayerInfo
{
	char mapicon; //地圖中代表玩家的符號

	//絕對座標
	int x = 0;
	int y = 0;

	vector<Pet> pet; //擁有的寵物
};

//玩家物件
class Player
{
	friend class Move;
public:
	Player(char);
	~Player();
	void catchpet(int, const  PetList&); //抓寵流程 int控制地形
	void fight(const PetList&); //戰鬥流程 每次隨機生成敵人
private:
	int win = 0;
	PlayerInfo myinfo;
	void displayhave(int, int); //顯示擁有的pet
	int survival_count(); //顯示pet的存活數
	void round(Pet&, Pet&, int&); //每個回合
};


#endif // !PLAYER_H
