#ifndef PLAYWR_H
#define PLAYWR_H

class Player {
private:
	std::string Name;
	//int MonsterList[3];
	Monster* m[3];
public:
	Player(std::string name) {
		Name = name;
		//srand(time(NULL));
		for (int i = 0; i < 3; i++)
		{
			if (rand() % 3 == 0)
				m[i] = new Dragon(0.6);
			else if (rand() % 3 == 1)
				m[i] = new Unicorn;
			else 
				m[i] = new Hedgehog;
		}
		//m[0]= new Dragon(0.6);
		//m[1]= new Unicorn;
		//m[2] = new Hedgehog;
	}
	~Player() {
		for (int i = 0; i < 3 && m[i] != nullptr; i++)
		{
			delete m[i];
		}
	}
	std::string getName() {
		return Name;
	}
	Monster* getCurrentMonster() {
		for (int i = 0; i < 3; i++)
		{
			if (m[i]->getHP() > 0)
				return m[i];
		}
		return nullptr;
	}
	void showAliveMonsters() {
		for (int i = 0; i < 3; i++)
			if (m[i]->getHP() > 0)
				m[i]->showStats();
		std::cout << std::endl;
	}
};

#endif