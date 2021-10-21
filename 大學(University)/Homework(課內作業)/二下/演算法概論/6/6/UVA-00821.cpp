#include <iostream>
#include <climits>
#include <iomanip>
using namespace std;

int n, W[111][111], D[111][111];

void floyd()
{
	for (int i = 0; i < 111; i++)
		for (int j = 0; j < 111; j++)
			D[i][j] = W[i][j];
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
}

int main()
{
	int a,b,c = 1;
	while (cin >> a >> b)
	{
		if (a == 0 && b == 0) break;
		else
		{
			for (int i = 0; i < 111; i++)
				for (int j = 0; j < 111; j++)
					W[i][j] = 50000;
			for (int i = 0; i < 111; i++)
			{
				W[i][i] = 0;
			}
				

			W[a][b] = 1;
			if (a > n)n = a;
			if (b > n)n = b;
		}
		while (cin >> a >> b)
		{
			if (a == 0 && b == 0) break;
			W[a][b] = 1;
			if (a > n)n = a;
			if (b > n)n = b;
		}
		floyd();
		int sum = 0, co = 0;

		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (D[i][j] < 50000 && D[i][j] != 0)
				{
					sum += D[i][j];
					co++;
				}

		cout << setprecision(3) << fixed;
		cout << sum << " " << co << endl;
		cout << "Case "<<c++<<": average length between pages = "<<(sum+0.0)/(co+0.0)<<" clicks" << endl;
	}

	return 0;
}