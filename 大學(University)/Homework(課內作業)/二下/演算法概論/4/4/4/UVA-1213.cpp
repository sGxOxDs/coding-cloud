#include <iostream>
#include <cmath>

#define MAX 1200
using namespace std;

int main()
{
	bool mark[MAX] = { 0 };
	int prime[MAX] = { 0 };
	int pr_count = 0;

	int dp[MAX][15] = { 0 };

	mark[1] = true;
	for (int i = 2; i <= 1120; i++)
		if (!mark[i])
		{
			prime[pr_count++] = i;
			for (int j = i + i; j <= 1120; j += i)
				mark[j] = true;
		}

	dp[0][0] = 1;

	for (int k = 0; k < pr_count; k++)
	{
		for (int i = 1120; i >= prime[k]; i--)
		{
			for (int j = 1; j < 15; j++)
			{
				dp[i][j] += dp[i - prime[k]][j - 1];
			}
		}
	}

	int n, k;
	while (cin>>n>>k)
	{
		if (n == 0 && k == 0) break;
		cout << dp[n][k] << endl;
	}

}
			