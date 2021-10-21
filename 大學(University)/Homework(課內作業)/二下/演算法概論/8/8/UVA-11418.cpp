#include <iostream>
#include <ctype.h>
#include <string.h>
#include <string>
#include <climits>
using namespace std;

string mat[32][32];
int ans[32];
// 0=super_s 99=super_t 1-30=problem 31-60=aclist
int g[100][100] = { 0 };
bool seen[100] = { false };

int dfs(int u, int v, int w)
{
	seen[u] = true;
	if (u == v)
	{
		//cout << u << endl;
		return w;
	}

	for (int i = 0; i < 100; i++)
	{
		if (!seen[i] && g[u][i] > 0)
		{
			//cout << u << "-> "; // u-> i
			int res = dfs(i, v, min(w, g[u][i]));
			
			if (res > 0)
			{
				g[u][i] -= res;
				g[i][u] += res;
				if (u >= 1 && u <= 30 && i >= 31 && i <= 60)
					ans[u] = i;
				return res;
			}
		}
	}
	return 0;
}

int maxflow()
{
	int res = 0, tmp;
	memset(seen, false, sizeof(seen));
	while (tmp = dfs(0, 99, INT_MAX) > 0)
	{
		res += tmp;
		memset(seen, false, sizeof(seen));
	}
	return res;
}

int main()
{
	int id = 1;
	int N, n, k[32];
	cin >> N;
	while (N--)
	{
		cin >> n;
		memset(g, 0, sizeof(g));
		memset(k, 0, sizeof(k));
		memset(ans, -1, sizeof(ans));
		for (int i = 0; i < 32; i++)
			for (int j = 0; j < 32; j++)
				mat[i][j] = "";

		for (int i = 1; i <= 26; i++)
			g[0][i] = 1;

		for (int i = 1; i <= n; i++)
		{
			cin >> k[i];
			for (int j = 1; j <= k[i]; j++)
			{
				cin >> mat[i][j];
				
				for (int p = 0; p < mat[i][j].size(); p++)
				{
					if (p == 0)
						mat[i][j][p] = toupper(mat[i][j].c_str()[p]);
					else
						mat[i][j][p] = tolower(mat[i][j][p]);
				}
				g[mat[i][j][0] - 'A' + 1][i + 30] = 1;
			}
			g[i + 30][99] = 1;
		}
		int mf = maxflow();
		cout << "Case #" << id++ <<":"<< endl;
		//cout << "maxflow = " << mf << endl;
		for (int i = 1; i <= mf; i++)
		{
			//cout << ans[i] << endl;
			for (int j = 1; j <= k[ans[i] - 30]; j++)
			{
				if (mat[ans[i] - 30][j][0] == 'A' + i - 1)
				{
					cout << mat[ans[i] - 30][j] << endl;
					break;
				}
			}
			
		}
			
	}
	return 0;
}
/*
#include <iostream>
#include <stdio.h>
#include <string.h>
#define toupper(x) (x >= 'a' ? x-'a'+'A' : x)
#define tolower(x) (x >= 'a' ? x : x-'A'+'a')
int g[100][100], gt[100];
int mx[100], my[100], used[100];
int dfs(int x) {
	int i, y;
	for (i = 0; i < gt[x]; i++) {
		y = g[x][i];
		if (!used[y]) {
			used[y] = 1;
			if (my[y] == 0 || dfs(my[y])) {
				mx[x] = y, my[y] = x;
				return 1;
			}
		}
	}
	return 0;
}
int main() {
	int test;
	scanf_s("%d", &test);
	int n, K[30], i, j, k, cases = 0;
	char word[30][30][100];
	while (test--) {
		scanf_s("%d", &n);
		memset(gt, 0, sizeof(gt));
		memset(mx, 0, sizeof(mx));
		memset(my, 0, sizeof(my));
		for (i = 1; i <= n; i++) {
			scanf_s("%d", &K[i]);
			for (j = 0; j < K[i]; j++) {
				std::cin >> word[i][j];
				int x = i, y = 30 + (word[i][j][0] >= 'a' ? word[i][j][0] - 'a' : word[i][j][0] - 'A');
				g[y][gt[y]++] = x;
				printf("%d %d\n", i, g[i][gt[i]]);
			}
		}
		int ans = 0;
		for (i = 30; i < 30 + n; i++) {
			if (!mx[i]) {
				memset(used, 0, sizeof(used));
				if (dfs(i))
					ans++;
			}
		}
		printf("Case #%d:\n", ++cases);
		for (i = 30; i < 30 + n; i++) {
			for (j = 0; j < K[mx[i]]; j++) {
				if (tolower(word[mx[i]][j][0]) == i - 30 + 'a') {
					printf("%c", toupper(word[mx[i]][j][0]));
					for (k = 1; word[mx[i]][j][k]; k++)
						printf("%c", tolower(word[mx[i]][j][k]));
					puts("");
					break;
				}
			}
		}
	}
	return 0;
}*/