#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <climits>
#include <iomanip>
using namespace std;
/*
struct point
{
	double x, y;
};
vector<point> P;

bool cmp(point a, point b)
{
	return (a.x < b.x) || (a.x == b.x && a.y < b.y);
}

double dist(point a,point b)
{
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double mindist(int a,int b)
{
	if (a > b) return INT_MAX;
	int l, r, mid;
	l = r = mid = (a + b) / 2;
	double d = min(mindist(a, mid - 1), mindist(mid + 1, b));
	while (l >= a && d > P[mid].x - P[l].x) l--;
	while (r <= b && d > P[r].x - P[mid].x) r++;
	for (int i = l + 1; i < r; i++)
		for (int j = i + 1; j < r; j++)
			d = min(d, dist(P[i], P[j]));
	return d;
}

int main()
{
	int n;
	while (cin>>n)
	{
		if (n == 0) break;
		P.resize(n);
		for (int i = 0; i < n; i++)
			cin >> P[i].x >> P[i].y;
		sort(P.begin(), P.end(), cmp);
		double d = mindist(0, n - 1);
		//cout << "Ans: ";
		if (d >= 10000)
			cout << "INFINITY" << endl;
		else
			cout << setprecision(4) << fixed << d << endl;
	}
	return 0;
}*/