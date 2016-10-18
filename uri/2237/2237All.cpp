#include <bits/stdc++.h>

using namespace std;

map<vector<int>,int> minDists;
map<vector<int> , vector< pair<int,vector<int>> > > adj;
map<vector<int>,bool> vis;

priority_queue<pair<int, vector<int>>, vector< pair<int,vector<int>> >, greater<pair<int,vector<int>>>> pq;

vector<int> initial;
vector<int> goal;

void make_edge(vector<int> old, int i, int j) {
	vector<int> newConf (old);
	iter_swap(newConf.begin() + i, newConf.begin() + j);
	pair<int, vector<int>> edge = make_pair(old[i] + old[j], newConf);
	adj[old].push_back(edge);
}

int main(void) {

	// Getting initial configuration + mapping weights
	for (int i = 0; i < 8; ++i) {
		int a; scanf("%d", &a);
		initial.push_back(a);
	}
		
	// Getting final configuration
	for (int i = 0; i < 8; ++i) {
		int a; scanf("%d", &a);
		goal.push_back(a);
	}

	// Mapping all permutations 
	vector<int> permut (initial);
	sort(permut.begin(), permut.end());
	int pId = 0;
	do {
		minDists.insert(make_pair(permut, (1<<30)));	
	} while (next_permutation(permut.begin(), permut.end()));

	// Edges
	for (auto it = minDists.begin(); it != minDists.end(); ++it) {
		vector<pair<int,vector<int>>> newAdj;
		adj.insert(make_pair(it->first, newAdj));
		vis.insert(make_pair(it->first, false));
		// make edges
		make_edge(it->first, 0, 1);	
		make_edge(it->first, 1, 2);	
		make_edge(it->first, 2, 3);	
		make_edge(it->first, 4, 5);	
		make_edge(it->first, 5, 6);	
		make_edge(it->first, 6, 7);	
		make_edge(it->first, 0, 4);	
		make_edge(it->first, 1, 5);	
		make_edge(it->first, 2, 6);	
		make_edge(it->first, 3, 7);	
	}

	minDists[initial] = 0;
	pq.push(make_pair(0, initial));

	// Dijkstra
	pair<int, vector<int>> minEdge;	
	while(!pq.empty()) {
		minEdge = pq.top();
		if (vis[minEdge.second]) { 
			pq.pop();
			continue;
		}
		vector<int> v = minEdge.second;
		int mdv = minDists[v];
		for (auto i = 0; i < adj[v].size(); ++i) {
			vector<int> u = adj[v][i].second;	
			if (minDists[u] > mdv + adj[v][i].first) {
				minDists[u] = mdv + adj[v][i].first;
				pq.push(make_pair(minDists[u],u));
			}
		}
		vis[v] = true;
		pq.pop();	
	}

	cout << minDists[goal] << endl;

	return 0;
}
