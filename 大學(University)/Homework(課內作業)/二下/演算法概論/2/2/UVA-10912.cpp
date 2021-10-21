#include <iostream>
#include <climits>
using namespace std;

int main()
{
	int dp[27][27][352] = { 0 };
	int L, S, c = 1;
	dp[0][0][0] = 1;
	for (int i = 1; i <= 26; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			for (int k = 0; k <= 351; k++)
			{
				dp[i][j][k] = dp[i - 1][j][k];
				if (j && k >= i) 
					dp[i][j][k] += dp[i - 1][j - 1][k - i];
			}
		}
	}

	while (cin>>L>>S)
	{
		if (L == 0 && S == 0) break;
		cout << "Case " << c++ << ": " << ((L <= 26 && S <= 351) ? dp[26][L][S] : 0 )<< endl;
	}

}