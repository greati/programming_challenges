#include <bits/stdc++.h>

using namespace std;

int main(void) {

	int N;
	float F;
	int areas[201];
	int sum[201][201];
	double pd[201][201];
	double res = 1000000000;

	while (true) {
		scanf("%d%f", &N, &F);
		
		if (N == F and N == 0) break;

		res = 10000000000;

		for (int i = 0; i < N; ++i) {
			scanf("%d", (areas + i));	
			sum[i][1] = areas[i];
		}

		for (int j = 2; j <= N; ++j)
			for (int i = 0; i < N; ++i)
				sum[i][j] = sum[i][1] + sum[(i+1)%N][j-1];

		for (int i = 0; i < N; ++i)
			pd[i][1] = 0;

		for (int j = 2; j <= N; ++j) {
			for (int i = 0; i < N; ++i) {
				pd[i][j] = 10000000;
				for (int k = 1; k < j; ++k) {
					pd[i][j] = std::min(pd[i][j], pd[i][k] + pd[(i+k)%N][j-k] + std::max(sum[i][k], sum[(i+k)%N][j-k]));
				}
			}
		}

		for (int i = 0; i < N; ++i)
			res = std::min(res, pd[i][N]);

		printf("%.2f\n", res * F);

	}
	return 0;
}
