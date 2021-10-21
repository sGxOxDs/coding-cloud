#include <iostream>
#include <set>
#include <vector>
using namespace std;


int main()
{
	int testcase;
	cin >> testcase;
	for (; testcase--;)
	{
		
		unsigned long long left=0,n, snow, ans = 0;
		set<unsigned long long> s;
		vector<unsigned long long> v;
		cin >> n;
		for (auto i = 0; i < n; i++)
		{
			cin >> snow;
			v.push_back(snow);
		}
		for (auto i = 0; i < n; i++)
		{
			auto a = s.find(v[i]);
			if (a != s.end())
			{
				while (v[left] != v[i])
				{
					s.erase(v[left++]);
				}
				if (v[left] == v[i])
					s.erase(v[left++]);
			}
			s.insert(v[i]);
			ans = ans > s.size() ? ans : s.size();
		}
		cout << ans << endl;
	}
	return 0;

}