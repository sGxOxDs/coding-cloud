#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    fstream film;
    film.open("Members.dat",ios::out|ios::binary);
}
