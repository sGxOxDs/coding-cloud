#include <iostream>
#include <queue>

using namespace std;

int main()
{
	int n;
	priority_queue<int,vector<int>,greater<int>> ipq;
	for (; cin >> n;)
	{
		if (n == 0)
			break;
		int temp;
		for (int i = 0; i < n; i++)
		{
			cin >> temp;
			ipq.push(temp);
		}
		int ans = 0;

		for (;1;)//(int i = 0; i < n-1 && ipq.size()>1; i++)
		{
			temp = ipq.top();
			ipq.pop();
			temp += ipq.top();
			ipq.pop();
			ans += temp;
			if (ipq.empty())
				break;
			ipq.push(temp);
		}
		cout << ans << endl;
	}
}