#include <bits/stdc++.h>

int main(void) {

	int n, m;

	while(true) {
		scanf("%d%d", &n, &m);
		if(!n and !m) break;

		std::vector<int> diameters, heights;
		int d;
		for (int i = 0; i < n; ++i) {
			scanf("%d", &d);
			diameters.push_back(d);
		}
		int h;
		for (int j = 0; j < m; ++j) {
			scanf("%d", &h);
			heights.push_back(h);
		}
		sort(diameters.begin(), diameters.end());
		sort(heights.begin(), heights.end());
		int ans = 0;
		int i = 0, j = 0;
		while (i < n && j < m) {
			if (diameters[i] <= heights[j]) {
				ans += heights[j];
				++i;
				++j;
			} else ++j;
		}
		if (i < n) printf("Loowater is doomed!\n");
		else printf("%d\n", ans);
	}

	return 0;
}
