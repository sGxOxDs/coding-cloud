#include <iostream>
#include <climits>
#include <string.h>

using namespace std;
/*
// 1-50=in 51-100=out 1=boss in 100=server out
int g[102][102];
bool seen[102];
int M, W;

int dfs(int u, int v, int w)
{
	seen[u] = true;
	if (u == v) return w;
	for (int i = 0; i <= 101; i++)
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
	int tmp, res = 0;
	memset(seen, false, sizeof(seen));
	while ((tmp = dfs(1, M+50, INT_MAX)) > 0)
	{
		res += tmp;
		memset(seen, false, sizeof(seen));
	}
	return res;
}

int main()
{
	
	while (cin>>M>>W)
	{
		if (M == 0 && W == 0) break;
		memset(g, 0, sizeof(g));

		g[1][51] = INT_MAX;
		g[M][M+50] = INT_MAX;
		for (int i = 0; i < M - 2; i++)
		{
			int id, c;
			cin >> id >> c;
			g[id][id + 50] += c;
		}
		for (int i = 0; i < W; i++)
		{
			int j, k, d;
			cin >> j >> k >> d;
			//if (j > k) swap(j, k);
			g[j + 50][k] += d;
			g[k + 50][j] += d;
		}
		//cout << "Ans: ";
		cout << maxflow() << endl;
	}
	return 0;
}*/