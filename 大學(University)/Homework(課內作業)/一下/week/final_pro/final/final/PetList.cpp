#include "loading.h"


PetList::PetList()
{
	loadpetdata();
}

PetList::~PetList()
{
	
}

void PetList::loadpetdata()
{
	fstream file("assets/pokemons.csv", ios::in);
	Pet temp;
	char c[50];
	for (; file.getline(c,50,','); )
	{
		temp.myinfo.no = atoi(c);

		file.getline(temp.myinfo.name, 50, ',');
		file.getline(temp.myinfo.type, 50, ',');
		if (strcmp(temp.myinfo.type, "Normal") == 0)
			temp.myinfo.i_type = 0;
		else if (strcmp(temp.myinfo.type, "Fire") == 0)
			temp.myinfo.i_type = 1;
		else if (strcmp(temp.myinfo.type, "Water") == 0)
			temp.myinfo.i_type = 2;
		else if (strcmp(temp.myinfo.type, "Electric") == 0)
			temp.myinfo.i_type = 3;
		else if (strcmp(temp.myinfo.type, "Grass") == 0)
			temp.myinfo.i_type = 4;
		else if (strcmp(temp.myinfo.type, "Ice") == 0)
			temp.myinfo.i_type = 5;
		else if (strcmp(temp.myinfo.type, "Fighting") == 0)
			temp.myinfo.i_type = 6;
		else if (strcmp(temp.myinfo.type, "Poison") == 0)
			temp.myinfo.i_type = 7;
		else if (strcmp(temp.myinfo.type, "Ground") == 0)
			temp.myinfo.i_type = 8;
		else if (strcmp(temp.myinfo.type, "Flying") == 0)
			temp.myinfo.i_type = 9;
		else if (strcmp(temp.myinfo.type, "Psychic") == 0)
			temp.myinfo.i_type = 10;
		else if (strcmp(temp.myinfo.type, "Bug") == 0)
			temp.myinfo.i_type = 11;
		else if (strcmp(temp.myinfo.type, "Rock") == 0)
			temp.myinfo.i_type = 12;
		else if (strcmp(temp.myinfo.type, "Ghost") == 0)
			temp.myinfo.i_type = 13;
		else if (strcmp(temp.myinfo.type, "Dragon") == 0)
			temp.myinfo.i_type = 14;
		else if (strcmp(temp.myinfo.type, "Dark") == 0)
			temp.myinfo.i_type = 15;
		else if (strcmp(temp.myinfo.type, "Steel") == 0)
			temp.myinfo.i_type = 16;
		else if (strcmp(temp.myinfo.type, "Fairy") == 0)
			temp.myinfo.i_type = 17;
			
		file.getline(c, 50, ',');
		temp.myinfo.maxhp = atoi(c);
		temp.myinfo.hp = atoi(c);

		file.getline(c, 50, ',');
		temp.myinfo.maxatk = atoi(c);
		temp.myinfo.atk = atoi(c);

		file.getline(c, 50, ',');
		temp.myinfo.maxdef = atoi(c);
		temp.myinfo.def = atoi(c);

		file.getline(c, 50, ',');
		temp.myinfo.maxspeed = atoi(c);
		temp.myinfo.speed = atoi(c);

		file.getline(c, 50, '\n'); 
		temp.myinfo.i_ability = atoi(c);
		switch (atoi(c))
		{
		case 1:
			temp.myinfo.ability = new Heal;
			break;
		case 2:
			temp.myinfo.ability = new Burning;
			break;
		case 3:
			temp.myinfo.ability = new Counter_Attack;
			break;
		case 4:
			temp.myinfo.ability = new Immunology;
			break;
		case 5:
			temp.myinfo.ability = new Leech_Life;
			break;
		case 6:
			temp.myinfo.ability = new Avoid;
			break;
		case 7:
			temp.myinfo.ability = new Double_Attack;
			break;
		case 8:
			temp.myinfo.ability = new Poison;
			break;
		case 9:
			temp.myinfo.ability = new Lower_Speed;
			break;
		case 10:
			temp.myinfo.ability = new Rock_Skin;
			break;
		case 11:
			temp.myinfo.ability = new Lower_Defence;
			break;
		case 12:
			temp.myinfo.ability = new Lower_Attack;
			break;
		default:
			temp.myinfo.ability = new Ability;
			break;
		}

		petlist.push_back(temp);
	}
	file.close();
}