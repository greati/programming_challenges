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

		vector<int> adj[7];
		set<int> vertices;
		int degree[7];
		bool vis[7];

		for (int i = 0; i < 7; ++i) { 
			vis[i] = false;
			degree[i] = 0;
		}

		int a, b;
		for (int i = 0; i < n; ++i) {
			cin >> a >> b;
			adj[a].push_back(b);
			degree[a]++;
			adj[b].push_back(a);
			degree[b]++;
			vertices.insert(a);
			vertices.insert(b);
		}

		queue<int> q;

		bool connected = true;
		
		q.push(a);
		vis[a] = true;
		while (!q.empty()) {
			int cur = q.front();
			for (vit it = adj[cur].begin(); it != adj[cur].end(); ++it) {
				int adj = *it;
				if (!vis[adj]) {
					vis[adj] = true;
					q.push(adj);
				}
			}
			q.pop();
		}

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
