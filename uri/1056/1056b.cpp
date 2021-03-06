#include <stdio.h>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

struct Edge {
	int vertex;
	int residual;
	Edge * opposite;
	Edge (int v, int c) : vertex {v}, residual {c},opposite{nullptr} {};
	Edge(){};
};

vector<Edge> graph[204];
bool vis[204];
int parent[204];
Edge* path[204];
int flow = 0;

/**
 * Returns the weight of the critical edge and updates
 * the residual graph.
 * */
int updateNetwork(int vertex, int minCapacity){
	if (parent[vertex] != -1) {
		Edge * edgeInPath = path[vertex];
		int m = updateNetwork(parent[vertex], min(minCapacity, edgeInPath->residual));			
		edgeInPath->residual -= m;
		((edgeInPath->opposite)->residual) += m;
		return m;
	}
	return minCapacity;
}

int main(void) {

	int t;

	cin >> t;

	queue<int> q;
	set<int> A, B;	
	long long mapping[204];	

	for (int teste = 1; teste <= t; ++teste) {

		int s = 202; 	// source vertex
		int t = 203;		// sink vertex
		
		// Init
		A.clear(); B.clear();
		for (int i = 0; i < 204; ++i) {
			graph[i].clear();
		}

		int n;
		cin >> n;

		// Read
		for (int i = 0; i < n; ++i) {
			long long a;
			cin >> a;
			mapping[i] = a;
			A.insert(i);	
			Edge e {source, i, 1};
			graph[source].push_back(e);
		}	

		int m;
		cin >> m;

		for (int i = n; i < n + m; ++i) {
			long long a;
			cin >> a;
			mapping[i] = a;
			B.insert(i);	
			Edge e {i, sink, 1};
			graph[i].push_back(e);
		}	

		// Graph
		for (auto i = B.begin(); i != B.end(); i++) {
			for (auto j = A.begin(); j != A.end(); j++) {
				if ((mapping[(*j)] != 0 && (mapping[(*i)] % mapping[(*j)] == 0))
				    || (mapping[(*j)] == 0 && mapping[(*i)] == 0)) {
					Edge e1 {*j, *i, 1};
					Edge e2 {*i, *j, 0};
					e1.back = &e2; e2.back = &e1;
					graph[*j].push_back(e1);
					graph[*i].push_back(e2);
				}
			}
		}


		flow = 0;

		do {
			for (int i = 0; i <= n; ++i) {
				vis[i] = false;
				parent[i] = -1;
			}
			q.push(s);
			vis[s] = true;
			while (!q.empty()) {
				int cur = q.front();
				for (unsigned int i = 0; i < graph[cur].size(); ++i) {
					Edge * adj = &graph[cur][i];	
					if (!vis[adj->vertex] && (adj->residual) > 0) {
						vis[adj->vertex] = true;
						parent[adj->vertex] = cur;
						path[adj->vertex] = adj;
						q.push(adj->vertex);
					}
				}	
				q.pop();
			}
			
			if (vis[t])     flow +=	updateNetwork(t, 1001);

		} while (vis[t]);

		cout << "Case " << teste << ": " << flow << endl;
	}

	return 0;
}
