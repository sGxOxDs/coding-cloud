#include <iostream>

using namespace std;

int main()
{
	int N, Q, D, M, case_count = 0;
	while (cin>>N>>Q)
	{
		if (N == 0 && Q == 0) break;
		cout << "SET " << ++case_count << ":" << endl;
		int set[201] = { 0 };
		

		for (int i = 0; i < N; i++)
			cin >> set[i];
		for (int q = 0; q < Q; q++)
		{
			cin >> D >> M;
			int r[201] = { 0 };
			long long dp[201][12] = { 0 };

			for (int i = 0; i < N; i++)
			{
				r[i] = set[i] % D;
				if (r[i] < 0)
					r[i] += D;
			}

			dp[0][0] = 1;
			for (int k = 0; k < N; k++)
				for (int i = M; i > 0; i--)
					for (int j = 200; j >= r[k]; j--)
					{
						dp[j][i] += dp[j - r[k]][i - 1];
						if (dp[j][i] != 0)
							cout << "dp[" << j << "][" << i << "] = " << dp[j][i] << endl;
					}
						

			long long ans = 0;
			for (int i = 0; i <= 200; i+=D)
				ans += dp[i][M];
			cout << "QUERY " << q + 1 << " : " << ans << endl;
		}

	}
}