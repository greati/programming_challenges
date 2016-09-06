#include <bits/stdc++.h>

using namespace std;

map<char,int> vmap;
map<int,char> vmaptochar;
vector<int> graph[21];
int indegrees[21];
int n;
bool mark[21];
priority_queue<string,vector<string>,greater<string>> orders;

void topsort_visit(string & out) {	

	bool print = true;

	for (int i = 1; i <= n; ++i) {
		if (!mark[i] and indegrees[i] == 0) {
			print = false;
			mark[i] = true;
			for (int j = 0; j < graph[i].size(); ++j) {
				int adj = graph[i][j];
				indegrees[adj]--;
			}
			out += vmaptochar[i];
			topsort_visit(out);
		
			mark[i] = false;
			out.pop_back();
			for (int j = 0; j < graph[i].size(); ++j) {
				int adj = graph[i][j];
				indegrees[adj]++;
			}
		}
	}
	if (print) {
		orders.push(out);
	}
}


void print() {
	while (!orders.empty()) {
		cout << orders.top() << endl;
		orders.pop();
	}
}

void alltopsort() {
	string out;
	topsort_visit(out);
	print();
}

void clear() {
	for (int i = 1; i <= n; ++i) {
		mark[i] = false;
		indegrees[i] = 0;
		graph[i].clear();
	}
	vmap.clear();
	vmaptochar.clear();
}

int main(void) {
	string vars;
	string cons;
	bool primeira = false;
	while (getline(cin, vars)) {
		if (!primeira) primeira = true;
		else printf("\n");
		clear();
		n = 1;
		for (int i = 0; i < vars.length(); i += 2) {
			vmap.insert(make_pair(vars[i],i/2 + 1));
			vmaptochar.insert(make_pair(i/2 + 1,vars[i]));
			n++;
		}
		n--;	
		getline(cin,cons);
		for (int i = 0; i < cons.length(); i += 2) {
			char from = cons[i];
			char to = cons[i + 2];
			i += 2;
			graph[vmap[from]].push_back(vmap[to]);
			indegrees[vmap[to]]++;
		}

		alltopsort();
	}
	return 0;
}
