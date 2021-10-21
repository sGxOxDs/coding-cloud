#include <iostream>
#include "Graph.h"
using namespace std;


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

void Graph::DFS()
{
    for (size_type i = 0; i < max_node; i++)
    {
        mygraph[i]->color = WHITE;
        mygraph[i]->pi = nullptr;
    }
    time = 0;
    for (size_type i = 0; i < max_node; i++)
        if (mygraph[i]->color == WHITE)
            DFS(*mygraph[i]);
}

void Graph::DFS(value_type& u)
{
    time++;
    u.d = time;
    u.color = GRAY;

    size_type pos = 0;
    for (; mygraph[pos] != &u; pos++);
    for (size_type i = 0; i < edge[pos].size(); i++)
    {
        auto v = mygraph[edge[pos][i]];
        if (v->color == WHITE)
        {
            v->pi = &u;
            DFS(*v);
        }
    }

    u.color = BLACK;
    time++;
    u.f = time;
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
        if (v->d==0)
        {
            v->pi = &u;
            u.numChildren++;
            CUTPOINTS(*v);
            u.low = (u.low < v->low)? u.low : v->low;
            if (u.pi != nullptr)
                if (v->low == v->d || v->low == u.d)
                    u.cut = true;
        }
        else if (v!=u.pi)
        {
            u.low = (u.low < v->d) ? u.low : v->d;
        }
    }
}
