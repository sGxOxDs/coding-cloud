#include <iostream>
#include <string.h>
#include <climits>
using namespace std;

int n, m, maxmoney, mat[111][111], sum[111];

void ans()
{
	int maxbuy = 0;
	int maxcost = INT32_MAX;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			memset(sum, 0, sizeof(sum));
			for (int p = i; p < n; p++)
			{
				int temp = 0;
				for (int q = j; q < m; q++)
				{
					sum[q] += mat[p][q];
					temp += sum[q];
					if (maxbuy <= (p - i + 1) * (q - j + 1) && temp <= maxmoney)
					{
						if (maxbuy == (p - i + 1) * (q - j + 1))
							maxcost = min(maxcost, temp);
						else
							maxcost = temp;
						maxbuy = (p - i + 1) * (q - j + 1);
					}
				}
			}
		}
	}
	if (maxbuy == 0)
		maxcost = 0;
	cout << maxbuy << " " << maxcost << endl;
}

int main()
{
	int c, ca = 1;
	cin >> c;
	while (c--)
	{
		cin >> n >> m >> maxmoney;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
			{
				cin >> mat[i][j];
			}
		cout << "Case #" << ca++ << ": ";
		ans();
	}
	return 0;
}