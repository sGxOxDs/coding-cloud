#include <iostream>
#include "monster.h"
//1083339 ¾Ô°«¸ê®Æ
int main(int argc, const char *argv[])
{
    Dragon m1(0.6);
    Unicorn m2;
    srand(time(NULL));
    int cnt = 1;
    while(true){
        std::cout << "Round " << cnt << std::endl;
        bool r = rand() % 2;
        if (r)
        {
            m1.attack(m2);
            m2.showStats();
            if (m2.getHP() <= 0) {
                std::cout << ">>> Unicorn died, Dragon win! <<<" << std::endl;
                m1.showStats();
                break;
            }
            m2.attack(m1);
            m1.showStats();
            if (m1.getHP() <= 0) {
                std::cout << ">>> Dragon died, Unicorn win <<<" << std::endl;
                m2.showStats();
                break;
            }
        }
        else
        {
            m2.attack(m1);
            m1.showStats();
            if (m1.getHP() <= 0) {
                std::cout << ">>> Dragon died, Unicorn win <<<" << std::endl;
                m2.showStats();
                break;
            }
            m1.attack(m2);
            m2.showStats();
            if (m2.getHP() <= 0) {
                std::cout << ">>> Unicorn died, Dragon win! <<<" << std::endl;
                m1.showStats();
                break;
            }
        }
        std::cout << "===============================" << std::endl;
        cnt++;
    }
    return 0;
}
