#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int main()
{
	int set;
	cin >> set;
	for (int n=0;n<set;n++ )
	{
		int N, S, Q, temp_i;
		cin >> N >> S >> Q;
		stack<int> carrier;
		queue<int> qstation[100];
		for (int i = 0; i < N; i++)
		{
			int gc;
			cin >> gc;
			for (int j = 0; j < gc; j++)
			{
				cin >> temp_i;
				qstation[i].push(temp_i - 1);
			}
		}

		int c_where = 0, time = 0;
		for (; 1;)
		{
			for (; !carrier.empty() && (carrier.top() == c_where || qstation[c_where].size() < Q);) //¨ø³f
			{
				if (carrier.top() != c_where)
				{
					qstation[c_where].push(carrier.top());
				}
				carrier.pop();
				time++;
			}
			for (; carrier.size() < S && !qstation[c_where].empty();) //¸Ë³f
			{
				carrier.push(qstation[c_where].front());
				qstation[c_where].pop();
				time++;
			}
			
			bool clear = carrier.empty();
			for (int i = 0; i < N; i++)
			{
				clear = clear * qstation[i].empty();
			}
			if (clear) break;

			time += 2;
			c_where = (c_where + 1) % N;
		}
		cout << time << endl;
	}
}