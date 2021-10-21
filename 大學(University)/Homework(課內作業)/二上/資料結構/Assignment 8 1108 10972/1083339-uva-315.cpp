#include <iostream>
#include <sstream>
#include <cstdio>
using namespace std;
#include <vector>

struct Graph_Node
{
	using size_type = size_t;
	size_type d=0;
	Graph_Node* pi = nullptr;
	bool cut=false;
	size_type numChildren=0;
	size_type low=0;
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
	int CUTPOINTS();
private:
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

int Graph::CUTPOINTS()
{
    int ans = 0;
    for (size_type i = 0; i < max_node; i++)
    {
        mygraph[i]->d = 0;
        mygraph[i]->numChildren = 0;
        mygraph[i]->pi = nullptr;
        mygraph[i]->cut = false;
    }
    time = 0;
    for (size_type i = 0; i < max_node; i++)
        if (mygraph[i]->d == 0)
        {
            CUTPOINTS(*mygraph[i]);
            if (mygraph[i]->numChildren > 1)
                mygraph[i]->cut = true;
        }
    for (size_type i = 0; i < max_node; i++)
        if (mygraph[i]->cut)
            ans++;
    return ans;
}

void Graph::CUTPOINTS(value_type& u)
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
            u.numChildren++;
            CUTPOINTS(*v);
            u.low = (u.low < v->low) ? u.low : v->low;
            if (u.pi != nullptr)
                if (v->low == v->d || v->low == u.d)
                    u.cut = true;
        }
        else if (v != u.pi)
        {
            u.low = (u.low < v->d) ? u.low : v->d;
        }
    }
}

int main()
{
    int N, ans;
    string line;
    while (scanf("%d ", &N) && N) {
        Graph G(N);
        // Input
        int a, b;
        while (getline(cin, line)) {
            stringstream ss(line);
            ss >> a;
            if (!a) break;
            while (ss >> b) {
                G.Link(a-1, b-1);
            }
        }

        ans = G.CUTPOINTS();

        printf("%d\n", ans);
    }
}