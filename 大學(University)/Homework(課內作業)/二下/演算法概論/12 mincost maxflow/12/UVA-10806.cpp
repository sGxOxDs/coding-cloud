#include <iostream>
#include <queue>
#include <string.h>
/*#define maxn 10000
#define N 110
using namespace std;


struct edge
{
	int next, prev;
	int far, son;
	int cap, flow, cost;
};

edge e[maxn];

int h[N],tmp;

void add(int x, int y, int c, int cost, int prev)
{
	e[tmp].next = h[x];
	h[x] = tmp;

	e[tmp].prev = tmp + prev;
	e[tmp].far = x;
	e[tmp].son = y;
	e[tmp].cap = c;
	e[tmp].flow = 0;
	e[tmp].cost = cost;
	tmp++;
}
void mcmf(int s, int t, int& flow, int& cost)
{
	queue<int> que;
	flow = 0; cost = 0;
	int u, d[N], path[maxn];
	bool seen[N];
	while (true)
	{
		for (int i = 0; i <= t + 1; i++)
			d[i] = (i == 0) ? 0 : 1e9;
		memset(path, -1, sizeof(path));
		memset(seen, false, sizeof(seen));
		que.push(s);
		seen[s] = true;

		while (!que.empty())
		{
			u = que.front();
			que.pop();
			seen[u] = false;

			for (int i = h[u]; i != -1; i = e[i].next)
			{
				int v = e[i].son;
				if (e[i].cap > e[i].flow && d[v] > d[u] + e[i].cost)
				{
					d[v] = d[u] + e[i].cost;
					path[v] = i;
					if (!seen[v])
					{
						que.push(v);
						seen[v] = true;
					}
				}
			}
		}
		if (d[t] == 1e9)
			break;
		int a = 1e9;
		for (int i = t; i != s; i = e[path[i]].far)
		{
			a = min(a, e[path[i]].cap - e[path[i]].flow);
		}
		flow += a;
		cost += a * d[t];

		for (int i = t; i != s; i = e[path[i]].far)
		{
			e[path[i]].flow += a;
			int prev = e[path[i]].prev;
			e[prev].flow -= a;
		}
	}
}

int main()
{

	int node, m;
	while (cin>>node)
	{
		if (node == 0) break;
		cin >> m;
		int a, b, c;

		tmp = 0;
		memset(h, -1, sizeof(h));

		for (int i = 0; i < m; i++)
		{
			cin >> a >> b >> c;
			add(a, b, 1, c, 1);
			add(b, a, 0, -c, -1);
			add(b, a, 1, c, 1);
			add(a, b, 0, -c, -1);
		}
		add(0, 1, 2, 0, 1);
		add(1, 0, 0, 0, -1);
		int flow, cost;
		mcmf(0, node, flow, cost);
		//cout << "Ans: ";
		if (flow == 2)
			cout << cost << endl;
		else
			cout << "Back to jail" << endl;
	}
	

	return 0;
}*/