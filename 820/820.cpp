#include <bits/stdc++.h>

using namespace std;

struct Edge {
	int vertex;
	int capacity;
	int flow;
	int residual;
	Edge (int v, int c) : vertex {v}, capacity {c}, flow{0}, residual {c} {};
	Edge(){};
};

vector<Edge> graph[101];
vector<bool> vis;
vector<int> parent;
vector<Edge> path;

int updateNetwork(int vertex, int minCapacity){
	if (parent[vertex] != -1) {
		Edge edgeInPath = path[vertex];
		int m = updateNetwork(parent[vertex], min(minCapacity, edgeInPath.residual));			
		// Take care on update TODO
		edgeInPath.residual -= m;
		edgeInPath.flow += m;
		return m;
	}
	return minCapacity;
}

int main(void) {

	int n, s, t, c;
	
	vis.resize(101); parent.resize(101); path.resize(101);

	while (true) {
		scanf("%d", &n);

		if (n == 0) break;

		scanf("%d%d%d", &s, &t, &c); // source, destination, |E|

		// Clear graph
		for (int i = 0; i <= n; ++i)	graph[i].clear();

		// Mounting the network
		for (int i = 0; i < c; ++i) {
			int u, v, w;
			scanf("%d%d%d", &u, &v, &w); // from, to, weight 
			Edge ep {v, w};
			Edge en {u, w};
			graph[u].push_back(ep);
			graph[v].push_back(en);
		}

		do {
			queue<int> q;
			for (int i = 0; i <= n; ++i) {
				vis[i] = false;
				parent[i] = -1;
			}
			parent[s] = -1;
			q.push(s);
			while (!q.empty()) {
				int cur = q.front();
				vis[cur] = true;
				for (int i = 0; i < graph[cur].size(); ++i) {
					Edge adj = graph[cur][i];	
					if (!vis[adj.vertex]) {
						parent[adj.vertex] = cur;
						path[adj.vertex] = adj;
						q.push(adj.vertex);
					}
				}	
				q.pop();
			}
			
			if (vis[t]) 	updateNetwork(t);

		} while (vis[t]);
	}
	return 0;
}
