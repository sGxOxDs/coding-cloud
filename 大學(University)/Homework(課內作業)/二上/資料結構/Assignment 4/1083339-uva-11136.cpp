#include <iostream>
#include <set>
using namespace std;


int main()
{
	int n;
	
	for (; cin >> n && n != 0;)
	{
		multiset<int> ms;
		unsigned long long total = 0;
		for (int i = 0; i < n; i++)
		{
			int temp, put;
			cin >> put;
			for (int j = 0; j < put; j++)
			{
				cin >> temp;
				ms.insert(temp);
			}
			if (ms.size() >= 2)
			{
				total += ms.rbegin().operator*() - ms.begin().operator*();
				ms.erase(--ms.end());
				ms.erase(ms.begin());
			}
		}
		cout << total << endl;
	}
	return 0;

}