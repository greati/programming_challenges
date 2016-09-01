#include <bits/stdc++.h>

using namespace std;

vector<int> graph[1000001];
bool vis[1000001];
int dist[1000001];

pair<int,int> BFS(int s, int n) {
	for (int i = 1; i <= n; ++i) {
		vis[i] = false;
		dist[i] = 0;
	}
	queue<int> q;
	pair<int,int> p;
	q.push(s);
	while (!q.empty()) {
		int cur = q.front();
		for (int i = 0; i < graph[cur].size(); ++i) {
			if (!vis[graph[cur][i]]) {
				q.push(graph[cur][i]);
				vis[graph[cur][i]] = true;
				dist[graph[cur][i]] = dist[cur] + 1;
				if (p.second < dist[graph[cur][i]]) {
					p.second = dist[graph[cur][i]];
					p.first = graph[cur][i];
				}
			}
		}
		q.pop();
	}
	return p;
}

int main(void) {

	int n;

	cin >> n;

	for (int i = 1; i < n; ++i) {
		int from, to;
		scanf("%d %d", &from, &to);
		graph[from].push_back(to);
		graph[to].push_back(from);
	}	

	pair<int, int> m1 = BFS(1, n);
	int ans = m1.second;
	pair<int, int> m2 = BFS(m1.first, n);
	ans += m2.second;
	printf("%d\n", m2.second);

	return 0;
}
