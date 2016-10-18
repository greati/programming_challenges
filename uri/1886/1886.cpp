#include <bits/stdc++.h>

using namespace std;

int main(void) {
	int t;

	scanf("%d", &t);

	set<int> A,B;
	
	while (t--) {
		int n, m;

		for (int i = 0; i < m; ++i) {
			int u,v;
			scanf("%d %d", &u, &v);
			if (A.find(u) != A.end()) {
				B.insert(v);
			} else if (B.find(u) != B.end()) {
				A.insert(v);
			} else if (A.find(v) != A.end()) {
				B.insert(u);
			} else if (B.find(v) != B.end()) {
				A.insert(u);
			} else {
				A.insert(u); B.insert(v);
			}	
		}	
		
		for (auto it = A.begin(); it != A.end(); ++it)
			cout << (*it) << " ";
		cout << endl;
		for (auto it = B.begin(); it != B.end(); ++it)
			cout << (*it) << " ";
		cout << endl;

		//printf("%d\n", max(A.size(), B.size()));
		A.clear(); B.clear();
	}

	return 0;
}
