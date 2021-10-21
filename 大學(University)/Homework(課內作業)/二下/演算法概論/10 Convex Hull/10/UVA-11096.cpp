#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <iomanip>
using namespace std;

struct point {
	double x, y;
	point() {
	}
	point(double _x, double _y) {
		x = _x, y = _y;
	}
};

bool cmp(point a, point b)
{
	return (a.x < b.x) || (a.x == b.x && a.y < b.y);
}

double dist(point p1, point p2) {
	return hypot(p1.x - p2.x, p1.y - p2.y);
}

double perimeter(const vector<point>& P) {
	double result = 0.0;
	for (int i = 0; i < (int)P.size() - 1; i++)
		result += dist(P[i], P[i + 1]);
	return result;
}

double cross(point o, point a, point b) {
	return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}

vector<point> CHAMC(vector<point>& P) {
	if (P.size() <= 3)
		return P;
	vector<point> H;
	sort(P.begin(), P.end(), cmp);
	int n = P.size();
	for (int i = 0; i < n; i++) {
		while (H.size() >= 2
			&& cross(H[H.size() - 2], H[H.size() - 1], P[i]) <= 0)
			H.pop_back();
		H.push_back(P[i]);
	}
	unsigned int l = H.size() + 1;
	for (int i = n - 1; i >= 0; i--) {
		while (H.size() >= l
			&& cross(H[H.size() - 2], H[H.size() - 1], P[i]) <= 0)
			H.pop_back();
		H.push_back(P[i]);
	}
	return H;
}

int main() {
	int tc, n, x, y;
	double initLen, ans;
	vector<point> P;

	cin >> tc;
	while (tc--) {
		P.clear();
		cin >> initLen >> n;
		for (int i = 0; i < n; i++) {
			cin >> x >> y;
			P.push_back(point(x, y));
		}
		P.push_back(P[0]);

		cout << setprecision(5) << fixed;
		cout << max(initLen, perimeter(CHAMC(P))) << endl;

	}

	return 0;
}