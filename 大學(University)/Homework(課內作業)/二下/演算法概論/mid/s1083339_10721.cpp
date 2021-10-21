#include <iostream>

using namespace std;

long long bc[51][51][51] = { 0 }; //add

int main()
{
	//int bc[51][51][51] = { 0 }; delete

	for (int j = 1; j <= 50; j++)
	{
		bc[0][0][j] = 1; //modify
	}

	for (int u = 1; u <= 50; u++) //modify
	{
		for (int i = 1; i <= 50; i++)
		{
			for (int j = 1; j <= 50; j++) //modify
			{
				//if (j > u) delete
				for (int p = 1; p <= u && p <= j; p++) //add
					bc[u][i][j] += bc[u - p][i - 1][j]; //modify
				//cout << u << "/" << i << "/" << j << ": " << bc[u][i][j] << endl;
			}
		}
	}






	int  n, k, m;
	while (cin >> n >> k >> m)
	{
		cout << bc[n][k][m] << endl;
	}

	return 0;
}