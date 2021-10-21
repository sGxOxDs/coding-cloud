#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct Graph_Node
{
	int num;
	int d;
	int low;
	Graph_Node* pi;
};

class Graph
{
public:
	Graph(int nodesize)
	{
		max_node = nodesize;
		graph = new Graph_Node* [max_node]();
		for (int i = 0; i < max_node; i++)
		{
			graph[i] = new Graph_Node();
			graph[i]->num = i;
		}
		edge = new vector<int>[max_node]();
	}
	~Graph()
	{
		delete[] edge;
		for (int i = 0; i < max_node; i++)
			delete graph[i];
		delete[] graph;
	}
	void link(int a, int b)
	{
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	int BRIDGE_CONNECT()
	{
		for (int i = 0; i < max_node; i++)
		{
			graph[i]->d = 0;
			graph[i]->pi = nullptr;
		}
		time = 0;
		for (int i = 0; i < max_node; i++)
		{
			if (graph[i]->d == 0)
			{
				BRIDGE_CONNECT(graph[i]);
				comp++;
				/*cout << "new component: ";
				Graph_Node* w = sta.top();
				while (!sta.empty())
				{
					w = sta.top();
					sta.pop();
					cout << w->num + 1 << " ";
				}
				cout << endl;*/
			}
		}
		/*cout << "total bridge: " << bridge << endl;
		cout << "total comp: " << comp << endl;*/
		if (comp == 1)
			return 0;
		else
			return comp - bridge;
	}

private:
	void BRIDGE_CONNECT(Graph_Node* u)
	{
		time++;
		u->d = time;
		u->low = time;
		sta.push(u);

		
		for (auto it = edge[u->num].begin(); it != edge[u->num].end(); it++)
		{
			Graph_Node* v = graph[*it];
			if (v->d == 0)
			{
				v->pi = u;
				BRIDGE_CONNECT(v);
				u->low = (u->low < v->low) ? u->low : v->low;
				if (v->low > u->d)
				{
					bridge++;
					comp++;
					/*cout << "new component: ";
					Graph_Node* w = sta.top();
					do {
						w = sta.top();
						sta.pop();
						cout << w->num+1 << " ";
					} while (w != v);
					cout << endl;*/
				}
			}
			else if(v!=u->pi)
				u->low = (u->low < v->low) ? u->low : v->low;
		}
	}

private:
	Graph_Node** graph;
	vector<int>* edge;
	int max_node;
	int time;
	stack<Graph_Node*> sta;
	int bridge = 0;
	int comp = 0;
};

int main()
{
	int N, E;
	while (cin>>N>>E)
	{
		Graph G(N);
		int a, b;
		for (; E--;)
		{
			cin >> a >> b;
			G.link(a-1, b-1);
		}
		int ans = G.BRIDGE_CONNECT();
		//cout << "Ans: " << ans << endl;
		cout << ans << endl;
	}

	return 0;
}
