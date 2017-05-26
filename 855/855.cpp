#include <bits/stdc++.h>

int main(void) {
	int t;
	scanf("%d", &t);
	std::vector<int> x, y;
	while (t--) {
		int s, a, f;
		scanf("%d%d%d", &s, &a, &f);
		int sf, af;
		for (int i = 0; i < f; ++i) {
			scanf("%d%d", &sf, &af);
			x.push_back(sf);
			y.push_back(af);
		}
		sort(x.begin(), x.end());
		sort(y.begin(), y.end());
		printf("(Street: %d, Avenue: %d)\n", x[(f-1)/2], y[(f-1)/2]);
		x.clear(); y.clear();
	}
	return 0;
}
