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
	int belong; //add
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
				/*cout << "new component: ";*/ //modify
				Graph_Node* w = sta.top();
				while (!sta.empty())
				{
					w = sta.top();
					sta.pop();
					//cout << w->num + 1 << " "; delete
					w->belong = comp; //add
				}
				/*cout << endl;*/ //modify
			}
		}
		/*cout << "total bridge: " << bridge << endl;
		cout << "total comp: " << comp << endl;*/
		if (comp == 1)
			return 0;
		//else delete
			//return comp - bridge; delete

		int* de = new int[max_node + 1](); //add
		for (int i = 0; i < max_node + 1; de[i] = 0, i++); //add
		for (int i = 0; i < vbridge.size(); i++) //add
		{
			int u = vbridge[i].first; //add
			int v = vbridge[i].second; //add
			de[graph[u]->belong] ++; //add
			de[graph[v]->belong] ++; //add
		}
		int res = 0; //add
		for (int i = 1; i <= comp; i++) //add
			if (de[i] == 0) res += 2; //add
			else  if (de[i] == 1) res++; //add
		delete[] de; //add
		return (res + 1) / 2; //add
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
					vbridge.push_back(pair<int, int>(u->num, v->num)); //add
					/*cout << "new component: ";*/ //modify
					Graph_Node* w = sta.top();
					do {
						w = sta.top();
						sta.pop();
						//cout << w->num+1 << " "; delete
						w->belong = comp; //add
					} while (w != v);
					/*cout << endl;*/ //modify
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
	int time = 0;
	stack<Graph_Node*> sta;
	int bridge = 0;
	int comp = 0;
	vector<pair<int,int>> vbridge; //add
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
