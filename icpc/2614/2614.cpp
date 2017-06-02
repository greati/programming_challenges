#include <bits/stdc++.h>

using namespace std;

int main(void) {
	
	int M, L, N;
	int c[1001];
	int pd[1001][2001];
	std::vector<int> boxes;

	while (true) {
		cin >> M >> L;
		if (M == L and M == 0) break;

		boxes.clear();
		int sum_caps = 0;
		cin >> N;
		for (int i = 1; i <= N; ++i) {
			cin >> c[i];
			sum_caps += c[i];
		}
		
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

		if (L >= sum_caps - pd[M][N]) {
			int H = M;
			for (int j = N; j >= 1; --j) {
				if (pd[H][j] != pd[H][j-1]) {
					boxes.push_back(j);
					H -= c[j];
				}
			}
			std::reverse(boxes.begin(), boxes.end());
			
			std::cout << boxes.size() << " ";
			for (unsigned int j = 0; j < boxes.size(); ++j) {
				std::cout << boxes[j];
				if (j != boxes.size() - 1) std::cout << " ";
			}
			std::cout << std::endl;
		} else std::cout << "Impossible to distribute" << std::endl;
		
	}

	return 0;
}
