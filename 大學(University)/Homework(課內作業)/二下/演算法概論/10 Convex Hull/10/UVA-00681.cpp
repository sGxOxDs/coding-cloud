#include <iostream>
#include <algorithm>
/*
#define Num 520

using namespace std;

struct Point
{
	int x, y;
} P[Num], L[Num], U[Num];
int l, u;

double cross(Point o, Point a, Point b)
{
	return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}

bool compare(Point a, Point b)
{
	return (a.y < b.y) || (a.y == b.y && a.x < b.x);
}

void amc(int n)
{
	sort(P, P + n, compare);

	l = 0;
	u = 0;
	for (int i = 0; i < n; i++)
	{
		while (l >= 2 && cross(L[l - 2], L[l - 1], P[i]) <= 0)
			l--;
		while (u >= 2 && cross(U[u - 2], U[u - 1], P[i]) >= 0)
			u--;
		L[l++] = P[i];
		U[u++] = P[i];
	}
}

int main()
{
	int k;
	cin >> k;
	cout << k << endl;
	while (k--)
	{
		int n;
		cin >> n;
		for (int i = 0; i < Num; i++)
		{
			P[i] = L[i] = U[i] = { 0,0 };
		}
		for (int i = 0; i < n; i++)
		{
			cin >> P[i].x >> P[i].y;
		}
		amc(n);
		if (k)
			cin >> n;
		//cout << "=====ans=====" << endl;
		if (l + u - 2 < 2)
		{
			cout << "0" << endl;
		}
		else
		{
			cout << l + u - 1 << endl;
			for (int i = 0; i < l; i++)
			{
				cout << L[i].x << " " << L[i].y << endl;
			}
			for (int i = u - 2; i >= 0; i--)
			{
				cout << U[i].x << " " << U[i].y << endl;
			}
			//cout << "=====ans=====" << endl;
		}
		if (k)
			cout << "-1" << endl;
	}
	return 0;
}*/