#include <bits/stdc++.h>

using namespace std;

int main(void){
	int r, k;

	int degree[101];
	bool pd[6000][101];

	while (cin >> r >> k) {

		for (int i = 1; i <= r; ++i)
			degree[i] = 0;

		for (int i = 1; i <= r; ++i)
			pd[0][i] = true;

		for (int i = 1; i <= k; ++i)
			pd[k][0] = false;

		for (int i = 0; i < k; ++i) {
			int from, to;
			cin >> from >> to;
			degree[from]++;
			degree[to]++;	
		}	
			
		for (int i = 1; i <= k; ++i) {
			for (int j = 1; j <= r; ++j) {
				pd[i][j] = pd[i][j-1];
				if (i - degree[j] >= 0) {
					pd[i][j] = pd[i][j] || (pd[i - degree[j]][j-1]);	
				}
			}
		} 

		printf("%c\n",(pd[k][r] ? 'S' : 'N'));
	}


}
