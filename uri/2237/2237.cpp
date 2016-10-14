#include <bits/stdc++.h>

using namespace std;

map<int,int> wToId;
map<vector<int>,int> minDists;


void print_min_dists() {
	for (auto i = minDists.begin(); i != minDists.end(); ++i) {
		for (int j = 0; j < 8; ++j)
			cout << (i->first)[j];
		cout << "-" << (i->second) <<  endl;
	}
}

void compute_dists(vector<int> config) {
	for (int i = 0; i < 3; ++i) {
		config.swap(i, i+1);
		compute_dists(config); 
		config.swap(i, i + 4);
		compute_dists(config); 
	}
	for (int i = 4; i < 6; ++i) {
		config.swap(i, i+1);
		compute_dists(config); 
		config.swap(i, i + 4);
		compute_dists(config); 
	}

}

int main(void) {

	vector<int> initial;
	vector<int> goal;

	// Getting initial configuration + mapping weights
	for (int i = 0; i < 8; ++i) {
		int a; scanf("%d", &a);
		wToId.insert(make_pair(i,a));
		initial.push_back(i);
	}
		
	// Getting final configuration
	for (int i = 0; i < 8; ++i) {
		int a; scanf("%d", &a);
		goal.push_back(a);
	}
	
	// Mapping all permutations 
	vector<int> permut (initial);
	do {
		minDists.insert(make_pair(permut, INT_MAX));	
	} while (next_permutation(permut.begin(), permut.end()));

	return 0;
}
