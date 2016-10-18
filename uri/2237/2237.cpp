#include <bits/stdc++.h>

using namespace std;

map<vector<int>,int> permToId;
map<int,int> idToW;
map<int,int> wToId;
map<vector<int>,int> minDists;
vector<int> initial;
vector<int> goal;
map<pair<int,int>,int> edges;

void print_min_dists() {
	for (auto i = minDists.begin(); i != minDists.end(); ++i) {
		for (int j = 0; j < 8; ++j)
			cout << (i->first)[j];
		cout << "-" << (i->second) <<  endl;
	}
}

void print_edges() {
	for (auto i = edges.begin(); i != edges.end(); ++i) {
		cout << (i->first).first << "-" << (i->first).second << " = " << (i->second) <<  endl;
	}
}

void print_vec(vector<int> & last) {
	for (int i=0; i<8; ++i)
		cout << last[i];
	cout << endl;
}

void compute_dists(vector<int> last) {
	// Keep on the way
	for (int i = 0; i < 3; ++i) {
		vector<int> newConfig (last);
		iter_swap(newConfig.begin() + i, newConfig.begin() + i + 1);
		if ((edges.find(make_pair(permToId[last],permToId[newConfig])) == edges.end())) { 
			edges.insert(make_pair(make_pair(permToId[last],permToId[newConfig]), idToW[last[i]] + idToW[last[i+1]]));
			edges.insert(make_pair(make_pair(permToId[newConfig],permToId[last]), idToW[last[i]] + idToW[last[i+1]]));
			compute_dists(newConfig);
		}
	}
	
	for (int i = 4; i < 7; ++i) {
		vector<int> newConfig (last);
		iter_swap(newConfig.begin() + i, newConfig.begin() + i + 1);
		if ((edges.find(make_pair(permToId[last],permToId[newConfig])) == edges.end())) { 
			edges.insert(make_pair(make_pair(permToId[last],permToId[newConfig]), idToW[last[i]] + idToW[last[i+1]]));
			edges.insert(make_pair(make_pair(permToId[newConfig],permToId[last]), idToW[last[i]] + idToW[last[i+1]]));
			compute_dists(newConfig);
		}
	}
	
	for (int i = 0; i < 4; ++i) {
		vector<int> newConfig (last);
		iter_swap(newConfig.begin() + i, newConfig.begin() + i + 4);
		if ((edges.find(make_pair(permToId[last],permToId[newConfig])) == edges.end())) { 
			edges.insert(make_pair(make_pair(permToId[last],permToId[newConfig]), idToW[last[i]] + idToW[last[i+4]]));
			edges.insert(make_pair(make_pair(permToId[newConfig],permToId[last]), idToW[last[i]] + idToW[last[i+4]]));
			//compute_dists(newConfig);
		}
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
	vector<int> permut (initial);
	int pId = 0;
	do {
		minDists.insert(make_pair(permut, INT_MAX));	
		permToId.insert(make_pair(permut,pId++));
	} while (next_permutation(permut.begin(), permut.end()));

	compute_dists(initial);
	//print_edges();
	//cout << edges.size() << endl;
	return 0;
}
