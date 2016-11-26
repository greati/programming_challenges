#include <bits/stdc++.h>

using namespace std;

vector<int> graph[101];

int maxBlacks = 0;
vector<int> pathMax;

bool check(int v, vector<int> vertices, vector<bool> visited) {
	for (int i = 0; i < graph[v].size(); ++i)
		if (vertices[graph[v][i]] == 1)
			return false;
	return true;
}

void backtrack(vector<int> vertices, vector<bool> visited, int visNumber, int cur, bool fatherColor, int numBlacks, vector<int> blackPath) {
	if (visNumber < vertices.size()) {
		for (int i = 0; i < graph[cur].size(); ++i) {
			int adj = graph[cur][i];
			if (!visited[adj]) {
				visited[adj] = true;
				if (check(cur,vertices,visited)) {
					vertices[cur] = 1;
					blackPath.push_back(cur);
					if (maxBlacks < numBlacks + 1) {
						pathMax = blackPath;
						maxBlacks = numBlacks + 1;
					}
					backtrack(vertices, visited, visNumber + 1, adj, 1, numBlacks + 1, blackPath);

				}
				vertices[cur] = 0;
				backtrack(vertices, visited, visNumber + 1, adj, 0, numBlacks, blackPath);
			}
		}
	}
}

int main(void) {

	int m;

	cin >> m;

	vector<int> vertices;
	vector<bool> visited;
	vector<int> path;

	while (m--) {
		
		vertices.clear();
		visited.clear();
		path.clear();
		pathMax.clear();
		maxBlacks = 0;

		int n, k;

		cin >> n >> k;

		for (int i = 0; i < n; ++i) {
			visited.push_back(false);
			graph[i].clear();
			vertices.push_back(0);
		}

		for (int i = 0; i < k; ++i) {
			int a, b;
			cin >> a >> b;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}

		visited[1] = true;
		
		backtrack(vertices, visited, 0, 1, 0, 0, path);

		cout << maxBlacks << endl;
		for (int i = 0; i < pathMax.size(); ++i)
			cout << pathMax[i] << " ";
		cout << endl;
	}

	return 0;
}
