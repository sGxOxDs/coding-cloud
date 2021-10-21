#include <iostream>
#include <deque>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cstdio>
using namespace std;

struct Graph_Node
{
	using size_type = size_t;
	size_type d;
	Graph_Node* pi = nullptr;
	size_type low;
	size_type num;
};

class Graph
{
	using value_type = Graph_Node;
	using pointer = value_type*;
	using multptr = pointer*;
	using size_type = size_t;
public:
	Graph(size_type);
	~Graph();
	void Link(int, int);
	void DFS();
	vector< pair<int, int> > BRIDGE();
	int CUTPOINTS();
private:
	void DFS(value_type&);
	void BRIDGE(value_type&, vector<pair<int, int>>&);
	void CUTPOINTS(value_type&);

private:
	multptr mygraph;
	size_type max_node;
	size_type time;
	vector<int>* edge;
};

Graph::Graph(size_type n)
{
    max_node = n;
    edge = new vector<int>[max_node];
    mygraph = new pointer[max_node];
    for (size_type i = 0; i < max_node; i++)
        mygraph[i] = new value_type;
    for (size_type i = 0; i < max_node; i++)
        mygraph[i]->num = i;
    time = 0;
}

Graph::~Graph()
{
    delete[] edge;
    for (size_type i = 0; i < max_node; i++)
        delete mygraph[i];
    delete[] mygraph;
}

void Graph::Link(int a, int b)
{
    edge[a].push_back(b);
    edge[b].push_back(a);
}

vector<pair<int, int>> Graph::BRIDGE()
{
    vector< pair<int, int> > ans;
    for (size_type i = 0; i < max_node; i++)
    {
        mygraph[i]->d = 0;
        mygraph[i]->pi = nullptr;
    }
    time = 0;
    for (size_type i = 0; i < max_node; i++)
        if (mygraph[i]->d == 0)
            BRIDGE(*mygraph[i], ans);
    return ans;
}

void Graph::BRIDGE(value_type& u, vector<pair<int, int>>& ans)
{
    time++;
    u.d = time;
    u.low = time;

    size_type pos = 0;
    for (; mygraph[pos] != &u; pos++);
    for (size_type i = 0; i < edge[pos].size(); i++)
    {
        auto v = mygraph[edge[pos][i]];
        if (v->d == 0)
        {
            v->pi = &u;
            BRIDGE(*v, ans);
            u.low = (u.low < v->low) ? u.low : v->low;

        }
        else if (v != u.pi)
        {
            u.low = (u.low < v->d) ? u.low : v->d;
        }
    }
    if (u.pi != nullptr && u.low == u.d)
    {
        pair<int, int> temp;
        temp.first = u.pi->num;
        temp.second = u.num;
        ans.push_back(temp);
    }
}


vector< pair<int, int> > ans;


int main() {
    int x, y;
    int n, m;
    while (cin >> n) 
    {
        Graph G(n);
        for (int i = 0; i < n; i++) 
        {
            scanf("%d (%d)", &x, &m);
            for (int j = 0; j < m; j++) 
            {
                scanf("%d", &y);
                G.Link(x, y);
            }
        }
        ans = G.BRIDGE();

        cout << ans.size() << " critical links" << endl;
        for (int i = 0; i < ans.size(); i++) {
            if (ans[i].first > ans[i].second)
            {
                int temp = ans[i].first;
                ans[i].first = ans[i].second;
                ans[i].second = temp;
            }
        }

        sort(ans.begin(), ans.end());
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i].first << " - " << ans[i].second << endl;
        }
        cout << endl;
    }
}