#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		int builds;
		cin >> builds;

		pair<int, int>* build = new pair<int, int>[builds];
		int* up = new int[builds];
		int* low = new int[builds];

		for (int j = 0; j < builds; j++)
			cin >> build[j].first;
		for (int j = 0; j < builds; j++)
			cin >> build[j].second;

		int in = 0, de = 0;
		for (int j = 0; j < builds; j++)
		{
			up[j] = low[j] = build[j].second;
			for (int k = 0; k < j; k++)
			{
				//cout << "debuga: " << j << "/" << in << "/" << up[j] << endl;
				if (build[k].first < build[j].first && up[j] < up[k] + build[j].second)
					up[j] = up[k] + build[j].second;
				if (build[k].first > build[j].first && low[j] < low[k] + build[j].second)
					low[j] = low[k] + build[j].second;
				//cout << "debugb: " << j << "/" << in << "/" << up[j] << endl;
			}
			if (up[j] > in)
			{
				//cout << "debugc: " << j << "/" << in << "/" << up[j] << endl;
				in = up[j];
				
			}
			if (low[j] > de)de = low[j];
		}

		if (in >= de)
		{
			cout << "Case " << i << ". Increasing (" << in << "). Decreasing (" << de << ")." << endl;
		}
		else
		{
			cout << "Case " << i << ". Decreasing (" << de << "). Increasing (" << in << ")." << endl;
		}

		delete[] build;
		delete[] up;
		delete[] low;
	}
}