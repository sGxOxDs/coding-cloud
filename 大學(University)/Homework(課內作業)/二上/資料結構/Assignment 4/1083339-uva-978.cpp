#include <iostream>
#include <set>
using namespace std;


int main()
{
	int N,B,SG,SB;
	while (cin >> N)
	{
		for (int i = 0; i < N; i++)
		{
			if (i != 0)
				cout << endl;
			multiset<int> green;
			multiset<int> blue;
			cin >> B >> SG >> SB;
			for (int j = 0; j < SG; j++)
			{
				int temp;
				cin >> temp;
				green.insert(green.end(), temp);
			}
			for (int j = 0; j < SB; j++)
			{
				int temp;
				cin >> temp;
				blue.insert(blue.end(), temp);
			}

			while (!green.empty() && !blue.empty()) {
				int size = 0;
				int* battlefields = new int[B]();
				for (int i = 0; i < B; ++i) {
					if (green.empty() || blue.empty()) {
						break;
					}
					battlefields[size++] = *green.rbegin() - *blue.rbegin();
					green.erase(green.lower_bound(*green.rbegin()));
					blue.erase(blue.lower_bound(*blue.rbegin()));
				}
				for (int i = 0; i < size; ++i) {
					if (battlefields[i] > 0) {
						green.insert(battlefields[i]);
					}
					else if (battlefields[i] < 0) {
						blue.insert(-battlefields[i]);
					}
				}
			}

			/*for (; !green.empty() && !blue.empty();)
			{
				int* battle = new int[B]();
				auto ga = green.begin();
				auto ba = blue.begin();
				for (int j = 0; j < B; j++)
				{
					if (green.empty() || blue.empty()) break;
					battle[j] = *ga - *ba;
					ga = green.erase(ga);
					ba = blue.erase(ba);
				}
				for (int j = 0; j < B; j++)
				{
					if (battle[j] > 0)
						green.insert(green.begin(), battle[j]);
					else if (battle[j] < 0)
						blue.insert(blue.begin(), -battle[j]);
				}
			}*/
			if (green.empty() && blue.empty())
				cout << "green and blue died"<< endl;
			else if (green.empty())
			{
				cout << "blue wins"<< endl;
				for (auto a = blue.rbegin(); a != blue.rend(); a++)
					cout << *a << endl;
			}
			else
			{
				cout << "green wins" << endl;
				for (auto a = green.rbegin(); a != green.rend(); a++)
					cout << *a << endl;
			}
			
		}
	}
	
	return 0;
}
