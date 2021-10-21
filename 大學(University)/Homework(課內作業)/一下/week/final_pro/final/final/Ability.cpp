#include "loading.h"

bool Ability::use(Pet& left) { return true; }
void Ability::use(Pet& left, Pet& right, int& y) {}
void Ability::allreset() { used_all = false; }

string Heal::ability_name() { return "Heal"; }
void Heal::use(Pet &left,Pet &right)
{
	if (left.myinfo.hp > 0)
	{
		if (left.myinfo.hp + 3 > left.myinfo.maxhp)
		{
			left.myinfo.hp = left.myinfo.maxhp;
		}
		else
		{
			left.myinfo.hp += 3;
		}
		string str = left.myinfo.name;
		str += " �ϥί�O \"Heal\" �v���F�ۤv";
		throw str;
	}
}

string Burning::ability_name() { return "Burning"; }
void Burning::use(Pet& left, Pet& right)
{
	if (left.myinfo.hp > 0)
	{
		right.myinfo.hp -= (rand() % 3 + 1);
		string str = right.myinfo.name;
		str += " �Q \"Burning\" �`��";
		throw str;
	}
}

string Counter_Attack::ability_name() { return "Counter Attack"; }
void Counter_Attack::use(Pet& left, Pet& right, double dmg)
{
	if (left.myinfo.hp > 0)
	{
		right.myinfo.hp -= (dmg / 5);
		string str = left.myinfo.name;
		str += " �ϥί�O \"Counter Attack\" �ϼu�F�ˮ`";
		throw str;
	}
}

string Immunology::ability_name() { return "Immunology"; }

string Leech_Life::ability_name() { return "Leech Life"; }
void Leech_Life::use(Pet& left, Pet& right)
{
	if (left.myinfo.hp > 0)
	{
		int r = rand() % 2 + 2;
		if (left.myinfo.hp + r > left.myinfo.maxhp)
		{
			left.myinfo.hp = left.myinfo.maxhp;
		}
		else
		{
			left.myinfo.hp += r;
		}
		string str = left.myinfo.name;
		str += " �ϥί�O \"Leech Life\" �l��";
		throw str;
	}
}

string Avoid::ability_name() { return "Avoid"; }
bool Avoid::use(Pet& left)
{
	if (rand() % 5 == 0)
	{
		string str = left.myinfo.name;
		str += " �ϥί�O \"Avoid\" �j�פF�ˮ`";
		throw str;
		return false; //�@�L�N�q   ��] throw �����e�� catch
	}
	else
	{
		return true;
	}
	
}

string Double_Attack::ability_name() { return "Double Attack"; }
void Double_Attack::use(Pet& left, Pet& right,int& y)
{
	if (left.myinfo.hp > 0)
	{
		if (rand() % 5 == 0)
		{
			string str = left.myinfo.name;
			str += " �ϥί�O \"Double Attack\" �y����2���ˮ`";
			throw str;
		}
	}
}

string Poison::ability_name() { return "Poison"; }
void Poison::use(Pet& left, Pet& right)
{
	if (left.myinfo.hp > 0)
	{
		if (!used_all)
		{
			right.myinfo.poison = 2;
			used_all = true;
			string str = right.myinfo.name;
			str += " ���r�F \"Poison\" ";
			throw str;
		}
	}
}

string Lower_Speed::ability_name() { return "Lower Speed"; }
void Lower_Speed::use(Pet& left, Pet& right)
{
	if (left.myinfo.hp > 0)
	{
		if (right.myinfo.i_ability == 4)
		{
			string str = right.myinfo.name;
			str += " �ϥί�O \"Immunology\" �K�̤F�w�t";
			throw str;
			return;
		}
		if (!used_all)
		{
			right.myinfo.lower_speed = 2;
			used_all = true;
			string str = right.myinfo.name ;
			str += " �Q�w�t�F \"Lower Speed\" ";
			throw str;
		}
	}
}

string Rock_Skin::ability_name() { return "Rock Skin"; }
void Rock_Skin::use(Pet& left, Pet& right)
{
	if (left.myinfo.hp > 0)
	{
		if ((left.myinfo.atk + 0.0 - right.myinfo.def) * left.type_table[left.myinfo.i_type][right.myinfo.i_type] > 2)
			left.myinfo.hp += 2;
		else
			left.myinfo.hp += (left.myinfo.atk + 0.0 - right.myinfo.def) * left.type_table[left.myinfo.i_type][right.myinfo.i_type];
		string str = left.myinfo.name;
		str += " �ϥί�O \"Rock Skin\" ";
		throw str;
	}
}

string Lower_Defence::ability_name() { return "Lower Defence"; }
void Lower_Defence::use(Pet& left, Pet& right)
{
	if (left.myinfo.hp > 0)
	{
		if (right.myinfo.i_ability == 4)
		{
			string str = right.myinfo.name;
			str += " �ϥί�O \"Immunology\" �K�̤F����";
			throw str;
			return;
		}
		if (!used_all)
		{
			right.myinfo.lower_defence = 2;
			used_all = true;
			string str = right.myinfo.name;
			str += " �Q�����F \"Lower Defence\" ";
			throw str;
		}
	}
}

string Lower_Attack::ability_name() { return "Lower Attack"; }
void Lower_Attack::use(Pet& left, Pet& right)
{
	if (left.myinfo.hp > 0)
	{
		if (right.myinfo.i_ability == 4)
		{
			string str = right.myinfo.name;
			str += " �ϥί�O \"Immunology\" �K�̤F����";
			throw str;
			return;
		}
		if (!used_all)
		{
			right.myinfo.lower_attack = 2;
			used_all = true;
			string str = right.myinfo.name;
			str += " �Q�����F \"Lower Attack\" ";
			throw str;
		}
	}
}