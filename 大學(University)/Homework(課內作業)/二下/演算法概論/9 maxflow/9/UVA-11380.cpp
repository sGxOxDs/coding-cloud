#include <iostream>
#include <climits>
#include <string.h>

using namespace std;
/*
//g[2 x y] x y=in  in+4000=out 0=ss 8000=st
int g[8001][8001];
bool seen[8001];

int dfs(int u, int v, int w)
{
	seen[u] = true;
	if (u == v) return w;

	for (int i = 0; i <= 8000; i++)
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
	while ((tmp = dfs(0, 8000, INT_MAX)) > 0)
	{
		res += tmp;
		memset(seen, false, sizeof(seen));
	}
	return res;
}

int main()
{
	int X, Y, P;
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	while (cin >> X)
	{
		cin >> Y >> P;
		memset(g, 0, sizeof(g));
		for (int i = 1; i <= X; i++)
		{
			for (int j = 1; j <= Y; j++)
			{
				char c;
				cin >> c;
				int in, out;
				in = i * 100 + j;
				out = i * 100 + j + 4000;

				if (c == '*')
				{
					g[in][out] = 1;
					g[0][in] = INT_MAX;
				}
				else if (c == '~')
				{
					g[in][out] = 0;
				}
				else if (c == '.')
				{
					g[in][out] = 1;
				}
				else if (c == '@')
				{
					g[in][out] = INT_MAX;
				}
				else if (c == '#')
				{
					g[in][out] = INT_MAX;
					g[out][8000] = P;
				}

				
				out = i * 100 + j + 4000;//i * 100 + j = x y(in) // i * 100 + j + 10000 = 1 x y(out)
				if (i + 1 <= X)
				{
					in = (i + 1) * 100 + j;
					g[out][in] = INT_MAX;
				}
				if (i - 1 >= 1)
				{
					in = (i - 1) * 100 + j;
					g[out][in] = INT_MAX;
				}
				if (j + 1 <= Y)
				{
					in = i * 100 + (j + 1);
					g[out][in] = INT_MAX;
				}
				if (j - 1 >= 1)
				{
					in = i * 100 + (j - 1);
					g[out][in] = INT_MAX;
				}
			}
		}
		//cout << "Ans: ";
		cout << maxflow() << endl;
	}

	return 0;
}*/