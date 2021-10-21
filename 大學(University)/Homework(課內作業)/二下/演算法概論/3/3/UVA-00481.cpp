#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n, posi = 1;
	vector<int> s,v,pos,ans;
	vector<int>::iterator wh;
	while (cin>>n)
	{
		s.push_back(n);
	}
	for (int i = 0; i < s.size(); i++)
	{
		n = s[i];
		if (!v.empty())
		{
			wh = v.end();
			wh--;
		}
		if (v.empty() || *wh < n)
		{
			v.push_back(n);
			posi = v.size();
		}
		else
		{
			for (wh = v.begin(), posi = 1; *wh < n && wh != v.end(); wh++, posi++);
			*wh = n;
		}
		pos.push_back(posi);
	}
	int count = v.size();
	for (auto a = pos.rbegin(), b = s.rbegin(); a != pos.rend(); a++, b++)
	{
		if (*a == count)
		{
			ans.push_back(*b);
			count--;
		}
	}
	cout << v.size() << endl;
	cout << "-" << endl;
	for (auto a = ans.rbegin(); a != ans.rend(); a++)
		cout << *a << endl;
}