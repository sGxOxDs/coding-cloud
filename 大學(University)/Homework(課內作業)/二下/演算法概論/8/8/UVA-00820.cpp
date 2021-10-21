#include <iostream>
#include <climits>
using namespace std;

int flow[101][101] = { 0 };
bool seen[101] = { false };
int n, s, t, c;

int dfs(int u, int v, int w)
{
	seen[u] = true;
	if (u == v) return w;

	for (int i = 1; i <= n; i++)
	{
		if (flow[u][i] > 0 && !seen[i] )
		{
			int res = 0;
			if (res = (dfs(i, v, min(w, flow[u][i])) > 0))
			{
				flow[u][i] -= res;
				flow[i][u] += res;
				return res;
			}
		}
	}
	return 0;
}

int maxflow()
{
	int res = 0, tmp = 0;

	while (tmp = (dfs(s, t, INT_MAX) > 0))
	{
		res += tmp;
		memset(seen, false, sizeof(seen));
	}

	return res;
}


int main()
{
	int id = 1;
	while (cin >> n)
	{
		if (n == 0) break;
		memset(flow, 0, sizeof(flow));
		memset(seen, false, sizeof(seen));

		cin >> s >> t >> c;
		for (int i = 1; i <= c; i++)
		{
			int a, b, w;
			cin >> a >> b >> w;
			flow[b][a] = flow[a][b] = w;
		}

		cout << "Network " << id++ << endl;
		cout << "The bandwidth is " << maxflow() << endl;
	}
	return 0;
}