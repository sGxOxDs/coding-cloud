#include <iostream>

using namespace std;

int add(int left, int right)
{
    return left + right;
}

double add(double left, double right)
{
    return left + right;
}

int main(int argc, const char *argv[])
{
    int a=5, b=1;
    float m=0.5, n=0.01;

    cout << add(a,b) << endl;
    cout << add(m,n) << endl;
    return 0;
}
