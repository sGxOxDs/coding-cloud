#include <iostream>

using namespace std;

int ceil(int a[], int tail[], int low, int high, int key)
{
	while (high-low>1)
	{
		int mid = (high + low) / 2;
		if (a[tail[mid]] >= key)
			high = mid;
		else
			low = mid;
	}

	return high;
}

int ceil2(int a[], int tail[], int low, int high, int key)
{
	while (high - low > 1)
	{
		int mid = (high + low) / 2;
		if (a[tail[mid]] <= key)
			high = mid;
		else
			low = mid;
	}

	return high;
}

int main()
{
	int n;

	while (cin>>n)
	{
		int a[10001] = { 0 };
		for (int i = 1; i <= n; i++)
			cin >> a[i];

		int tail[10001] = { 0 };
		int tail2[10001] = { 0 };
		
		int prev[10001] = { 0 };
		int prev2[10001] = { 0 };

		int length = 1;
		int length2 = 0; //modify

		int lengi[10001] = { 0 }, lengd[10001] = { 0 }; //add

		tail[1] = 1;
		tail2[1] = 1;

		int ans = 1;
		for (int i = 2; i <= n; i++)
		{
			if (a[i] < a[tail[1]])
				tail[1] = i;
			else if (a[i] > a[tail[length]])
			{
				prev[i] = tail[length];
				tail[++length] = i;
			}
			else
			{
				int pos = ceil(a, tail, 0, length, a[i]);
				prev[i] = tail[pos - 1];
				tail[pos] = i;
			}

			if (a[n - i + 2] < a[tail2[0]]) //modify
				tail2[0] = i; //modify
			else if (a[n - i + 2] > a[tail2[length2]]) //modify
			{
				prev2[n - i + 2] = tail2[length2]; //modify
				tail2[++length2] = n - i + 2; //modify
			}
			else
			{
				int pos = ceil(a, tail2, 0, length2, a[n - i + 2]); //modify
				prev2[n - i + 2] = tail2[pos - 1]; //modify
				tail2[pos] = n - i + 2; //modify
			}

			lengi[i] = length; //add
			lengd[n - i + 2] = length2;; //add
		}
		for (int i = 1; i <= n; i++)
			//if (length2 == length) delete
			//	ans = length * 2 - 1; delete
			ans = max(ans, min(lengi[i], lengd[i])); //add

		/*do {
			int tail2[10001] = { 0 };
			int length2 = 1;
			tail2[1] = change[changei][0];
			for (int i = change[changei][0]; i <= n; i++)
			{
				if (a[i] > a[tail2[1]])
					tail2[1] = i;
				else if (a[i] < a[tail2[length2]])
				{
					tail2[++length2] = i;
				}
				else
				{
					int pos = ceil2(a, tail2, 0, length2, a[i]);
					tail2[pos] = i;
				}
			}
			if (change[changei][1] == length2 && length2 * 2 - 1 > ans)
				ans = length2 + change[changei][1] - 1;

		} while (changei--);*/

		//cout << "ans: " << length + length2 << endl;
		cout << 2 * ans - 1 << endl; //modify
	}

	return 0;
}