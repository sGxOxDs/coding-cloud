#include <iostream>
#include "num.h"
using namespace std;
int main (void)
{
    num myNum;

    myNum.set(3);
    myNum.addTwo();
    cout << myNum.get() << endl;
    return (0);
}
