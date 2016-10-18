#include <bits/stdc++.h>

using namespace std;

int main(void) {

	int T, n, c, sum, next, ans;
	
	int cs[1001];

	scanf("%d", &T);

	while (T--) {
		scanf("%d", &n);
		
		for (int i = 0; i < n; ++i)
			scanf("%d", &cs[i]);
		cs[n] = INT_MAX;
		
		sum = 0;
		next = 1;
		ans = 0;

		for (int i = 0; i < n; ++i) { 
			if (sum + cs[i] < cs[next]) {
				sum += cs[i];
				ans++;				
			}	
			next++;
		}

		printf("%d\n", ans);
	}

	return 0;
}
