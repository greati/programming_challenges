#include <bits/stdc++.h>

using namespace std;

vector<int> graph[102];
bool vis[102];
bool belong[102];

int main(void) {

	int N;

	while (true) {
		cin >> N;

		if (N == 0) break;

		for (int i = 0; i <= N; ++i) {
			graph[i].clear();
			vis[i] = false;
			belong[i] = false;
		}

		for (int i = 0; i < N; ++i) {
			int id;
			cin >> id;
			cin.ignore();
			int f;
			string line;
			getline(cin, line);
			istringstream iss (line);
			while (iss >> f) 
				graph[id].push_back(f);
		}

		queue<int> q;
		q.push(1);
		vis[1] = true;
		belong[1] = true;
		bool fail = false;

		while (!q.empty()) {
			int cur = q.front();
			for (int i = 0; i < graph[cur].size(); ++i) {
				int adj = graph[cur][i];
				if (!vis[adj]) {
					vis[adj] = true;
					belong[adj] = not belong[cur];
					q.push(adj);
				} else {
					if (belong[cur] == belong[adj])
						fail = true;
				}
			}
			q.pop();
		}

		if (fail) cout << "NAO" << endl;
		else 	  cout << "SIM" << endl;
	}

	return 0;
}
