#include <iostream>
#include <sstream>
#include <string>
#include <climits>
using namespace std;



int main()
{
	int line;
	while (cin>>line)
	{
		if (line == 0)break;
		int map[2][27][27];
		int oo = 999999;
		for (int s = 0; s < 2; s++)
			for (int i = 0; i < 27; i++)
				for (int j = 0; j < 27; j++)
				{
					map[s][i][j] = oo;
					if (i == j)
						map[s][i][j] = 0;
				}

		for (int i = 0; i < line; i++)
		{
			char a, b, p, m;
			int j, s;

			cin >> p >> m >> a >> b >> j;

			s = (p == 'Y') ? 0 : 1;
			map[s][a - 'A'][b - 'A'] = j;
			if (m == 'B')
				map[s][b - 'A'][a - 'A'] = j;

		}
		for (int s = 0; s < 2; s++)
			for (int k = 0; k < 26; k++)
				for (int i = 0; i < 26; i++)
					for (int j = 0; j < 26; j++)
						map[s][i][j] = min(map[s][i][j], map[s][i][k] + map[s][k][j]);

		char a, b;
		cin >> a >> b;
		int temp = 0, j = a - 'A', k = b - 'A';

		for (int i = 0; i < 26; i++)
			if (map[0][j][i] + map[1][k][i] < map[0][j][temp] + map[1][k][temp])
				temp = i;

		if (map[0][j][temp] + map[1][k][temp] >= oo)
			cout << "You will never meet." << endl;
		else
		{
			cout << map[0][j][temp] + map[1][k][temp];
			for (int i = temp; i < 26; i++)
				if (map[0][j][i] + map[1][k][i] == map[0][j][temp] + map[1][k][temp])
					cout << " " << (char)(i + 'A');
			cout << endl;
		}

	}
	return 0;
}