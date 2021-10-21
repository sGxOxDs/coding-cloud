#include <iostream>
#include <string.h>
#include <climits>
using namespace std;

int n,mat[400][400], sum[400];

int ans()
{
	int globalmax = INT32_MIN;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			memset(sum, 0, sizeof(sum));
			for (int p = i; p < n + i; p++)
			{
				int temp = 0;
				for (int q = j; q < n + j; q++)
				{
					sum[q] += mat[p][q];
					temp += sum[q];
					globalmax = max(globalmax, temp);
				}
			}
		}
	}
	return globalmax;
}

void main()
{
	int c;
	cin >> c;
	while (c--)
	{
		cin >> n;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
			{
				cin >> mat[i][j];
				mat[i + n][j] = mat[i][j];
				mat[i][j + n] = mat[i][j];
				mat[i + n][j + n] = mat[i][j];
			}
		cout << ans() << endl;
	}
}