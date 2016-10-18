#include <bits/stdc++.h>

using namespace std;

int permIDGen = 1;
map<vector<int>,int> permToId;
map<int,int> idToW;
map<int,int> wToId;
map<int,int> minDists;
vector<int> initial;
vector<int> goal;

bool adjMatrix[40321][40321];
vector<pair<int,int>> adjList[40321];

void print_vec(vector<int> & last) {
	for (int i=0; i<8; ++i)
		cout << last[i];
	cout << endl;
}

void print_adjList(){
	for (int i = 0; i < 40321; ++i) {
		if (adjList[i].size() > 0) {
			for (int j = 0; j < adjList[i].size(); ++j) {
				cout << adjList[i][j].first << "(" << adjList[i][j].second << ")" << " ";
			}
			cout << endl;
		}
	}
}

void compute_dists(vector<int> last) {
	vector<int> newConfig(last);
	//cout << permToId.size() << endl;
	// Keep on the way
	for (int i = 0; i < 3; ++i) {
		iter_swap(newConfig.begin() + i, newConfig.begin() + i + 1);
		if (permToId.find(newConfig) == permToId.end()) {
			permToId.insert(make_pair(newConfig,permIDGen++));
			minDists.insert(make_pair(permIDGen - 1,INT_MAX));
			adjMatrix[permIDGen-1][permIDGen-1] = true;
		}
		if (!adjMatrix[permToId[last]][permToId[newConfig]]) {
			adjMatrix[permToId[last]][permToId[newConfig]] = adjMatrix[permToId[newConfig]][permToId[last]] = true;
			adjList[permToId[last]].push_back(make_pair(permToId[newConfig],idToW[last[i]] + idToW[last[i+1]]));
			adjList[permToId[newConfig]].push_back(make_pair(permToId[last],idToW[last[i]] + idToW[last[i+1]]));
			compute_dists(newConfig);
		}
		iter_swap(newConfig.begin() + i, newConfig.begin() + i + 1);
	}
	
	for (int i = 4; i < 7; ++i) {
		iter_swap(newConfig.begin() + i, newConfig.begin() + i + 1);
		if (permToId.find(newConfig) == permToId.end()) {
			permToId.insert(make_pair(newConfig,permIDGen++));
			minDists.insert(make_pair(permIDGen - 1,INT_MAX));
			adjMatrix[permIDGen-1][permIDGen-1] = true;
		}
		if (!adjMatrix[permToId[last]][permToId[newConfig]]) {
			adjMatrix[permToId[last]][permToId[newConfig]] = adjMatrix[permToId[newConfig]][permToId[last]] = true;
			adjList[permToId[last]].push_back(make_pair(permToId[newConfig],idToW[last[i]] + idToW[last[i+1]]));
			adjList[permToId[newConfig]].push_back(make_pair(permToId[last],idToW[last[i]] + idToW[last[i+1]]));
			compute_dists(newConfig);
		}
		iter_swap(newConfig.begin() + i, newConfig.begin() + i + 1);
	}
	
	for (int i = 0; i < 4; ++i) {
		iter_swap(newConfig.begin() + i, newConfig.begin() + i + 4);
		if (permToId.find(newConfig) == permToId.end()) {
			permToId.insert(make_pair(newConfig,permIDGen++));
			minDists.insert(make_pair(permIDGen - 1,INT_MAX));
			adjMatrix[permIDGen-1][permIDGen-1] = true;
		}
		if (!adjMatrix[permToId[last]][permToId[newConfig]]) {
			adjMatrix[permToId[last]][permToId[newConfig]] = adjMatrix[permToId[newConfig]][permToId[last]] = true;
			adjList[permToId[last]].push_back(make_pair(permToId[newConfig],idToW[last[i]] + idToW[last[i+4]]));
			adjList[permToId[newConfig]].push_back(make_pair(permToId[last],idToW[last[i]] + idToW[last[i+4]]));
			print_vec(newConfig);
			//compute_dists(newConfig);
		}
		iter_swap(newConfig.begin() + i, newConfig.begin() + i + 4);
	}
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

	// Mapping all permutations 
	/*vector<int> permut (initial);
	int pId = 0;
	do {
		minDists.insert(make_pair(permut, INT_MAX));	
		permToId.insert(make_pair(permut,pId++));
	} while (next_permutation(permut.begin(), permut.end()));*/
	permToId.insert(make_pair(initial,0));
	compute_dists(initial);
	//print_adjList();
	cout << permToId.size() << endl;
	cout << permToId[goal] << endl;
	//print_edges();
	//cout << edges.size() << endl;
	return 0;
}
