﻿#include <iostream>
#include "Graph.h"
using namespace std;


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
            for (j = 0; j < ans.size() && ans[j] != edge[elm][i] ; j++);
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
        if (temp==0)
            ans.first--;
        ans.second = (ans.second > temp) ? ans.second : temp;
    }
}