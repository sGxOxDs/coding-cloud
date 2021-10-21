#include <iostream>
#include <climits>
using namespace std;

int main()
{
	int l, n;
	int dp[52][52] = { 0 };
	while (cin>>l)
	{
		if (l == 0) break;
		int table[52] = { 0 };
		cin >> n;
		n++; table[n] = l;
		for (int i = 1; i < n; i++)
			cin >> table[i];

		int r, b, e, c, temp;
		for (r = 2; r <= n; r++)
		{
			for (b = 0; b < n; b++)
			{
				e = b + r;
				if (e > n) break;
				dp[b][e] = INT_MAX;
				for (c = b + 1; c < e; c++)
				{
					temp = dp[b][c] + dp[c][e] + table[e] - table[b];
					if (temp < dp[b][e])
						dp[b][e] = temp;
				}
			}
		}

		cout << "The minimum cutting is " << dp[0][n] << endl;
	}
}