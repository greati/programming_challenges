#include <bits/stdc++.h>
using namespace std;

bool vis[1001];
int sets[2];
int vertexSet[1001];
vector<int> adj[1001];
queue<int> q;

inline void fastRead_int(int *a)
{
	register char c=0;
	while (c<33) c=getchar_unlocked();
	*a=0;
	while (c>33) {
		*a=*a*10+c-'0';
		c=getchar_unlocked();
	}
}

int main(void) {
	int t;
	int n,m;
	int u,v;
	int neib;
	int cur, scur;
	fastRead_int(&t);
	while (t--) {
		fastRead_int(&n); fastRead_int(&m);
		// Cleaning
		for (int i = 0; i <= n; ++i) {
			*(vis + i) = false;
			(*(adj + i)).clear();
		}
		*(sets + 0) = *(sets + 1) = 0;
		// Read graph
		for (int i = 0; i < m; ++i) {
			fastRead_int(&u); fastRead_int(&v);
			(*(adj + u)).push_back(v);
			(*(adj + v)).push_back(u);			
		}	
		// BFS
		++(*(sets + 0));
		*(vertexSet + 1) = 0;
		q.push(1);
		*(vis + 1) = true;
		while (!q.empty()) {
			cur = q.front();
			scur = *(vertexSet + cur);
			for (int i = 0; i < (*(adj + cur)).size(); ++i) {
				neib = (*(adj + cur))[i];
				if (!(*(vis + neib))) {
					*(vis + neib) = true;
					q.push((*(adj+cur))[i]);
					++(*(sets + 1 - scur)); 	
					*(vertexSet + neib) = 1 - scur;
				}
			}
			q.pop();	
		}
		printf("%d\n", max(*(sets),*(sets+1)));
	}
	return 0;
}
