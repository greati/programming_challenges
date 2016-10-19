#include <bits/stdc++.h>

using namespace std;

int main(void) {
	int t;

	scanf("%d", &t);

	set<int> A,B;

	bool vis[1001];

	while (t--) {
		int n, m;
		int ans = 0;

		scanf("%d %d",&n,&m);

		for (int i = 0; i <= n; ++i)
			vis[i] = false;

		for (int i = 0; i < m; ++i) {
			int u,v;
			scanf("%d %d", &u, &v);
			if (!vis[u] && !vis[v]) {
				ans++;
				vis[u] = vis[v] = true;
			}
						
			/*if (A.find(u) != A.end()) {
				B.insert(v);
			} else if (B.find(u) != B.end()) {
				A.insert(v);
			} else if (A.find(v) != A.end()) {
				B.insert(u);
			} else if (B.find(v) != B.end()) {
				A.insert(u);
			} else {
				A.insert(u); B.insert(v);
			}*/	
		}	
		cout << ans + (n-2*ans) << endl;
		//printf("%d\n", max(A.size(), B.size()));
		//A.clear(); B.clear();
	}

	return 0;
}
