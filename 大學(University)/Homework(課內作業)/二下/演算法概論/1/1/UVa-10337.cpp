#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

#define MAX 10000000

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		x /= 100;
		vector<vector<int>> wind(10, vector<int>(x + 1));
		for (int p = 9; p >= 0; p--)
			for (int q = 0; q < x; q++)
				cin >> wind[p][q];

		vector<vector<int>> dp(10, vector<int>(x + 1, MAX));
		dp[0][0] = 0;

		for (int q = 1; q <= x; q++)
		{
			for (int p = 0; p < 10; p++)
			{
				int Min = MAX;
				if (p > 0)
				{
					Min = min(Min, dp[p - 1][q - 1] + 60 - wind[p - 1][q - 1]);
					Min = min(Min, dp[p][q - 1] + 30 - wind[p][q - 1]);
				}
				if (p < 9)
				{
					Min = min(Min, dp[p + 1][q - 1] + 20 - wind[p + 1][q - 1]);
				}
				dp[p][q] = Min;
				//cout << "dp" << "[" << p << "]" << "[" << q << "]" << ": " << dp[p][q] << endl;
				
			}
		}
		cout << dp[0][x] << endl;

	}

	return 0;
}