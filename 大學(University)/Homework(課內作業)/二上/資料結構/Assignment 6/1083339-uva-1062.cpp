#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
	int cc = 1;
	string s;
	for (; cin >> s; cc++)
	{
        if (s == "end")
            break;
        int n = s.size();
        int* dp = new int[n]();
        int ret = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (s[j] > s[i])
                    dp[j] = max(dp[j], dp[i] + 1);
            }
            ret = max(ret, dp[i]);
        }
        cout << "Case " << cc << ": " << ret + 1 << endl;
        delete[] dp;
	}
    return 0;
}

int  solve(string& s)
{
    vector<stack<char> >vs;
    for (int i = 0; i < s.size(); i++) 
    {
        if (vs.empty()) {
            stack<char>st;
            vs.push_back(st);
            vs[0].push(s[i]);
            continue;
        }
        bool flag = false;
        int mini = -1;
        for (int j = 0; j < vs.size(); j++) 
        {
            if (s[i] <= vs[j].top()) 
            {
                flag = true;
                if (mini == -1)
                    mini = j;
                else if (vs[mini].top() > vs[j].top())
                    mini = j;
            }
        }
        if (!flag)
        {
            stack<char>st;
            vs.push_back(st);
            vs[vs.size() - 1].push(s[i]);
        }
        else 
            vs[mini].push(s[i]);
    }
    return vs.size();
}
int main()
{
    string s;
    cin >> s;
    int i = 1;
    while (s != "end") {
        cout << "Case " << i++ << ": " << solve(s) << endl;
        cin >> s;
    }
    return 0;
}