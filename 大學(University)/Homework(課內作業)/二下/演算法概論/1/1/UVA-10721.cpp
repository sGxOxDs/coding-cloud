#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int bc[51][51][51];

int main()
{
	for (int x = 0; x < 51; x++)
		for (int y = 0; y < 51; y++)
			for (int z = 0; z < 51; z++)
				bc[x][y][z] = 0;
	for (int i = 0; i < 51; i++)
		bc[0][0][i] = 1;

	int n, k, m;
	for (n = 1; n <= 50; n++)
	{
		for (k = 1; k <= 50; k++)
		{
			for (m = 1; m <= 50; m++)
			{
				if (m > n)
				{
					bc[n][k][m] = bc[n][k][n];
					continue;
				}
				for (int i = 1; i <= n && i <= m; i++)
				{
					bc[n][k][m] += bc[n - i][k - 1][m];
					//if (bc[n - i][k - 1][m] > 0)
						cout << "    n=" << n-i << " k=" << k-1 << " m=" << m << " bc=" << bc[n - i][k - 1][m] << endl;
				}
				if (bc[n][k][m] > 0)
				{
					cout << "=== n=" << n << " k=" << k << " m=" << m << " bc=" << bc[n][k][m] << " ===" << endl;
					cout << endl;
				}
					

			}
		}
	}
		



	while (cin>>n>>k>>m)
	{
		cout << bc[n][k][m] << endl;
	}
}