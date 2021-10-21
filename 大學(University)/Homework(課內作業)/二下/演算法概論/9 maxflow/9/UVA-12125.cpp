#include <iostream>
#include <climits>
#include <string.h>

using namespace std;

struct Ice
{
	int x, y, p, j;
};

bool can_jump(Ice i1, Ice i2, float max)
{
	return max * max >= (i1.x - i2.x) * (i1.x - i2.x) + (i1.y - i2.y) * (i1.y - i2.y);
}

int N;
// 0=ss 1-100=in 101-200=out;
int g[201][201];
int mf[201][201];
bool seen[201];

int dfs(int u, int v, int w)
{
	seen[u] = true;
	if (u == v) return w;
	for (int i = 0; i <= 200; i++)
	{
		if (!seen[i] && mf[u][i] > 0)
		{
			int res = dfs(i, v, min(w, mf[u][i]));
			if (res > 0)
			{
				mf[u][i] -= res;
				mf[i][u] += res;
				return res;
			}
		}
	}
	return 0;
}

int maxflow(int t)
{
	int tmp, res = 0;
	memset(seen, false, sizeof(seen));
	while ((tmp = dfs(0, t, INT_MAX)) > 0)
	{
		res += tmp;
		memset(seen, false, sizeof(seen));
	}
	return res;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		float D;
		cin >> N >> D;

		memset(g, 0, sizeof(g));
		Ice ice[101];
		int allp = 0;
		for (int i = 1; i <= N; i++)
		{
			cin >> ice[i].x >> ice[i].y >> ice[i].p >> ice[i].j;
			allp += ice[i].p;
			g[i][i + 100] = ice[i].j;

			if (ice[i].p > 0)
			{
				g[0][i] = ice[i].p;
			}

			for (int j = 1; j < i; j++)
			{
				if (can_jump(ice[i], ice[j], D))
				{
					g[i + 100][j] = g[j + 100][i] = INT_MAX;
				}
			}
		}
		int ans[101] = { 0 };
		int acount = 0;
		for (int i = 1; i <= N; i++)
		{
			for (int p = 0; p <= 200; p++)
				for (int q = 0; q <= 200; q++)
					mf[p][q] = g[p][q];
			if (allp == maxflow(i))
			{
				ans[acount++] = i-1;
			}
		}

		//cout << "Ans: ";
		if (acount == 0)
			cout << "-1" << endl;
		else
		{
			cout << ans[0];
			for (int i = 1; i < acount; i++)
				cout << " " << ans[i];
			cout << endl;
		}

	}
	return 0;
}