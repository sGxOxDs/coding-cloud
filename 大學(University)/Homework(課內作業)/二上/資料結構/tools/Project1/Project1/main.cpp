#include <cstdio>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;
#include "Graph.h"

int main()
{
    int N, ans;
    string line;
    while (scanf_s("%d ", &N) && N) {
        Graph G(105);
        // Input
        int a, b;
        while (getline(cin, line)) {
            stringstream ss(line);
            ss >> a;
            if (!a) break;
            while (ss >> b) {
                G.Link(a, b);
            }
        }

        ans = G.CUTPOINTS();

        printf("%d\n", ans);
    }
}