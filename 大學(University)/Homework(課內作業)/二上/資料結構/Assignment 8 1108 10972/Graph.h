#pragma once

#include <iostream>
using namespace std;
#include <vector>
#include <stack>

enum Color { WHITE, GRAY, BLACK };

struct Graph_Node
{
	using size_type = size_t;
	size_type d;
	size_type f;
	Color color;
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
	void BRIDGE_CONNECT(value_type& ,stack<value_type>& ,pair<long long, long long>&);

private:
	multptr mygraph;
	size_type max_node;
	size_type time;
	vector<int>* edge;
};
