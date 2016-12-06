#include <bits/stdc++.h>

using namespace std;

vector<int> graph[101];
int maxBlacks = 0;
vector<int> pathMax;

bool check(const int & v, const vector<int> & vertices) {
	for (int i = 0; i < graph[v].size(); ++i)
		if (vertices[graph[v][i]] == 1)
			return false;
	return true;
}

void backtrack(int cur, vector<int> & colors, vector<int> & blackPath) {
	if (cur <= colors.size()) {
		// Se não há pretos na adjacência
		if (check(cur, colors)) {
			colors[cur] = 1;
			blackPath.push_back(cur);
			backtrack(cur + 1, colors, blackPath);
			blackPath.pop_back();
			colors[cur] = 0;
		}
		// Backtrack com brancos anyway
		backtrack(cur + 1, colors, blackPath);
	} else {
		if (maxBlacks < blackPath.size()) {
			maxBlacks = blackPath.size();
			pathMax = blackPath;
		}
	}
}

int main(void) {

	int m;

	cin >> m;

	vector<int> vertices;
	vector<int> path;

	while (m--) {
		
		vertices.clear();
		path.clear();
		pathMax.clear();
		maxBlacks = 0;

		int n, k;

		cin >> n >> k;

		for (int i = 1; i <= n; ++i) {
			graph[i].clear();
			vertices.push_back(0);
		}

		for (int i = 0; i < k; ++i) {
			int a, b;
			cin >> a >> b;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}
		
		backtrack(1, vertices, path);

		sort(pathMax.begin(), pathMax.end());
		cout << maxBlacks << endl;
		for (int i = 0; i < pathMax.size(); ++i) {
			cout << pathMax[i];
			if (i < pathMax.size() - 1) cout << " ";
		
		}
		cout << endl;
	}

	return 0;
}
