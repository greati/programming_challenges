#include <bits/stdc++.h>

using namespace std;

typedef vector<int>::iterator vit;
typedef set<int>::iterator sit;

int main(void) {

	int n;
	int test = 0;

	while (true) {
	
		cin >> n;

		if (n == 0) return 0;

		test++;

		set<int> adj[7];
		set<int> vertices;
		int degree[7];

		int a, b;
		for (int i = 0; i < n; ++i) {
			cin >> a >> b;
			if (a != b) {
				adj[a].insert(b);
				degree[a]++;
				adj[b].insert(a);
				degree[b]++;
			} else degree[a]++;
			vertices.insert(a);
			vertices.insert(b);
		}

		bool vis[7];
		queue<int> q;

		for (int i = 0; i < 7; ++i) vis[i] = false;

		q.push(a);
		vis[a] = true;
		while (!q.empty()) {
			int cur = q.front();
			for (sit it = adj[cur].begin(); it != adj[cur].end(); ++it) {
				int adj = *it;
				if (!vis[adj]) {
					vis[adj] = true;
					q.push(adj);
				}
			}
			q.pop();
		}

		bool connected = true;
		for (sit i = vertices.begin(); i != vertices.end(); ++i) {
			if (!vis[*i]) {
				connected = false; break;
			}
		}

		int countOdd = 0;
		if (connected) {
			for (sit i = vertices.begin(); i != vertices.end(); ++i) {
				int v = *i;
				countOdd += (degree[v] % 2);
			}
		}

		cout << "Teste " << test << endl;
		if (connected && (countOdd == 2 || countOdd == 0)) cout << "sim" << endl << endl;
		else cout << "nao" << endl << endl;
	}

	return 0;
}
