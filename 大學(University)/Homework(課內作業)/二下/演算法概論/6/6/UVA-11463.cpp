#include <iostream>

using namespace std;


int main()
{
	int t, c = 1;
	cin >> t;
	while (t--)
	{
		int W[101][101], oo = 999999;
		for (int i = 0; i < 101; i++)
			for (int j = 0; j < 101; j++)
			{
				W[i][j] = oo;
				if (i == j)
					W[i][j] = 0;
			}

		int n, line;
		cin >> n;
		cin >> line;

		while (line--)
		{
			int a, b;
			cin >> a >> b;
			W[a][b] = 1;
			W[b][a] = 1;
		}

		for (int k = 0; k < n; k++)
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					W[i][j] = min(W[i][j], W[i][k] + W[k][j]);

		int s, e, ans = 0;
		cin >> s >> e;

		for (int k = 0; k < n; k++)
			ans = max(ans, W[s][k] + W[k][e]);

		cout << "Case " << c++ << ": " << ans << endl;
	}
	return 0;
}