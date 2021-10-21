#include <iostream>
using namespace std;

long long int c[201][201] = {0};
long long int mod = 1000000;
int main()
{
	c[0][0] = 1;
	for (int i = 1; i < 201; i++)
	{
		c[i][0] = 1;
		for (int j = 1; j <= i; j++)
		{
			c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
		}
	}
	int n, k;
	while (cin>>n>>k)
	{
		if (n == 0 && k == 0)break;
		cout << "ans: " << c[n + k - 1][k - 1] << endl;
	}
}