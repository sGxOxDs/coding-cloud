#include <stdio.h>
#include <vector>
#include <algorithm>
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
    int Node_edge(int);
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

int Graph::Node_edge(int elm)
{
    vector<int> ans;
    for (int i = 0; i < edge[elm].size(); i++)
    {
        if (ans.size() > 0)
        {
            int j;
            for (j = 0; j < ans.size() && ans[j] != edge[elm][i]; j++);
            if (j == ans.size())
                ans.push_back(edge[elm][i]);
        }
        else
        {
            ans.push_back(edge[elm][i]);
        }
    }
    return ans.size();
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
        //cout << " " << u.pi->num << " and " << u.num << " is a bridge" << endl;
    }
}

struct E {
    int x, value;
    bool operator<(const E& a) const {
        if (value != a.value)
            return value > a.value;
        return x < a.x;
    }
};

int main() {
    int n, m;
    int i, j, k, x, y;
    while (scanf("%d %d", &n, &m) == 2 && n) 
    {
        E* D = new E[n];
        for (i = 0; i < n; i++) 
        {
            D[i].x = i, D[i].value = 0;
        }
        Graph G(n);
        vector< pair<int, int> > bridge;
        

        while (scanf("%d %d", &x, &y) == 2 && x >= 0)
        {
            G.Link(x, y);
        }

        bridge = G.BRIDGE();

        for (i = 0; i < bridge.size(); i++) 
        {
            D[bridge[i].first].value++;
            D[bridge[i].second].value++;
        }

        for (i = 0; i < n; i++) {
            if (D[i].value != G.Node_edge(i))
                D[i].value++;
        }

        sort(D, D + n);
        for (i = 0; i < m; i++)
            printf("%d %d\n", D[i].x, D[i].value);
        puts("");
        delete[] D;
    }
    return 0;
}