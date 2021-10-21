#include <iostream>
#include <climits>
#include <string.h>

using namespace std;
/*
// 0=ss 1-100=in 101-200=out 201=st
int g[250][250];
bool seen[250];

int dfs(int u, int v, int w)
{
	seen[u] = true;
	if (u == v) return w;

	for (int i = 0; i <= 201; i++)
	{
		if (!seen[i] && g[u][i] > 0)
		{
			int res = dfs(i, v, min(w, g[u][i]));
			if (res > 0)
			{
				g[u][i] -= res;
				g[i][u] += res;
				return res;
			}
		}
	}
	return 0;
}

int maxflow()
{
	int tmp = 0, res = 0;
	memset(seen, false, sizeof(seen));
	while ((tmp = dfs(0, 201, INT_MAX)) > 0)
	{
		res += tmp;
		memset(seen, false, sizeof(seen));
	}
	return res;
}

int main()
{
	int N, M;
	int I, J, C;

	while (cin >> N)
	{
		memset(g, 0, sizeof(g));
		for (int i = 1; i <= N; i++)
		{
			int tmp;
			cin >> tmp;
			g[i][i + 100] = tmp;
		}
			

		cin >> M;

		for (int i = 1; i <= M; i++)
		{
			cin >> I >> J >> C;
			g[I + 100][J] += C;
		}
		int B, D;
		cin >> B >> D;
		for (int i = 1; i <= B; i++)
		{
			int tmp;
			cin >> tmp;
			g[0][tmp] = INT_MAX;
		}
		for (int i = 1; i <= D; i++)
		{
			int tmp;
			cin >> tmp;
			g[tmp + 100][201] = INT_MAX;
		}
		//cout << "Ans: ";
		cout << maxflow() << endl;
	}
	return 0;
}*/