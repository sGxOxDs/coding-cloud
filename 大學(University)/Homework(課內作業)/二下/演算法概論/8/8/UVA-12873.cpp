#include <iostream>
#include <climits>
#include <string.h>
using namespace std;

//g[∂§•Ó][¡…∞œ] 0=super_s 600=super_t
int g[601][601] = { 0 };
bool seen[601] = { false };
int  p, s, c;

int path[601];

int dfs(int u, int v, int w)
{
	seen[u] = true;
	//cout << "dfs u/v:" << u << "/" << v << endl;
	if (u == v)
	{
		cout << v << " ";
		for (int i = path[600]; path[i] != -1; i = path[i])
			cout << i << " ";
		cout << endl;
		return w;
	}

	for (int i = 0; i <= 600; i++)
	{
		if (!seen[i] && g[u][i] > 0)
		{
			path[i] = u;
			int res = dfs(i, v, min(w, g[u][i]));
			path[i] = -1;
			if (res > 0)
			{
				g[u][i] -= res;
				//g[i][u] += res;
				return res;
			}
		}
	}

	return 0;
}

int maxflow()
{
	memset(seen, false, sizeof(seen));
	int res = 0, tmp;
	memset(path, -1, sizeof(path));
	while (tmp = dfs(0, 600, INT_MAX) > 0)
	{
		res += tmp;
		memset(path, -1, sizeof(path));
		memset(seen, false, sizeof(seen));
	}
	return res;
}

int main()
{
	int n, m;
	cin >> n;
	while (n--)
	{
		memset(g, 0, sizeof(g));
		cin >> p >> s >> c >> m;
		for (int i = 0; i < m; i++)
		{
			int a, b;
			cin >> a >> b;
			//g[a][b + 510] = g[b + 510][a] = 1;
			//g[b + 510][b + 540] = g[b + 540][b + 510] = c;
			//g[0][a] = g[a][0] = 1;
			//g[b + 540][600] = g[600][b + 540] = INT_MAX;
			g[a][b + 510] = 1;
			g[b + 510][b + 540] = c;
			g[0][a] = 1;
			g[b + 540][600] = INT_MAX;
		}
		/*cout << "===after===" << endl;
		for (int i = 0; i <= 600; i++)
		{
			for (int j = i; j <= 600; j++)
			{
				if (g[i][j] > 0)
					cout << "g[" << i << "][" << j << "]=" << g[i][j] << endl;
			}
		}
		cout << "===after===" << endl;*/

		cout << maxflow() << endl;

		/*cout << "===befor===" << endl;
		for (int i = 0; i <= 600; i++)
		{
			for (int j = i; j <= 600; j++)
			{
				if (g[i][j] > 0)
					cout << "g[" << i << "][" << j << "]=" << g[i][j] << endl;
			}
		}
		cout << "===befor===" << endl;*/
	}
	return 0;
}