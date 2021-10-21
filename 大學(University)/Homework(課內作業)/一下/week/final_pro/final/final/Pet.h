#pragma once
#ifndef PET_H
#define PET_H

class Ability;

//寵物資料基本格式
struct PetInfo
{
	int no; //編號
	char name[50]; //名字
	
	// 屬性
	char type[30];
	int i_type;
	
	//hp
	double maxhp;
	double hp;
	
	//atk
	int maxatk;
	int atk;
	
	//def
	int maxdef;
	int def;
	
	//speed
	int maxspeed;
	int speed;
	
	//能力
	int i_ability;
	Ability* ability = nullptr;

	//debuff
	int poison = 0;
	int lower_attack = 0;
	int lower_defence = 0;
	int lower_speed = 0;
};

class Pet
{
	friend void fightdisplay(Pet&, Pet&); //展示戰鬥中的兩隻Pet
	friend class Ability;
	friend class Heal;
	friend class Burning;
	friend class Counter_Attack;
	friend class Immunology;
	friend class Leech_Life;
	friend class Avoid;
	friend class Double_Attack;
	friend class Poison;
	friend class Lower_Speed;
	friend class Rock_Skin;
	friend class Lower_Defence;
	friend class Lower_Attack;
	friend class Player;
	friend class PetList;
public:
	Pet();
	~Pet();
	//Pet& operator=(Pet&);
	void catchdisplay(); //展示被捕捉的寵物
	void attack(Pet&); //攻擊
	void passaround(); //經過1回合
private:
	double type_table[18][18];
	PetInfo myinfo;
	void displayicon(int, int); //展示圖示
	void displayattributes(int, int); //展示屬性
	void loadtypetable(); //讀取相剋表
};


#endif // !PET_H
