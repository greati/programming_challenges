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

vector<Edge> graph[101];
bool vis[101];
int parent[101];
Edge* path[101];
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

	int n, s, t, c;

	int netNumber = 0;

	queue<int> q;

	while (true) {
		scanf("%d", &n);

		if (n == 0) break;
	
		++netNumber;

		scanf("%d%d%d", &s, &t, &c); // source, destination, |E|

		// Clear graph
		for (int i = 0; i <= n; ++i) graph[i].clear();

		// Mounting the network
		for (int i = 0; i < c; ++i) {
			int u, v, w;
			scanf("%d%d%d", &u, &v, &w); // from, to, weight 
			Edge ep {v, w}; Edge en {u, w};
			ep.opposite = &en; en.opposite = &ep;
			graph[u].push_back(ep);
			graph[v].push_back(en);
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

		printf("Network %d\nThe bandwidth is %d.\n\n", netNumber, flow);
	}

	return 0;
}
