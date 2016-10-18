#include <bits/stdc++.h>

using namespace std;

int main(void) {

	int n, l, w;

	while (scanf("%d%d%d", &n, &l, &w) != EOF) {
		
		vector<pair<int, int>> sprinkles;
		int p,r;
		for (int i = 0; i < n; ++i) {
			scanf("%d%d", &p, &r);
			sprinkles.push_back(make_pair(p,r));
		}

		sort(sprinkles.begin(), sprinkles.end());

		for (int i = 0; i < n; ++i) {
			
		
		}

	}


	return 0;
}
