#include <iostream>
using namespace std;

int main(int argc,char* argv[])
{
	int x = atoi(argv[1]);
	cout << x * (x + 1) / 2 << endl;
	return 0;
}