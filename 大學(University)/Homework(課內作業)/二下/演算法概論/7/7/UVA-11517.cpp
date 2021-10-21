#include <iostream>

using namespace std;

int money[101], dp[10001];

int main()
{
	int c;
	cin >> c;
	while (c--)
	{
		int price;
		cin >> price;

		int n;
		cin >> n;

		for (int i = 0; i < n; i++)
			cin >> money[i];
		for (int i = 0; i < 10001; i++)
			dp[i] = 0;

		dp[0] = 1;
		for (int i = 0; i < n; i++)
		{
			for (int j = 10000; j - money[i] >= 0; j--)
			{
				if (dp[j] == 0 || dp[j] > 1 + dp[j - money[i]])
				{
					if (dp[j - money[i]] != 0)
					{
						dp[j] = dp[j - money[i]] + 1;
					}
				}
			}
		}
		while (!dp[price])
		{
			price++;
		}

		cout << price << " " << dp[price] - 1 << endl;
	}

	return 0;
}