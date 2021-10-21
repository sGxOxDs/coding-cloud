#pragma once

#include <iostream>
using namespace std;
#include <vector>

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
	int CUTPOINTS();
private:
	void DFS(value_type&);
	void CUTPOINTS(value_type&);

private:
	multptr mygraph;
	size_type max_node;
	size_type time;
	vector<int>* edge;
};
