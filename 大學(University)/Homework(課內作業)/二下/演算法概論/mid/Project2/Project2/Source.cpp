#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
#define INF 0x7fffffff
using namespace std;
const int maxn = 10000 + 10;
int a[maxn], g[maxn];
int dpi[maxn], dpd[maxn];

void LIS(int n)
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (!cnt || g[cnt - 1] < a[i])   g[cnt++] = a[i];
        else
        {
            int k = lower_bound(g, g + cnt, a[i]) - g;    //恰好不小于a[i]的元素下标
            g[k] = a[i];
        }
        dpi[i] = cnt;
    }
}

void LDS(int n)
{
    int cnt = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (!cnt || g[cnt - 1] < a[i])   g[cnt++] = a[i];
        else
        {
            int k = lower_bound(g, g + cnt, a[i]) - g;  //恰好不小于a[i]的元素下标
            g[k] = a[i];
        }
        dpd[i] = cnt;
    }
}


int main()
{
    int n, ans;
    while (scanf_s("%d", &n) != EOF)
    {
        ans = 0;
        for (int i = 0; i < n; i++)
            scanf_s("%d", &a[i]);
        LIS(n);
        LDS(n);
        for (int i = 0; i < n; i++)
            ans = max(ans, min(dpi[i], dpd[i]));
        printf("%d\n", ans * 2 - 1);
    }
    return 0;
}
