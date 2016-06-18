#include <iostream>
#include <stdlib.h>

using namespace std;

int main(void) {
	
	int m, n, num = 0;

	while (true) {

		cin >> m >> n;	
		
		if (m == 0 && m == n) return 0;
		
		if (num != 0)
			cout << endl;

		++num;

		char tab[102][102];	
		char resp[102][102];
		
		for (int i = 0; i < 102; ++i)
			for (int j = 0; j < 102; ++j) {
				resp[i][j] = 0;
				tab[i][j] = '.';
			}

		// Read tab
		for (int i = 1; i <= m; ++i) {
			for (int j = 1; j <= n; ++j) {
				cin >> tab[i][j];
			}
		}
		// Delta array
		int d[8][2] = {
				{1,1}, 
				{1,0}, 
				{0,1}, 
				{-1,-1}, 
				{-1,1}, 
				{1,-1}, 
				{-1,0},
				{0,-1}
		};
		// Eval tab
		for (int i = 1; i <= m; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (tab[i][j] != '*') {
					int qtd = 0;
					for (int k = 0; k < 8; ++k) {
						int ii = i + d[k][0];
						int jj = j + d[k][1];
						qtd += (tab[ii][jj] == '*') ? 1 : 0;
					}		
					resp[i - 1][j - 1] = qtd + '0';
				} else 
					resp[i - 1][j - 1] = '*';
			}
		}
		
		// Print resp
		cout << "Field #" << num << ":" << endl;
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				cout << resp[i][j];
			}
			cout << endl;
		}		
			
	}	

	return 0;
}
