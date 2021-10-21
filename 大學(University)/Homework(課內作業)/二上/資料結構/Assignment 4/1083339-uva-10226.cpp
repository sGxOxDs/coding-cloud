#include <iostream>
#include <map>
#include <iomanip>
#include <string>
using namespace std;


int main()
{
	int N;
	for (; cin >> N;)
	{
		getchar(); // for '\n'
		string temp;
		getline(cin, temp); // for blank line
		for (int i=0; N > 0; N--,i=1)
		{
			if (i != 0)
				cout << endl;
			map<string, int> m;
			int total = 0;
			for (; getline(cin, temp) && temp != ""; m[temp]++, total++);
			
			for (auto a = m.begin(); a != m.end(); a++)
			{
				cout << setprecision(4) << fixed;
				cout << a->first << " " << (a->second + 0.0) / (total + 0.0) * 100.0 << endl;
			}
		}
	}
	return 0;
	
}