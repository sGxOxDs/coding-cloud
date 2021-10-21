#include <iostream>
#include <map>
#include <set>
using namespace std;


int main()
{
	int n;
	for (; cin >> n && n != 0;)
	{
		map<set<int>, int> m;
		int courses, maxp = 0, ans = 0;
		for (int i=0;i<n;i++)
		{
			set<int> s;
			for (int j = 0; j < 5; j++)
			{
				cin >> courses;
				s.insert(courses);
			}
			m[s]++;
			maxp = max(maxp, m[s]);
		}
		
		for (auto a = m.begin(); a != m.end(); a++)
			if (a->second == maxp)
				ans += maxp;
			
		cout << ans << endl;
	}
	return 0;

}