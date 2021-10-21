#include <iostream>
#include <iomanip>
using namespace std;


int main()
{
	int N, x, T, K;
	while (cin>>N>>x>>T>>K)
	{
		if (N == 0 && x == 0 && T == 0 && K == 0) break;

		int price[202] = { 0 };
		int love[202] = { 0 };

		for (int i = 0; i < K; i++)
		{
			cin >> price[2 * i];
			price[2 * i + 1] = price[2 * i];
			for (int j = 0; j < N + 1; j++)
			{
				int temp;
				cin >> temp;
				love[2 * i] += temp;
			}
			love[2 * i + 1] = love[2 * i];
		}
        int allmoney = (x * (N + 1) / 1.1) + 1e-9 - T * (N + 1);
		int dp[202][1001] = { 0 };
		
		for (int i = 0; i < K * 2; i++)
			for (int j = 2 * (N + 1); j > 0; j--)
				for (int k = allmoney; k >= price[i]; k--)
				{
					dp[j][k] = max(dp[j][k], dp[j - 1][k]);
					dp[j][k] = max(dp[j][k], dp[j - 1][k - price[i]] + love[i]);
				}
		int Max = -1;
		int V = allmoney;
		for (int i = 0; i <= (N + 1) * 2; i++)
			Max = max(dp[i][V], Max);
		cout <<"Ans: "<< setprecision(2) << fixed << (double)Max / (N + 1) << endl;
	}
}