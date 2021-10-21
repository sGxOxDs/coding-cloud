#include <iostream>
#include <list>

using namespace std;

int main()
{
	int p, c, t = 1, ulimit;
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	for (; cin >> p >> c /*scanf_s("%d %d", &p, &c)*/;)
	{
		if (p == 0 && c == 0)
			break;
		if (p > 1000) ulimit = 1000;
		else ulimit = p;
		list<int> l;
		for (int i=1;i<= ulimit;i++)
		{
			l.push_back(i);
		}
		auto it = l.begin();
		char temp_c;
		int temp_i;
		//printf_s("Case %d:\n", t++);
		cout << "Case " << t++ << ":" << '\n';
		for (int i = 1; i <= c; i++)
		{
			//scanf_s("%c", &temp_c);
			cin >> temp_c;
			if (temp_c == 'N')
			{
				//printf_s("%d\n", l.front());
				cout << l.front() << '\n';
				l.push_back(l.front());
				l.pop_front();
			}
			else
			{
				//scanf_s("%n", &temp_i);
				cin >> temp_i;
				l.remove(temp_i);
				l.push_front(temp_i);
			}
		}
	}
}

