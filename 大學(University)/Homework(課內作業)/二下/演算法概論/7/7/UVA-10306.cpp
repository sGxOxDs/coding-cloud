#include <iostream>

using namespace std;

int x[41], y[41];
int dp[301][301];

int main()
{
	int n, m, s;
	cin >> n;
	while (n--)
	{
		cin >> m >> s;
		for (int i = 0; i < 301; i++)
			for (int j = 0; j < 301; j++)
				dp[i][j] = 999999;
		
		for (int i = 0; i < m; i++)
		{
			cin >> x[i] >> y[i];
			dp[x[i]][y[i]] = 1;
		}

		for (int i = 0; i < m; i++)
			for (int j = x[i]; j <= s; j++)
				for (int k = y[i]; k <= s; k++)
					if (dp[j][k] > 1 + dp[j - x[i]][k - y[i]])
						dp[j][k] = 1 + dp[j - x[i]][k - y[i]];

		int max = 999999;
		for (int i = 0; i <= s; i++)
			for (int j = 0; j <= s; j++)
				if (i * i + j * j == s * s && max > dp[i][j])
					max = dp[i][j];

		if (max == 999999)
			cout << "not possible" << endl;
		else
			cout << max << endl;
	}

	return 0;
}