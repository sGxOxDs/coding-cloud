#pragma once
#ifndef PET_H
#define PET_H

class Ability;

//�d����ư򥻮榡
struct PetInfo
{
	int no; //�s��
	char name[50]; //�W�r
	
	// �ݩ�
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
	
	//��O
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
	friend void fightdisplay(Pet&, Pet&); //�i�ܾ԰������ⰦPet
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
	void catchdisplay(); //�i�ܳQ�������d��
	void attack(Pet&); //����
	void passaround(); //�g�L1�^�X
private:
	double type_table[18][18];
	PetInfo myinfo;
	void displayicon(int, int); //�i�ܹϥ�
	void displayattributes(int, int); //�i���ݩ�
	void loadtypetable(); //Ū���۫g��
};


#endif // !PET_H
