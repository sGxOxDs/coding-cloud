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
		str += " 使用能力 \"Heal\" 治療了自己";
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
		str += " 被 \"Burning\" 灼傷";
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
		str += " 使用能力 \"Counter Attack\" 反彈了傷害";
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
		str += " 使用能力 \"Leech Life\" 吸血";
		throw str;
	}
}

string Avoid::ability_name() { return "Avoid"; }
bool Avoid::use(Pet& left)
{
	if (rand() % 5 == 0)
	{
		string str = left.myinfo.name;
		str += " 使用能力 \"Avoid\" 迴避了傷害";
		throw str;
		return false; //毫無意義   原因 throw 直接前往 catch
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
			str += " 使用能力 \"Double Attack\" 造成第2次傷害";
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
			str += " 中毒了 \"Poison\" ";
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
			str += " 使用能力 \"Immunology\" 免疫了緩速";
			throw str;
			return;
		}
		if (!used_all)
		{
			right.myinfo.lower_speed = 2;
			used_all = true;
			string str = right.myinfo.name ;
			str += " 被緩速了 \"Lower Speed\" ";
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
		str += " 使用能力 \"Rock Skin\" ";
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
			str += " 使用能力 \"Immunology\" 免疫了降防";
			throw str;
			return;
		}
		if (!used_all)
		{
			right.myinfo.lower_defence = 2;
			used_all = true;
			string str = right.myinfo.name;
			str += " 被降防了 \"Lower Defence\" ";
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
			str += " 使用能力 \"Immunology\" 免疫了降攻";
			throw str;
			return;
		}
		if (!used_all)
		{
			right.myinfo.lower_attack = 2;
			used_all = true;
			string str = right.myinfo.name;
			str += " 被降防了 \"Lower Attack\" ";
			throw str;
		}
	}
}