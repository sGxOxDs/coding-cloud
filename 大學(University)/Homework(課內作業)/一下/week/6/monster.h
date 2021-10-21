#ifndef MONSTER_H
#define MONSTER_H
//1083339 ©Çª«¸ê®Æ
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <time.h>

class Monster {
    private:
        int HP;
        int MaxHP;
        int Attack;
        int Defense;
    public:
        Monster(int hp, int mxhp, int atk, int def):HP(hp),MaxHP(mxhp),Attack(atk),Defense(def){}
        void setHP(int hp){ HP = hp; }
        int getHP() const { return HP; }
        int getMaxHP() const { return MaxHP; }
        int getAttack() const { return Attack; }
        int getDefense() const { return Defense; }
        void showStats(){
            std::cout << std::setw(10) << "Monster(" << std::setw(3) << getHP() << " / " << std::setw(3) << getMaxHP() << " )" << std::endl; 
        }
        void attack(Monster &m){
            m.setHP(m.getHP() - (getAttack() - m.getDefense()));
        }
};

class Dragon : public Monster {
    private:
        double Rate;
    public:
        Dragon(double R) :Monster(100, 100, 10, 5), Rate(R) {
            srand(time(NULL));
        }
        void showStats() {
            std::cout << std::setw(10) << "Dragon(" << std::setw(3) << getHP() << " / " << std::setw(3) << getMaxHP() << " )" << std::endl;
        }
        void attack(Monster &m) {
            int Additional = rand() % 10 + 1;
            m.setHP(m.getHP() - (getAttack() - m.getDefense()) - Additional * Rate);
        }
};

class Unicorn : public Monster {
    private:
        int Rate[4] = { 0 };
    public:
        Unicorn() :Monster(100, 100, 11, 6) {
            srand(time(NULL));
            int R = rand() % 4;
            Rate[R] = 1;
        }
        void showStats() {
            std::cout << std::setw(10) << "Unicorn(" << std::setw(3) << getHP() << " / " << std::setw(3) << getMaxHP() << " )" << std::endl;
        }
        void attack(Monster &m) {
            int R = rand() % 4;
            m.setHP(m.getHP() - (getAttack() - m.getDefense()));
            if(Rate[R])
                m.setHP(m.getHP() - (getAttack() - m.getDefense()));
        }
};

#endif // MONSTER_H
