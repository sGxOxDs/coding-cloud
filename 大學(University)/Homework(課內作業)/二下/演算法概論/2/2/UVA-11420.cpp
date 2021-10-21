#include <iostream>
#include <climits>
using namespace std;

int main()
{
	int dp[67][67][2] = { 0 };
	dp[1][1][1] = 1;
	dp[1][0][0] = 1;
	for (int i = 2; i <= 66; i++)
	{
		for (int j = 0 ; j <= i; j++)
		{
			dp[i][j][0] += dp[i - 1][j][0] + dp[i - 1][j + 1][1];
			if (j > 0)
				dp[i][j][1] += dp[i - 1][j - 1][0] + dp[i - 1][j - 1][1];
		}
	}


	int n, s;
	while (cin>>n>>s)
	{
		if (n == -1 && s == -1) break;
		cout << dp[n][s][0] + dp[n][s][1] << endl;
	}
}