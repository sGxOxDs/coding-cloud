#include <iostream>
#include <climits>
using namespace std;


int main()
{
	int n;
	long long c[30001],d[6];
	
	d[1] = 1;
	d[2] = 5;
	d[3] = 10;
	d[4] = 25;
	d[5] = 50;

	for (int j = 0; j < 30001; j++)
		c[j] = 0;
	c[1] = 1;
	for (int i = 1; i < 6; i++)
	{
		for (int j = d[i]; j < 30001; j++)
			c[j] += c[j - d[i]];
	}


	while (cin >> n)
	{
		if (c[n] == 1)
		{
			cout << "There is only 1 way to produce " << n << " cents change." << endl;
		}
		else
		{
			cout << "There are " << c[n] << " ways to produce " << n << " cents change." << endl;
		}
	}

	return 0;
}