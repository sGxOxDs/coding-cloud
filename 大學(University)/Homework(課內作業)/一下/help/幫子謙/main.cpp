#include"s1081414_BigNUM_P2.h"
#include<iostream>
using namespace std;

BigNUM diNFib(unsigned int n = 0) {
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return diNFib(n - 1) + diNFib(n - 2);
}

int main() {
    unsigned int level = 0;
    cout << "Hello s1081402! how many level do you want to reach?" << endl;
    cin >> level; //this input value will always >=0

    BigNUM ANS(0);
    BigNUM a;

    for (int i = 0; i < level; ++i) {
        ANS = diNFib(i);

        cout << "F(" << i << ") = " << ANS << endl;
        //cout << "F(" << i << ") = "; ANS.print();
    }
    system("pause");
    return 0;
}