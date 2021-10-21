#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main()
{
	int c;
	cin >> c;
	for (; c--;)
	{
		int l, m;
		queue<int> left, right, ship;
		cin >> l >> m;
		for (; m--;)
		{
			string s;
			int temp;
			cin >> temp >> s;
			((s == "left") ? left : right).push(temp);
		}
		int cross = 0, carry_length = 0;
		bool atleft = true;
		for (; !(left.empty() && right.empty() && ship.empty());)
		{
			if (!(atleft ? left : right).empty() && carry_length + (atleft ? left : right).front() <= l * 100)
			{
				ship.push((atleft ? left : right).front());
				carry_length += (atleft ? left : right).front();
				(atleft ? left : right).pop();
			}
			else
			{
				cross++;
				for (; !ship.empty();) ship.pop();
				carry_length = 0;
				atleft = !atleft;
			}
		}
		cout << cross << endl;
	}
}
