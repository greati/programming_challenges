#include <bits/stdc++.h>

using namespace std;

int main(void) {
	
	int M, L, N;
	int c[1001];
	int pd[1001][2001];


	while (true) {
		cin >> M >> L;
		if (M == L and M == 0) break;

		cin >> N;
		for (int i = 1; i <= N; ++i)
			cin >> c[i];
		
		for (int i = 0; i <= N; ++i) 
			pd[0][i] = 0;
		for (int i = 0; i <= M; ++i) 
			pd[i][0] = 0;

		int ans = 0;
		for (int j = 1; j <= N; ++j) {
			for (int w = 1; w <= M; ++w) {
				if (w >= c[j])
					pd[w][j] = std::max( pd[w][j-1], pd[w - c[j]][j-1] + c[j] );		
				else
					pd[w][j] = pd[w][j-1];
			}	
		}

		std::cout << pd[M][N] << std::endl;
		
	}

	return 0;
}
