#include <bits/stdc++.h>

using namespace std;

vector<int> edges[100001];
vector<int> edgesT[100001];
list<int> vertices;
vector<int> vertices_comp;
vector<int> indegree;
vector<bool> vis;
int n, v, e;

void clear() {
	vertices.clear();
	vis.clear();
	indegree.clear();
	vertices_comp.clear();
	for (int i = 0; i <= v; ++i) {
		edges[i].clear();
		edgesT[i].clear();
		vis.push_back(false);
		vertices_comp.push_back(-1);
		indegree.push_back(0);
	}
}

// DFS for ordering by finish time
void DFS_finish(int s) {
	vis[s] = true;
	for (int i = 0; i < edges[s].size(); ++i)
		if (!vis[edges[s][i]])
			DFS_finish(edges[s][i]);	
	vertices.push_front(s);
}

// DFS for getting the components
void DFS_scc(int s, int comp) {
	vis[s] = true;
	vertices_comp[s] = comp;
	for (int i = 0; i < edgesT[s].size(); ++i)
		if (!vis[edgesT[s][i]]) {
			DFS_scc(edgesT[s][i], comp);
		}
}

int main(void) {

	cin >> n;

	while (n--) {

		cin >> v >> e;	

		clear();	
	
		for (int i = 0; i < e; ++i) {
			int a, b;
			cin >> a >> b;
			edges[a].push_back(b);
			edgesT[b].push_back(a);
		}		

		for (int i = 1; i <= v; ++i) 
			if (!vis[i])
				DFS_finish(i);
		
		vis.clear();	
		for (int i = 0; i <= v; ++i)
			vis.push_back(false);
	
		int comp = 1;
		while (!vertices.empty()) {
			int cur = vertices.front();
			vertices.pop_front();
			if (!vis[cur])
				DFS_scc(cur, comp++);
		}
			
		// Counting in degrees
		for (int i = 1; i <= v; ++i)
			for (int j = 0; j < edges[i].size(); ++j)
				if (vertices_comp[i] != vertices_comp[edges[i][j]])
					indegree[vertices_comp[edges[i][j]]]++;	
		int ans = 0;

		for (int i = 1; i < comp; ++i)
			if (!indegree[i]) ans++;

		cout << ans << endl;

	}

	return 0;
}
