#include <bits/stdc++.h>

using namespace std;

int parent[1001];
int height[1001];
priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> edges;
priority_queue<int> answer;
int n, m;

void make_set() {
	for (int i = 0; i <= n; ++i) {
		parent[i] = i;
		height[i] = 0;
	}
}

int find(int u) {
	if (u != parent[u])
		parent[u] = find(parent[u]);
	return parent[u];
}

void join(int u, int v) {
	int pu = find(u);
	int pv = find(v);
	if (height[pu] > height[pv]) {
		parent[pv] = pu;
	} else if (height[pv] > height[pu]) {
		parent[pu] = pv;
	} else {
		parent[pu] = pv;
		height[pv]++;
	}
}

int main(void) {
	
	while (true) {
		scanf("%d %d", &n, &m);

		if (m == 0 && n == 0) break;

		make_set();

		for (int i = 0; i < m; ++i) {
			int from, to, w;
			scanf("%d %d %d", &from, &to, &w);
			edges.push(make_pair(w,make_pair(from, to)));
		}

		int i = 0;
		while (i < n-1 && !edges.empty()) {
			pair<int,pair<int,int>> p = edges.top();
			cout << p.first << endl;
			if (find(p.second.first) != find(p.second.second))
				++i;
			else
				answer.push(p.first);	
			edges.pop();
		}
		
		while (!edges.empty()) {
			answer.push(edges.top().first);
			edges.pop();
		}
		
		if (answer.empty()) printf("forest");
		else
			while (!answer.empty()) {
				printf("%d ", answer.top());
				answer.pop();
			}
		printf("\n");
	}

	return 0;
}
