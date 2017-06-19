#include <bits/stdc++.h>

using namespace std;

int pd[131072][17][2];

int main(void) {

	int K, h, n;

	scanf("%d%d", &K, &h);

	while (K--) {
			
		scanf("%d", &n);

		for (int i = 0; i <= n; ++i)
			for (int j = 0; j <= h; ++j)
				pd[i][j][0] = pd[i][j][1] = 0;

		pd[0][0][0] = pd[0][0][1] = 1;

		//for (int i = 0; i <= h; ++i) {
			pd[1][0][0] = 0;	
			pd[1][0][1] = 1;	
			pd[1][1][0] = 1;	
			pd[1][1][1] = 0;	
		//}
		for (int i = 2; i <= n; ++i) {
			//pd[i][0][0] = 1;	
			//pd[i][0][1] = 1;	
		}

		for (int i = 2; i <= n; ++i) {
			for (int j = 1; j <= h; ++j) {
				for (int k = 0; k < i; ++k) {
					pd[i][j][0] += (pd[k][j-1][0] * pd[i - k - 1][j-1][0]);// % 258280327;	
					pd[i][j][0] += (pd[k][j-1][1] * pd[i - k - 1][j-1][1]);// % 258280327;	
					//pd[i][j][0] += (pd[k][j-1][1] * pd[i - k - 1][j-1][0]);// % 258280327;	
				}
				for (int k = 0; k < i; ++k)
					pd[i][j][1] += (pd[k][j][0] * pd[i - k - 1][j][0]);// % 258280327;	
			}
		}

		/*for (int i = 0; i <= n; ++i) {
			for (int j = 0; j <= h; ++j)
				cout << pd[i][j][0] << " ";
			cout << endl;
		}
		std::cout << endl;*/

		int ans = 0;
		for (int i = 0; i <= h; ++i) {
			ans += (pd[n][i][0] + pd[n][i][1]);// % 258280327;
		}
		
		printf("%d", ans);// % 258280327);
		if (K != 0) printf(" ");
	}

	printf("\n");

	return 0;
}
