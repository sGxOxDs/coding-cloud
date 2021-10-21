#include "loading.h"

void fightdisplay(Pet& left, Pet& right)
{
	rlutil::cls();

	try { left.displayicon(1,1); }
	catch (string & e) { cout << e << endl; }

	try { right.displayicon(51,1); }
	catch (string & e) { cout << e << endl; }

	left.displayattributes(1, 26);
	right.displayattributes(51, 26);
}

Pet::Pet()
{
	loadtypetable();
}

Pet::~Pet()
{
	//if (myinfo.ability != nullptr)
		//delete myinfo.ability;
}

//Pet& Pet::operator=(Pet& right)
//{
//	if (this != &right)
//	{
//		myinfo = right.myinfo;
//	}
//	return *this;
//}

void Pet::catchdisplay()
{
	rlutil::cls();

	try { displayicon(1,1); }
	catch (string & e) { cout << e << endl; }
	
	displayattributes(51, 1);
}

void Pet::displayicon(int x,int y)
{
	string path = "assets/icons/color/";
	if (myinfo.no < 10)
	{
		path += "00";
		path += myinfo.no + '0';
		path += ".txt";
	}
	else
	{
		path += "0";
		path += myinfo.no / 10 + '0';
		path += myinfo.no % 10 + '0';
		path += ".txt";
	}
	fstream file(path, ios::in);
	if (!file)
	{
		throw "No find file";
		return;
	}
	for (char c[500]; file.getline(c, 500, '\n'); rlutil::locate(x, y++),cout << c << endl);
	file.close();
}

void Pet::displayattributes(int x,int y)
{
	rlutil::locate(x, y);
	cout << "Name: " << myinfo.name << endl;
	rlutil::locate(x, y + 1);
	cout << "Type: " << myinfo.type << endl;
	rlutil::locate(x, y + 2);
	cout << "HP: " << myinfo.hp << endl;
	rlutil::locate(x, y + 3);
	cout << "ATK: " << myinfo.atk << endl;
	rlutil::locate(x, y + 4);
	cout << "DEF: " << myinfo.def << endl;
	rlutil::locate(x, y + 5);
	cout << "Speed: " << myinfo.speed << endl;
	rlutil::locate(x, y + 6);
	cout << "Ability: " << myinfo.ability->ability_name() << endl;

}

void Pet::attack(Pet& enemy)
{
	if (myinfo.atk - enemy.myinfo.def > 0)
	{
		enemy.myinfo.hp = enemy.myinfo.hp - (myinfo.atk + 0.0 - enemy.myinfo.def) * type_table[myinfo.i_type][enemy.myinfo.i_type];
		throw (myinfo.atk + 0.0 - enemy.myinfo.def)* type_table[myinfo.i_type][enemy.myinfo.i_type];
	}
	else
	{
		throw 0.0;
	}
	
}

void Pet::passaround()
{
	if (myinfo.poison > 0)
	{
		myinfo.hp -= 2;
		myinfo.poison--;
	}

	if (myinfo.lower_attack > 0)
	{
		myinfo.atk = myinfo.maxatk - 2;
		myinfo.lower_attack--;
	}
	else
	{
		myinfo.atk = myinfo.maxatk;
	}

	if (myinfo.lower_defence > 0)
	{
		myinfo.def = myinfo.maxdef - 2;
		myinfo.lower_defence--;
	}
	else
	{
		myinfo.def = myinfo.maxdef;
	}

	if (myinfo.lower_speed > 0)
	{
		myinfo.speed = myinfo.maxspeed - 2;
		myinfo.lower_speed--;
	}
	else
	{
		myinfo.speed = myinfo.maxspeed;
	}
}

void Pet::loadtypetable()
{
	fstream file("assets/type.csv", ios::in);
	int i = 0;
	for (string line ; getline(file, line, '\n'); i++)
	{
		istringstream templine(line);
		string data;
		int j = 0;
		for (; getline(templine, data, ','); j++)
		{
			type_table[i][j] = atof(data.c_str());
		}
	}
	file.close();
}