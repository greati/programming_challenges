#include <bits/stdc++.h>
using namespace std;

bool vis[1001];
int sets[2];
int vertexSet[1001];
vector<int> adj[1001];
queue<int> q;
int remaining;

int main(void) {
	int t;
	int n,m;
	scanf("%d", &t);
	while (t--) {
		q.clear();
		scanf("%d %d",&n,&m);
		// Cleaning
		for (int i = 0; i <= n; ++i) {
			vis[i] = false;
			adj[i].clear();
		}
		sets[0] = sets[1] = 0;
		// Read graph
		for (int i = 0; i < m; ++i) {
			int u,v;
			scanf("%d %d", &u, &v);
			adj[u].push_back(v);
			adj[v].push_back(u);			
		}	
		// BFS
		sets[0]++;
		vertexSet[1] = 0;
		q.push(1);
		vis[1] = true;
		remaining = n-1;
		while (!q.empty()) {
			int cur = q.front();
			int scur = vertexSet[cur];
			for (int i = 0; i < adj[cur].size(); ++i) {
				if (!vis[adj[cur][i]]) {
					vis[adj[cur][i]] = true;
					q.push(adj[cur][i]);
					sets[1 - scur]++; 	
					vertexSet[adj[cur][i]] = 1 - scur;
					remaining--;
				}
			}
			q.pop();	
			if (remaining == 0) break;
		}
		printf("%d\n", max(sets[0],sets[1]));
	}
	return 0;
}
