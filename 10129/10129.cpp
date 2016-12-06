#include <bits/stdc++.h>

using namespace std;

int main(void) {

	int indegree[30], outdegree[30];
	int vis[30];
	unordered_set<int> adj[30];
	unordered_set<int> vertices;
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		vertices.clear();
		for (int i = 0; i < 30; ++i) {
			indegree[i] = outdegree[i] = 0;
			vis[i] = 0;
			adj[i].clear();
		}

		int a, b;

		for (int i = 0; i < n; ++i) {
			string s;
			cin >> s;
			a = s[0] - 'a'; b = s[s.size()-1] - 'a';		
			adj[a].insert(b);
			indegree[b]++;
			outdegree[a]++;
			vertices.insert(a);
			vertices.insert(b);
		}

		bool possible = true;
	
		int countOdd = 0;
		int oddBegin = 0;
		for (auto i = vertices.begin(); i != vertices.end(); ++i) {
			if (indegree[*i] != outdegree[*i]) countOdd++;	
			if (indegree[*i] < outdegree[*i]) oddBegin = *i;
		}

		possible = (countOdd == 0 || countOdd == 2);

		if (countOdd == 0) oddBegin = a;

		if (possible) {
			queue<int> q;
			q.push(oddBegin);
			vis[oddBegin] = 0;
			while (!q.empty()) {
				int cur = q.front();
				for (auto i = adj[cur].begin(); i != adj[cur].end(); ++i) {
					int ad = *i;
					if (vis[ad] < indegree[ad]) {
						vis[ad]++;
						q.push(ad);
					}
				}
				q.pop();
			}
			for (auto i = vertices.begin(); i != vertices.end(); ++i) { 
				if (vis[*i] < indegree[*i]) {possible = false; break;}
			}
		} 
		
		if (!possible) cout << "The door cannot be opened." << endl;
		else cout << "Ordering is possible." << endl;
		
	}

	return 0;
}
