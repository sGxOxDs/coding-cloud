#include <iostream>
#include <cstring>
#include<vector>
#include <queue>
#include <algorithm>
using namespace std;

#include <stdio.h>
#include <string.h>

const int MAXN = 50000;
int INF = 1e9;
const int N = 105;

struct edge {
	int next, im;
	int far, son;
	int cap, flow;
	int cost;
}s[MAXN];

int n, m, tmp, h[N];
int K, D;

void add(int x, int y, int c, int cost, int im) {

	s[tmp].next = h[x];
	h[x] = tmp;

	s[tmp].im = tmp + im;
	s[tmp].far = x;
	s[tmp].son = y;
	s[tmp].cap = c;
	s[tmp].flow = 0;
	s[tmp].cost = cost;
	tmp++;
}

void mcmf(long long& flow, long long& cost)
{
	queue<int> que;
	flow = 0;
	cost = 0;
	int u, d[N], vis[N], path[MAXN];

	while (1) {

		for (int i = 0; i <= n + 1; i++) d[i] = (i == 0) ? 0 : INF;
		memset(path, -1, sizeof(path));
		memset(vis, 0, sizeof(vis));

		que.push(0);
		vis[0] = 1;

		while (!que.empty()) {
			u = que.front(), que.pop();
			vis[u] = 0;

			for (int i = h[u]; i != -1; i = s[i].next) {
				int v = s[i].son;
				if (s[i].cap > s[i].flow && d[v] > d[u] + s[i].cost) {
					d[v] = d[u] + s[i].cost;
					path[v] = i;

					if (vis[v] == 0) {
						que.push(v);
						vis[v] = 1;
					}
				}
			}
		}

		if (d[n] == INF)
			break;
		long long a = INF;

		for (int i = n; i; i = s[path[i]].far)
			a = (a > s[path[i]].cap - s[path[i]].flow) ? s[path[i]].cap - s[path[i]].flow : a;
		flow += a;
		cost += a * d[n];

		for (int i = n; i; i = s[path[i]].far) {
			s[path[i]].flow += a;
			int im = s[path[i]].im;
			s[im].flow -= a;
		}
	}
}

int main() {

	while (cin>>n>>m) {
		int a[MAXN], b[MAXN], c[MAXN];

		tmp = 0;
		memset(h, -1, sizeof(h));

		for (int i = 0; i < m; i++)
			cin >> a[i] >> b[i] >> c[i];
		cin >> K >> D;

		add(0, 1, K, 0, 1);
		add(1, 0, 0, 0, -1);

		for (int i = 0; i < m; i++) {

			add(a[i], b[i], D, c[i], 1);
			add(b[i], a[i], 0, -c[i], -1);
			add(b[i], a[i], D, c[i], 1);
			add(a[i], b[i], 0, -c[i], -1);
		}

		long long flow, cost;
		mcmf(flow, cost);
		//cout << "Ans: ";
		if (flow < K)
			cout << "Impossible." << endl;
		else
			cout << cost << endl;
	}

	system("pause");
}

