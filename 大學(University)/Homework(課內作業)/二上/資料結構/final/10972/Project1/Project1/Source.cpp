#include <iostream> 
#include <cstdio> 
#include <cstring> 
#include <stack> 
#include <vector>
using  namespace std;
#define N 1010

int n, tot;
int dfn[N], low[N], vis[N], de[N], dcnt, bcnt;
vector < int > e[N];

void init()
{
    dcnt = bcnt = 0;
    for (int i = 1; i <= n; i++)
    {
        dfn[i] = 0;
        e[i].clear();
        vis[i] = de[i] = 0;
    }
}

void dfs(int u, int fa)
{
    dfn[u] = low[u] = ++dcnt;
    vis[u] = 1;
    for (int i = 0; i < e[u].size(); i++)
    {
        int v = e[u][i];
        if (v == fa) continue;
        if (!vis[v]) //樹邊
        {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] > dfn[u]) //找到一個橋,新增一個連通分量
                bcnt++;
        }
        else  if (vis[v] == 1) //後向邊
            low[u] = min(low[u], dfn[v]);
    }
}

void solve()
{
    for (int i = 1; i <= n; i++)
        if (!vis[i])
        {
            dfs(i, -1);
            bcnt++;
        }
    if (bcnt == 1) //整個圖本身就是個雙連通分量
    {
        cout << 0 << endl; return;
    }

    bool used[N];
    memset(used, false, sizeof(used));
    for (int i = 1; i <= n; i++)
    {
        if (e[i].size() == 0) //孤立點，它自身形成一個連通分量
        {
            used[low[i]] = true; continue;
        }

        for (int j = 0; j < e[i].size(); j++)
        {
            int u = i;
            int v = e[i][j];
            used[low[u]] = used[low[v]] = true;
            if (low[u] != low[v]) //不同的連通分量
                de[low[u]]++;
        }
    }

    int res = 0;
    for (int i = 1; i <= n; i++)   //掃描縮點後每個點的度
        if (used[i] && de[i] == 0) //度為0即孤立點
            res += 2;
        else  if (de[i] == 1) //葉子
            res++;
    cout << (res + 1) / 2 << endl;
}

int main()
{
    while (cin >> n >> tot)
    {
        init();
        while (tot--)
        {
            int u, v;
            cin >> u >> v;
            e[u].push_back(v);
            e[v].push_back(u);
            //偷懶直接用vector建圖不用靜態鍊錶了
        }
        solve();
    }
    return  0;
}