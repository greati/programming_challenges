#include <bits/stdc++.h>

using namespace std;

bool dist(int x1, int y1, int x2, int y2, int max) {
	return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) <= max*max;
}

int main(void) {

	int n, d;

	vector<int> graph[1001];
	int coord[1001][2];

	scanf("%d %d", &n, &d);	

	bool vis[1001];

	for (int i = 0; i < n; ++i) {
		vis[i] = false;
		int a, b;
		scanf("%d %d", &a, &b);
		coord[i][0] = a;
		coord[i][1] = b;
		for (int j = 0; j < i; ++j) {
			if (dist(coord[i][0], coord[i][1], coord[j][0], coord[j][1], d)) {
				graph[i].push_back(j);
				graph[j].push_back(i);
			}
		}
	}
	
	queue<int> q;
	int count = 1;
	vis[0] = true;
	q.push(0);
	while (!q.empty()) {
		int cur = q.front();
		for (int i = 0; i < graph[cur].size(); ++i) {
			if (!vis[graph[cur][i]]) {
				vis[graph[cur][i]] = true;
				count++;	
				q.push(graph[cur][i]);
			}
		}
		q.pop();
	}
	
	printf(count == n ? "S\n" : "N\n");

	return 0;
}
