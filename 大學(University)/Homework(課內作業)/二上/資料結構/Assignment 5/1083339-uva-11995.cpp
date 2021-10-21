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
		queue<int> q;
		priority_queue<int> pq;
		int flag, in, c = 0, sc = 0, qc = 0, pqc = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> flag >> in;
			if (flag == 1)
			{
				s.push(in);
				q.push(in);
				pq.push(in);
			}
			else
			{
				if (!s.empty() && in == s.top())
				{
					sc++;
					s.pop();
				}
				if (!q.empty() && in == q.front())
				{
					qc++;
					q.pop();
				}
				if (!pq.empty() && in == pq.top())
				{
					pqc++;
					pq.pop();
				}
				c++;
			}
		}
		if (c != sc && c != qc && c != pqc)
		{
			cout << "impossible" << endl;
		}
		else if ((c == sc && c == qc) || (c == pqc && c == sc) || (c == qc && c == pqc))
		{
			cout << "not sure" << endl;
		}
		else if (c == sc)
		{
			cout << "stack" << endl;
		}
		else if (c == qc)
		{
			cout << "queue" << endl;
		}
		else if (c == pqc)
		{
			cout << "priority queue" << endl;
		}
	}
}