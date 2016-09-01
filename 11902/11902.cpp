#include <bits/stdc++.h>

using namespace std;

int T;
int graph[101][101];
char domination[101][101];
int n;
unordered_set<int> reacheable;
bool vis[101];

void print(int c) {
	printf("Case %d:\n", c);
	for (int i = 0; i < 2*n + 1; ++i) {	
		if (!(i & 1)) {
			printf("+");
			for (int j = 0; j < 2*n - 1; ++j)	
				printf("-");
			printf("+");
		} else {
			for (int j = 0; j < n; ++j) {	
				printf("|%c", domination[(i - 1)/2][j]);	
			}
			printf("|");
		}
		printf("\n");
	}
}

void DFS_reach(int v){
	vis[v] = true;
	reacheable.insert(v);
	domination[v][v] = 'Y';
	for (int i = 0; i < n; ++i) {
		if (graph[v][i] and not vis[i]) {
			DFS_reach(i);
		}
	}	
}

void DFS_dominator(int v, int excluded){
	if (v == excluded) return;
	vis[v] = true;
	for (int i = 0; i < n; ++i) {
		if (graph[v][i] and not vis[i])
			DFS_dominator(i, excluded);
	}	
}

void clear_case() {
	reacheable.clear();
	for (int i = 0; i < n; ++i) {
		vis[i] = false;
		for (int j = 0; j < n; ++j) {
			domination[i][j] = 'N';
			graph[i][j] = 0;
		}
	}
}

void clear_vis() {
	for (int i = 0; i < n; ++i)
		vis[i] = false;
}

int main(void) {
	
	scanf("%d", &T);
	
	for (int c = 1; c <= T; ++c) {
		
		scanf("%d", &n);	
		
		clear_case(); 
		
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				scanf("%d", &graph[i][j]);
			}	
		}
		
		// Get all reacheable from 0
		DFS_reach(0);

		for (auto i = reacheable.begin(); i != reacheable.end(); ++i) {
			clear_vis();
			DFS_dominator(0, *i);		
			for (int j = 0; j < n; ++j) {
				if (*i != j && reacheable.find(j) != reacheable.end() && !vis[j]) 
					domination[*i][j] = 'Y';
			}	
		}		

		print(c);
	}	

	return 0;
}
