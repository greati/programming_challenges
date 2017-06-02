#include <bits/stdc++.h>

using namespace std;

int main(void) {

	int N;
	double F;
	int areas[201];
	int sum[201][201];
	double pd[201][201];

	while (true) {
		cin >> N >> F;
		
		if (N == F and N == 0) break;

		int total = 0;
		for (int i = 0; i < N; ++i) {
			cin >> areas[i];	
			total += areas[i];
		}

		// Compute sums
		for (int i = 0; i < N; ++i) {
			sum[i][i] = areas[i];
			for (int j = i + 1; j < N; ++j)
				sum[i][j] = sum[i][j-1] + areas[j];
		}

		for (int i = 1; i < N; ++i) 
			for (int j = 0; j < i; ++j) 
				sum[i][j] = sum[i][(j + (N-1)) % N] + areas[j];
		
		// PD
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				if (j == i) { pd[i][j] = 0; continue;}
				pd[i][j] = 10000000;
				for (int k = i; k < j + N; ++k) {
					pd[i][j] = std::min(pd[i][j], pd[i][k%N] + pd[(k+1)%N][j] + F*std::max(sum[i][k%N],sum[(k+1)%N][j]));
				}
			}
		}

		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				std::cout << pd[i][j] << " ";
			}
			std::cout << std::endl;
		}

	}
	return 0;
}
