#include <iostream>
#include <limits.h>

using namespace std;

int main(void) {
	
	int i, j;

	while (cin >> i >> j) {
		int is = i, js = j;
		if (i > j) swap(i,j);
		int maxQtd = INT_MIN;	
		for (int ii = i; ii <= j; ++ii) {
			int n = ii;
			int qtd = 1;
			while (n != 1) {
				n = (n & 1) ? 3 * n + 1 : n / 2; 
				++qtd;
			}	
			maxQtd = max(maxQtd, qtd);
		}
		cout << is << " " << js << " " << maxQtd << endl;	
	}	

	return 0;
}
