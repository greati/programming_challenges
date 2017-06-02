#include <bits/stdc++.h>
#define INF 10000000.0

using namespace std;

double pd[101][100001];

int main(void) {

	int M, N;
	int jones_list[101];
	std::vector<std::pair<int, double>> products;

	while (true) {
	
		cin >> M >> N;

		if (M == N && M == 0) break;

		products.clear();
		
		pd[0][0] = INF;

		for (int i = 1; i <= M; ++i) {
			cin >> jones_list[i];
			pd[i][0] = INF;
		}

		products.push_back(std::make_pair(0,0));
		for (int i = 1; i <= N; ++i) {
			int a;
			double b;
			std::cin >> a >> b;
			products.push_back(std::make_pair(a, b));
			pd[0][i] = 0.0;
		}


		for (int i = 1; i <= M; ++i) {
			for (int j = 1; j <= N; ++j) {
				if (products[j].first == jones_list[i])
					pd[i][j] = std::min(pd[i-1][j-1] + products[j].second,
							pd[i][j-1]);
				else
					pd[i][j] = pd[i][j-1];
			}
		}

		if (pd[M][N] >= INF)
			std::cout << "Impossible" << std::endl;
		else
			printf("%.2f\n", pd[M][N]);
	}

	return 0;
}
