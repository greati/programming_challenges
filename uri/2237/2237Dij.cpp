#include <bits/stdc++.h>

using namespace std;

// Graph
map<vector<int>, vector<vector<int>>> adjList;
map<vector<int>, int> minDist;
map<vector<int>, bool> vis;

// Mapping weights to ids
map<int,int> idToW;
map<int,int> wToId;

// Givens
vector<int> initial;
vector<int> goal;

void create_permut_relax(vector<int> config, int i, int j) {
	vector<int> newConfig (config);
	iter_swap(newConfig.begin() + i, newConfig.begin() + j);
	// Vertex doesn't exist yet, create it
	if (minDist.find(newConfig) == minDist.end()) {
		minDist.insert(make_pair(newConfig, INT_MAX));
		vector<vector<int>> newAdj;
		adjList.insert(make_pair(newConfig,newAdj));
		adjList[config].push_back(newConfig);
		adjList[newConfig].push_back(config);
		vis.insert(make_pair(newConfig,false));
	}	
	// Relax
	if (minDist[newConfig] > minDist[config] + (idToW[config[i]] + idToW[config[j]]))
		minDist[newConfig] = minDist[config] + (idToW[config[i]] + idToW[config[j]]);
			
}

vector<int> extract_min() {
	auto itMin = vis.begin();
	int dmin = INT_MAX;
	for (auto it = vis.begin(); it != vis.end(); ++it) {
		if (!(it->second) && minDist[it->first] < dmin ) {
			itMin = it;
			dmin = minDist[it->first];
		}
	}	
	return itMin->first;
}

int main(void) {

	// Getting initial configuration + mapping weights
	for (int i = 0; i < 8; ++i) {
		int a; scanf("%d", &a);
		idToW.insert(make_pair(i,a));
		wToId.insert(make_pair(a,i));
		initial.push_back(i);
	}
		
	// Getting final configuration
	for (int i = 0; i < 8; ++i) {
		int a; scanf("%d", &a);
		goal.push_back(wToId[a]);
	}
	
	minDist.insert(make_pair(initial, 0));
	vector<vector<int>> newAdj;
	adjList.insert(make_pair(initial,newAdj));
	vis.insert(make_pair(initial,false));

	vector<int> minD = initial;

	do {
		create_permut_relax(minD, 0, 1);
		create_permut_relax(minD, 1, 2);
		create_permut_relax(minD, 2, 3);
		create_permut_relax(minD, 4, 5);
		create_permut_relax(minD, 5, 6);
		create_permut_relax(minD, 6, 7);
		create_permut_relax(minD, 0, 4);
		create_permut_relax(minD, 1, 5);
		create_permut_relax(minD, 2, 6);
		create_permut_relax(minD, 3, 7);
		vis[minD] = true;
		minD = extract_min();
		if (minD == goal) break;
	} while (!vis[minD]);

	cout << minDist[goal] << endl;
	
	return 0;
}
