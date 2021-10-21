#include <climits>
#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

int main()
{
	int c;
	cin >> c;
	for (; c--;)
	{
		int n, t, m;
		vector<pair<int, bool>> event;
		cin >> n >> t >> m;
		for (; m--;)
		{
			string s;
			pair<int, bool> temp;
			cin >> temp.first >> s;
			temp.second = (s == "left");
			event.push_back(temp);
		}
		queue<int> left, right, ship;
		int now = 0, arr = INT_MAX, event_c = 0;
		bool atleft = true;
		int times[10000];
		for (; !(event_c == event.size() && left.empty() && right.empty() && ship.empty());)
		{
			if (event_c < (int)event.size() && event[event_c].first <= arr)
			{
				(event[event_c].second ? left : right).push(event_c);
				if (arr == INT_MAX)
					arr = event[event_c].first;
				event_c++;
			}
			else
			{
				for (; !ship.empty();)
				{
					times[ship.front()] = arr;
					ship.pop();
				}
				if (left.empty() && right.empty())
					arr = INT_MAX;
				else
				{
					queue<int>& curr = atleft ? left : right;
					while (!curr.empty() && (int)ship.size() < n) 
					{
						ship.push(curr.front());
						curr.pop();
					}
					arr = arr + t;
					atleft = !atleft;
				}
			}
		}
		for (int i = 0; i < event.size(); i++)
			cout << times[i] << endl;
		if (c) cout << endl;
	}
}
