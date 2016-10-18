#include <bits/stdc++.h>

using namespace std;

int main(void) {

	int n, m;

	int m[51][51];

	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			scanf("%d", &m[i][j]);
		}
	}

	return 0;
}
