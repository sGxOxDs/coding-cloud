#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int c;
	cin >> c;
	while (c--)
	{
		int n,in;
		vector<int> s;
		cin >> n;
		s.resize(n);
		while (n--)
		{
			cin >> in;
			s.at(n) = in;
		}
		n = s.size();
		int lis[2001], lds[2001];
		for (int i = 0; i < n; i++)
		{
			lis[i] = 1;
			lds[i] = 1;
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				if (s[i] > s[j])
					lis[j] = max(lis[j], lis[i] + 1);
				if (s[i] < s[j])
					lds[j] = max(lds[j], lds[i] + 1);
			}
		}
		int max = 0;
		for (int i = 0; i < n; i++)
			if (max < lis[i] + lds[i] - 1)
				max = lis[i] + lds[i] - 1;
		cout << max << endl;
		//cout << "ans: " << max << endl;
		//cout << "ans: " << ((v.size() < v2.size()) ? v2.size() : v.size()) << endl;
	}

}