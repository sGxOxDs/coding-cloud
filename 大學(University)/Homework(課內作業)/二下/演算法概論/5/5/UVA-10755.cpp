#include <iostream>
#include <string.h>
#include <climits>
using namespace std;

long long x, y, z, mat[21][21][21], D2sum[21][21], sum[21];

long long ans()
{
	long long globalmax = INT32_MIN;
	for (int x1 = 0; x1 < x; x1++)
	{
		for (int y1 = 0; y1 < y; y1++)
		{
			for (int z1 = 0; z1 < z; z1++)
			{
				memset(D2sum, 0, sizeof(D2sum));
				for (int x2 = x1; x2 < x; x2++)
				{
					memset(sum, 0, sizeof(sum));
					for (int y2 = y1; y2 < y; y2++)
					{
						long long temp = 0;
						for (int z2 = z1; z2 < z; z2++)
						{
							D2sum[y2][z2] += mat[x2][y2][z2];
							sum[z2] += D2sum[y2][z2];
							temp += sum[z2];
							globalmax = max(globalmax, temp);
						}
					}
				}
			}
			
		}
	}
	return globalmax;
}

int main()
{
	int c;
	cin >> c;
	while (c--)
	{
		memset(mat, 0, sizeof(mat));
		cin >> x >> y >> z;
		for (int i = 0; i < x; i++)
			for (int j = 0; j < y; j++)
				for (int k = 0; k < z; k++)
					cin >> mat[i][j][k];
		cout << ans() << endl;
		if (c != 0) cout << endl;
	}
	return 0;
}