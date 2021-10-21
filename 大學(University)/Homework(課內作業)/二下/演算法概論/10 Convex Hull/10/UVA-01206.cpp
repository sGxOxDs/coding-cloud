#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
#include <iomanip>
using namespace std;
/*
struct Point
{
	double x, y;
};


double cross(Point o, Point a, Point b)
{
	return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}

bool cmp(Point a, Point b)
{
	return (a.x < b.x) || (a.x == b.x && a.y < b.y);
}

void amc(vector<Point> &P, vector<Point>& L, vector<Point>& U)
{
	sort(P.begin(), P.end(), cmp);
	//cout << "=== P ===" << endl;
	//for (int i = 0; i < P.size(); i++)
	//{
	//	cout << P[i].x << " " << P[i].y << endl;
	//}
	//cout << "=== P ===" << endl;
	L.clear();
	U.clear();
	for (int i = 0; i < P.size(); i++)
	{
		while (L.size() >= 2 && cross(L[L.size() - 2], L[L.size() - 1], P[i]) <= 0)
			L.pop_back();
		while (U.size() >= 2 && cross(U[U.size() - 2], U[U.size() - 1], P[i]) >= 0)
			U.pop_back();
		L.push_back(P[i]);
		U.push_back(P[i]);
	}
}

int main()
{
	string s, stmp;
	while (getline(cin, s))
	{
		stringstream ss;
		ss << s;
		vector<Point> P, L, U;
		while (getline(ss, stmp, '('))
		{
			Point ptmp;
			getline(ss, stmp, ',');
			ptmp.x = stod(stmp);
			getline(ss, stmp, ')');
			ptmp.y = stod(stmp);
			P.push_back(ptmp);
		}
		amc(P,L,U);
		//cout << "=V=V= ans =V=V=" << endl;
		cout << setprecision(3) << fixed;
		for (int i = 0; i < U.size(); i++)
		{
			if (i)
				cout << " ";
			cout << "(" << U[i].x << "," << U[i].y << ")";
		}
		for (int i = L.size() - 2; i >= 0; i--)
		{
			//if (i)
			cout << " ";
			cout << "(" << L[i].x << "," << L[i].y << ")";
			
		}
		cout << endl;
		//cout << "=^=^= ans =^=^=" << endl;
	}
	
	return 0;
}*/