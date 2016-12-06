#include <bits/stdc++.h>

using namespace std;

struct Edge {
	int from, to;
	int residual;
	Edge * back;

	Edge(int _from, int _to, int _residual) : 
		from {_from}, to {_to}, residual {_residual}, back {nullptr} {};
	Edge() {};
};

void printa(vector<Edge> * adj, int n, int m) {
	for (int i = 0; i < n + m; ++i) {
		cout << i << ":" << endl;
		for (auto e : adj[i]) {
			cout << e.to << " [" << e.residual << "] // ";
		}
		cout << endl;
	}
}


int main(void) {

	int t;

	cin >> t;

	queue<int> q;
	bool vis[204];
	Edge* parent[204];
	vector<Edge> adj[204];
	set<int> A, B;	
	long long mapping[204];	

	for (int teste = 1; teste <= t; ++teste) {

		int source = 202; 	// source vertex
		int sink = 203;		// sink vertex
		
		// Init
		A.clear(); B.clear();
		for (int i = 0; i < 204; ++i) {
			adj[i].clear();
		}

		int n;
		cin >> n;

		// Read
		for (int i = 0; i < n; ++i) {
			long long a;
			cin >> a;
			mapping[i] = a;
			A.insert(i);	
			Edge e {source, i, 1};
			adj[source].push_back(e);
		}	

		int m;
		cin >> m;

		for (int i = n; i < n + m; ++i) {
			long long a;
			cin >> a;
			mapping[i] = a;
			B.insert(i);	
			Edge e {i, sink, 1};
			adj[i].push_back(e);
		}	

		// Graph
		for (auto i = B.begin(); i != B.end(); i++) {
			for (auto j = A.begin(); j != A.end(); j++) {
				if ((mapping[(*j)] != 0 && (mapping[(*i)] % mapping[(*j)] == 0))
				    || (mapping[(*j)] == 0 && mapping[(*i)] == 0)) {
					Edge e1 {*j, *i, 1};
					Edge e2 {*i, *j, 0};
					e1.back = &e2; e2.back = &e1;
					adj[*j].push_back(e1);
					adj[*i].push_back(e2);
				}
			}
		}


		long long ans = 0;
		do {
			for (int i = 0; i < n + m; ++i) {
				vis[i] = false;	
				parent[i] = nullptr;
			}
			vis[sink] = false;
			q.push(source);
			vis[source] = true;
			while (!q.empty()) {
				int cur = q.front();
				for (unsigned int i = 0; i < adj[cur].size(); ++i) {
					Edge * e = &adj[cur][i];
					if (!vis[e->to] && e->residual > 0) {
						vis[e->to] = true;
						parent[e->to] = e;
						q.push(e->to);
					}
				}
				q.pop();
			}

			if (vis[sink]) {
				++ans;  
				int i = sink;
				while (i != source) {
					Edge * e = parent[i];
					e->residual = 0;
					if (e->back != nullptr) e->back->residual = 1;
					i = e->from;
				}
			}	

		} while (vis[sink]);

		cout << "Case " << teste << ": " << ans << endl;
	}
	
	return 0;
}
