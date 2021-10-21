#include <iostream>
#include <string>
#include <stack>
using namespace std;

string in, out, ans;
int len;
stack<char> temp;
void DFS(int i, int o) 
{
    if (i == len && o == len) 
    {
        for (auto it = ans.begin(); it != ans.end();)
        {
            cout << *it;
            if (++it != ans.end())
                cout << " ";
        }
        cout << endl;
        return;
    }
    if (i < len) 
    {
        temp.push(in[i]);
        ans.push_back('i');
        DFS(i + 1, o);
        ans.pop_back();
        temp.pop();
    }
    if (i > o) 
    {
        if (temp.top() == out[o]) 
        {
            temp.pop();
            ans.push_back('o');
            DFS(i, o + 1);
            ans.pop_back();
            temp.push(out[o]);
        }
    }
}

int main()
{
	for (; cin >> in;)
	{
		cin >> out;
		cout << "[" << endl;
        len = in.length();
		if (in.length() == out.length())
			DFS(0,0);
		cout << "]" << endl;
	}
}