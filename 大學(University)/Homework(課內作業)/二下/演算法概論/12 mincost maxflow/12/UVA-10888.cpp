/*#include <iostream>
#include <string.h>
#include <queue>

using namespace std;

const int maxn = 2000;
const int N = 42;

struct edge
{
	int next, prev;
	int far, son;
	int cap, flow, cost;
};

edge e[maxn];

int h[N], tmp;

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

int fg[45][45][45][45];
int oo = 1e9;

int main()
{
	int case_t;
	cin >> case_t;
	while (case_t--)
	{
		char table[45][45];

		for (int i = 0; i < 45; i++)
			for (int j = 0; j < 45; j++)
				for (int p = 0; p < 45; p++)
					for (int q = 0; q < 45; q++)
					{
						fg[i][j][p][q] = oo;
						if (i == p && j == q)
							fg[i][j][p][q] = 0;
					}


		int x, y;
		cin >> x >> y;
		for (int i = 0; i < x; i++)
			cin >> table[i];

		for (int i = 0; i < x; i++)
			for (int j = 0; j < y; j++)
			{
				if (table[i][j] != '#')
				{
					if (i + 1 < x && table[i + 1][j] != '#')
						fg[i][j][i + 1][j] = fg[i + 1][j][i][j] = 1;
					if (0 <= i - 1 && table[i - 1][j] != '#')
						fg[i][j][i - 1][j] = fg[i - 1][j][i][j] = 1;
					if (j + 1 < y && table[i][j + 1] != '#')
						fg[i][j][i][j + 1] = fg[i][j + 1][i][j] = 1;
					if (0 <= j - 1 && table[i][j - 1] != '#')
						fg[i][j][i][j - 1] = fg[i][j - 1][i][j] = 1;
				}
			}


		for (int i = 0; i < x; i++)
			for (int j = 0; j < y; j++)
				for (int p = 0; p < x; p++)
					for (int q = 0; q < y; q++)
						for (int u = 0; u < x; u++)
							for (int v = 0; v < y; v++)
							{
								fg[p][q][u][v] = min(fg[p][q][u][v], fg[p][q][i][j] + fg[i][j][u][v]);
							}
								

		//cout << "debug: " << endl;
		tmp = 0;
		memset(h, -1, sizeof(h));

		int idb = 0;
		for (int i = 0; i < x; i++)
			for (int j = 0; j < y; j++)
				if (table[i][j] == 'B')
				{ 
					idb++;
					int idx = 20;
					for (int p = 0; p < x; p++)
						for (int q = 0; q < y; q++)
							if (table[p][q] == 'X')
							{
								idx++;
								add(idb, idx, 1, fg[i][j][p][q], 1);
								add(idx, idb, 0, -fg[i][j][p][q], -1);
								cout << i << "/" << j << " to " << p << "/" << q << " = " << fg[i][j][p][q] << endl;
							}
				}
		for (int i = 1; i <= idb; i++)
		{
			add(0, i, 1, 0, 1);
			add(i, 0, 0, 0, -1);

			add(i + 20, 40, 1, 0, 1);
			add(40, i + 20, 0, 0, -1);

			cout << i << endl;
		}
		int flow, cost;
		mcmf(0, 40, flow, cost);

		//cout << "ans: ";
		cout << cost << endl;
	}
	return 0;
}*/

#include <iostream>
#include <string.h>
#include <queue>

using namespace std;

const int maxn = 250000;
const int N = 5000;

struct edge
{
	int next, prev;
	int far, son;
	int cap, flow, cost;
};

edge e[maxn];

int h[N], tmp;

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

//point to int
int ptoi(int x, int y)
{
	return (x * 100 + y);
}
int oo = 1e9;

void link(int x1, int y1, int x2, int y2)
{
	add(ptoi(x1, y1), ptoi(x2, y2), oo, 1, 1);
	add(ptoi(x2, y2), ptoi(x1, y1), 0, -1, -1);
	add(ptoi(x2, y2), ptoi(x1, y1), oo, 1, 1);
	add(ptoi(x1, y1), ptoi(x2, y2), 0, -1, -1);
}

int main()
{
	int case_t;
	cin >> case_t;
	while (case_t--)
	{
		char table[45][45];

		int x, y;
		cin >> x >> y;
		for (int i = 1; i <= x; i++)
			cin >> table[i];

		tmp = 0;
		memset(h, -1, sizeof(h));

		for (int i = 1; i <= x; i++)
			for (int j = 0; j < y; j++)
			{
				if (table[i][j] != '#')
				{
					if (i + 1 <= x && table[i + 1][j] != '#')
					{
						link(i, j, i + 1, j);
					}
					if (1 <= i - 1 && table[i - 1][j] != '#')
					{
						link(i, j, i - 1, j);
					}
					if (j + 1 < y && table[i][j + 1] != '#')
					{
						link(i, j, i, j + 1);
					}
					if (0 <= j - 1 && table[i][j - 1] != '#')
					{
						link(i, j, i, j - 1);
					}
				}
			}

		for (int i = 1; i <= x; i++)
			for (int j = 0; j < y; j++)
			{
				if (table[i][j] == 'B')
				{
					add(0, ptoi(i, j), 1, 0, 1);
					add(ptoi(i, j), 0, 0, 0, -1);
				}
				if (table[i][j] == 'X')
				{
					add(ptoi(i, j), 4545, 1, 0, 1);
					add(4545, ptoi(i, j), 0, 0, -1);
				}
			}

		int flow, cost;
		mcmf(0, 4545, flow, cost);

		//cout << "ans: ";
		cout << cost << endl;
	}

	return 0;
}

/*

1
5 8
BBBB....
.###...X
.XX#...X
...#....
........


1
4 4
...B
.###
....
#..X


*/