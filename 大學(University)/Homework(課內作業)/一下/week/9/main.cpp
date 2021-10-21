#include <iostream>
#include "monster.h"
//1083339 ¾Ô°«¸ê®Æ
int main(int argc, const char *argv[])
{
    //Dragon m1(0.6);
    //Unicorn m2;
    srand(time(NULL));
    Player p1(" wAw ");
    Player p2(" 030 ");
    int cnt = 1;
    while(true){
        system("CLS");
        std::cout << "Round " << cnt << std::endl;
        bool r = rand() % 2;
        if (r)
        {
            std::cout << p1.getName() << " first atk" << std::endl;
            p1.getCurrentMonster()->attack(*p2.getCurrentMonster());
            p2.showAliveMonsters();
            if (p2.getCurrentMonster() == nullptr) {
                std::cout << ">>> "<<p2.getName()<<" died, "<<p1.getName()<<" win! <<<" << std::endl;
                p1.showAliveMonsters();
                break;
            }
            p2.getCurrentMonster()->attack(*p1.getCurrentMonster());
            p1.showAliveMonsters();
            if (p1.getCurrentMonster() == nullptr) {
                std::cout << ">>> " << p1.getName() << " died, " << p2.getName() << " win! <<<" << std::endl;
                p2.showAliveMonsters();
                break;
            }
        }
        else
        {
            std::cout << p2.getName()
                <<" first atk" << std::endl;
            p2.getCurrentMonster()->attack(*p1.getCurrentMonster());
            p1.showAliveMonsters();
            if (p1.getCurrentMonster() == nullptr) {
                std::cout << ">>> " << p1.getName() << " died, " << p2.getName() << " win! <<<" << std::endl;
                p2.showAliveMonsters();
                break;
            }
            p1.getCurrentMonster()->attack(*p2.getCurrentMonster());
            p2.showAliveMonsters();
            if (p2.getCurrentMonster() == nullptr) {
                std::cout << ">>> " << p2.getName() << " died, " << p1.getName() << " win! <<<" << std::endl;
                p1.showAliveMonsters();
                break;
            }
        }
        //std::cout << "===============================" << std::endl;
        system("pause");
        cnt++;
    }
    return 0;
}
