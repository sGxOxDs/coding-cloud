#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main()
{
	int n;
	for (; cin >> n;)
	{
		stack<int> s;
		queue<int> qin;
		int temp=0;
		for (; cin >> temp; )
		{
			if (temp == 0)
			{
				cout << endl;
				break;
			}
			qin.push(temp);
			if (qin.size() == n)
			{
				for (int i = 1; i <= n; i++)
				{
					s.push(i);
					for (; !qin.empty() && !s.empty() && qin.front() == s.top();)
					{
						qin.pop();
						s.pop();
					}
				}
				if (s.empty())
					cout << "Yes" << endl;
				else
					cout << "No" << endl;
				for (; !s.empty(); s.pop());
				for (; !qin.empty(); qin.pop());
			}
		}
	}
}