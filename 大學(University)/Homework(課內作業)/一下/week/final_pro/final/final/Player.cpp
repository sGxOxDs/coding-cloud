#include "loading.h"



Player::Player(char t_char)
{
	myinfo.mapicon = t_char;
}

Player::~Player()
{

}

void Player::catchpet(int type, const PetList &petlist) // 0 = normal | 1 = grass | 2 = water
{
	Pet t_pet;
	int r = rand();
	if (type == 0) //normal
	{
		r %= 3200;
		r /= 100;
		t_pet = petlist.petlist[r];
	}
	else if (type == 1) //grass
	{
		r %= 3500;
		r /= 100;
		if (r >= 32)
			r -= 32;
		t_pet = petlist.petlist[r];
	}
	else if (type == 2) //water
	{
		r %= 3500;
		r /= 100;
		if (r >= 32)
			r -= 26;
		t_pet = petlist.petlist[r];
	}
	t_pet.catchdisplay(); //圖示與屬性
	displayhave(51, 15); //寵物列表
	string yn;
	rlutil::locate(1, 25);
	cout << "是否嘗試捕捉 y/n ? ";
	cin >> yn;
	if (strcmp(yn.c_str(), "y") == 0)
	{
		if (rand() % 2 == 0)
		{
			myinfo.pet.push_back(t_pet);
			rlutil::locate(20, 25);
			cout << "捕捉成功! ";
			while (myinfo.pet.size() > 3)
			{
				rlutil::locate(1, 26);
				int choice;
				cout << "超出上限! 必須捨棄一隻寵物";
				displayhave(1, 27);
				cin >> choice;
				if (choice >= 1 && choice < myinfo.pet.size())
					myinfo.pet.erase(myinfo.pet.begin() + choice - 1);
			}
		}
		else
		{
			rlutil::locate(20, 25);
			cout << "捕捉失敗... ";
		}
	}
	else
	{
		rlutil::locate(20, 25);
		cout << "放棄捕捉 ";
	}

	system("pause");
	rlutil::cls();
	rlutil::locate(1, 1);
}

void Player::displayhave(int x,int y)
{
	rlutil::locate(x, y);
	cout << "寵物列表: " << endl;
	for (int i = 1; i <= myinfo.pet.size(); i++)
	{
		rlutil::locate(x, y + i);
		cout << i << ". " << myinfo.pet[i - 1].myinfo.name << endl;
	}
}

void Player::fight(const PetList& petlist)
{
	Player enemy('0');
	for (int i = 0; i < 3; i++)
	{
		Pet t_pet = petlist.petlist[rand() % 32];
		enemy.myinfo.pet.push_back(t_pet);
	}
	while (survival_count() != 0 && enemy.survival_count() != 0)
	{
		vector<Pet>::iterator me;
		for (me = myinfo.pet.begin(); me->myinfo.hp <= 0; me++);

		vector<Pet>::iterator foe;
		for (foe = enemy.myinfo.pet.begin(); foe->myinfo.hp <= 0; foe++);

		me->passaround();
		foe->passaround();

		fightdisplay(*me, *foe);
		displayhave(1, 35);
		enemy.displayhave(51, 35);
		int y = 40;

		if (me->myinfo.speed >= foe->myinfo.speed)
		{
			round(*me, *foe, y);
		}
		else
		{
			round(*foe, *me, y);
		}
		rlutil::locate(1, y++);
		system("pause");
	}
	rlutil::cls();
	if (survival_count() == 0 )
	{
		cout << "你失去了所有寵物!" << endl;
		myinfo.pet.clear();
	}
	else if (enemy.survival_count() == 0)
	{
		win++;
		cout << "你獲勝了!" << endl;
		cout << "寵物完全恢復!" << endl;
		for (int i = 0; i < myinfo.pet.size(); i++)
		{
			myinfo.pet[i].passaround();
			myinfo.pet[i].passaround();
			myinfo.pet[i].passaround();
			myinfo.pet[i].myinfo.hp = myinfo.pet[i].myinfo.maxhp;
		}
			
	}
	system("pause");
	rlutil::cls();
}

//left speed 一定大於 right speed
void Player::round(Pet& left,Pet& right ,int& y)
{
	try //迴避能力
	{
		if (right.myinfo.ability->use(right))
		{
			try { left.myinfo.ability->use(left, right); } //其他能力
			catch (string & e)
			{
				rlutil::locate(1, y++);
				cout << e << endl;
			}
			try { left.attack(right); }
			catch (double& e)
			{
				rlutil::locate(1, y++);
				cout << left.myinfo.name << " 對" << right.myinfo.name << " 造成 " << e << "點傷害" << endl;
				try { right.myinfo.ability->use(right, left, e); } //反擊能力
				catch (string & a)
				{
					rlutil::locate(1, y++);
					cout << a << endl;
				}
			}
			try { left.myinfo.ability->use(left, right, y); } //雙重攻擊
			catch (string & e)
			{
				rlutil::locate(1, y++);
				cout << e << endl;
				try { left.attack(right); }
				catch (double& b)
				{
					rlutil::locate(1, y++);
					cout << left.myinfo.name << " 對" << right.myinfo.name << " 造成 " << b << "點傷害" << endl;
					try { right.myinfo.ability->use(right, left, b); } //反擊能力
					catch (string & a)
					{
						rlutil::locate(1, y++);
						cout << a << endl;
					}
				}
			}
		}
	} 
	catch (string & e)
	{
		rlutil::locate(1, y++);
		cout << e << endl;
	}
	if (right.myinfo.hp <= 0)
	{
		rlutil::locate(1, y++);
		cout << right.myinfo.name << " 陣亡!" << endl;
		left.myinfo.ability->allreset();
	}
	else
	{
		try //迴避能力
		{
			if (left.myinfo.ability->use(left))
			{
				try { right.myinfo.ability->use(right, left); } //其他能力
				catch (string & e)
				{
					rlutil::locate(1, y++);
					cout << e << endl;
				}
				try { right.attack(left); }
				catch (double& e)
				{
					rlutil::locate(1, y++);
					cout << right.myinfo.name << " 對" << left.myinfo.name << " 造成 " << e << "點傷害" << endl;
					try { left.myinfo.ability->use(left, right, e); } //反擊能力
					catch (string & a)
					{
						rlutil::locate(1, y++);
						cout << a << endl;
					}
				}
				try { right.myinfo.ability->use(right, left, y); } //雙重攻擊
				catch (string & e)
				{
					rlutil::locate(1, y++);
					cout << e << endl;
					try { right.attack(left); }
					catch (double& b)
					{
						rlutil::locate(1, y++);
						cout << right.myinfo.name << " 對" << left.myinfo.name << " 造成 " << b << "點傷害" << endl;
						try { left.myinfo.ability->use(left, right, b); } //反擊能力
						catch (string & a)
						{
							rlutil::locate(1, y++);
							cout << a << endl;
						}
					}
				}
			}
		}
		catch (string & e)
		{
			rlutil::locate(1, y++);
			cout << e << endl;
		}
		if (left.myinfo.hp <= 0)
		{
			rlutil::locate(1, y++);
			cout << left.myinfo.name << " 陣亡!" << endl;
			right.myinfo.ability->allreset();
		}
	}
}

int Player::survival_count()
{
	int ans = 0;
	for (int i = 0; i < myinfo.pet.size(); i++)
		if (myinfo.pet[i].myinfo.hp > 0)
			ans++;
	return ans;
}