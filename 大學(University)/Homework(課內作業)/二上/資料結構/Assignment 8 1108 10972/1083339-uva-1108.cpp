#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;
#define MAXN 65536
#include <stack>

struct Graph_Node
{
	using size_type = size_t;
	size_type d;
	Graph_Node* pi = nullptr;
	bool cut;
	size_type numChildren;
	size_type low;
	size_type num;
};

class Graph
{
	using value_type = Graph_Node;
	using pointer = value_type*;
	using multptr = pointer*;
	using size_type = unsigned long long;
public:
	Graph(size_type);
	~Graph();
	void Link(int, int);
	int Node_edge(int);
	void Resize(size_type);
	void DFS();
	vector< pair<int, int> > BRIDGE();
	int CUTPOINTS();
	pair<long long, long long> BRIDGE_CONNECT();
private:
	void DFS(value_type&);
	void BRIDGE(value_type&, vector<pair<int, int>>&);
	void CUTPOINTS(value_type&);
	void BRIDGE_CONNECT(value_type&, stack<value_type>&, pair<long long, long long>&);

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

void Graph::Resize(size_type newsize)
{
    for (size_type i = 0; i < max_node; i++)
        delete mygraph[i];
    delete[] mygraph;

    max_node = newsize;
    mygraph = new pointer[max_node];
    for (size_type i = 0; i < max_node; i++)
        mygraph[i] = new value_type;
    for (size_type i = 0; i < max_node; i++)
        mygraph[i]->num = i;
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

pair<long long, long long> Graph::BRIDGE_CONNECT()
{
    pair<long long, long long> ans;
    ans.first = 0;
    ans.second = 0;
    this->CUTPOINTS();
    for (size_type i = 0; i < max_node; i++)
    {
        mygraph[i]->d = 0;
        mygraph[i]->pi = nullptr;
    }
    time = 0;
    stack<value_type> S;
    for (size_type i = 0; i < max_node; i++)
        if (mygraph[i]->d == 0)
            BRIDGE_CONNECT(*mygraph[i], S, ans);
    return ans;
}

void Graph::BRIDGE_CONNECT(value_type& u, stack<value_type>& S, pair<long long, long long>& ans)
{
    time++;
    u.d = time;
    u.low = time;
    S.push(u);
    size_type pos = 0;
    for (; mygraph[pos] != &u; pos++);
    for (size_type i = 0; i < edge[pos].size(); i++)
    {
        auto v = mygraph[edge[pos][i]];
        if (v->d == 0)
        {
            v->pi = &u;
            BRIDGE_CONNECT(*v, S, ans);
            u.low = (u.low < v->low) ? u.low : v->low;
        }
        else if (v != u.pi)
        {
            u.low = (u.low < v->d) ? u.low : v->d;
        }
    }
    if (u.low == u.d)
    {
        auto w = S.top();
        int temp = 0;
        ans.first++;
        do {
            w = S.top();
            S.pop();
            if (!w.cut)
                temp++;
        } while (w.num != u.num);
        if (temp == 0)
            ans.first--;
        ans.second = (ans.second > temp) ? ans.second : temp;
    }
}



int main() {
    int n, m, x, y;
    int cases = 0;
    while (scanf_s("%d", &m) == 1 && m) {
        int used[MAXN] = {}, usedn = 0;
        Graph G(MAXN);
        n = 0;
        for (int i = 0; i < m; i++) {
            scanf_s("%d %d", &x, &y);
            n = max(n, max(x, y));
            x--, y--;
            used[x] = used[y] = 1;
            G.Link(x, y);
        }
        for (int i = 0; i < n; i++)
            usedn += used[i];
        G.Resize(usedn);
        pair<long long, long long>ans = G.BRIDGE_CONNECT();

        printf("Case %d: %lld %lld\n", ++cases, ans.first, ans.second);
    }
    return 0;
}