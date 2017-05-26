#include <bits/stdc++.h>

using namespace std;

/* k1/k2: queremos, não muda
 * m1/m2: raiz atual
 * n1/n2: gerador esquerdo da raiz atual
 * p1/p2: gerador direito da raiz atual
 * */
void search(int k1, int k2, int m1, int m2, int n1, int n2, int p1, int p2){
	if (k1 == m1 && k2 == m2) 
		return;
	double rk = (k1+0.0)/k2;
	double rm = (m1+0.0)/m2;
	if (rk >= rm) {
		std::cout << "R";
		search(k1,k2,m1+p1, m2+p2, m1, m2, p1, p2);
	} else {
		std::cout << "L";
		search(k1,k2,m1+n1, m2+n2, n1, n2, m1, m2);
	}
}

int main(void) {

	int m, n;
	
	while(true) {
		scanf("%d%d", &m, &n);
		if (m == 1 and n == 1) break;
		search(m, n, 1, 1, 0, 1, 1, 0);
		std::cout << std::endl;
	}

	return 0;
}
