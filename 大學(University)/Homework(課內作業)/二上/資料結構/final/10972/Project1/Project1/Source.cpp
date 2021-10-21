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
        if (!vis[v]) //����
        {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] > dfn[u]) //���@�Ӿ�,�s�W�@�ӳs�q���q
                bcnt++;
        }
        else  if (vis[v] == 1) //��V��
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
    if (bcnt == 1) //��ӹϥ����N�O�����s�q���q
    {
        cout << 0 << endl; return;
    }

    bool used[N];
    memset(used, false, sizeof(used));
    for (int i = 1; i <= n; i++)
    {
        if (e[i].size() == 0) //�t���I�A���ۨ��Φ��@�ӳs�q���q
        {
            used[low[i]] = true; continue;
        }

        for (int j = 0; j < e[i].size(); j++)
        {
            int u = i;
            int v = e[i][j];
            used[low[u]] = used[low[v]] = true;
            if (low[u] != low[v]) //���P���s�q���q
                de[low[u]]++;
        }
    }

    int res = 0;
    for (int i = 1; i <= n; i++)   //���y�Y�I��C���I����
        if (used[i] && de[i] == 0) //�׬�0�Y�t���I
            res += 2;
        else  if (de[i] == 1) //���l
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
            //���i������vector�عϤ����R�A����F
        }
        solve();
    }
    return  0;
}