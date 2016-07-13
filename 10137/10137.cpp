#include <iostream>
#include <math.h>
#include <cstdio>
#include <stdlib.h>

using namespace std;

int main(void) {

	int n;

	double v[1000];

	while (true) {
		
		scanf("%d", &n);

		if (n == 0) return 0;

		double av = 0;

		for (int i = 0; i < n; ++i) {
			scanf("%lf", &v[i]);
			av += v[i]; 
		}

		av /= n;

		double posDiff = 0, negDiff = 0;
		for (int i = 0; i < n; ++i) {
			double va = (long) ((v[i] - av) * 100.0) / 100.0;
			if (va > 0) posDiff += va;
			else negDiff += va;
		}
	
		negDiff = -negDiff;
		printf("$%.2f\n", negDiff > posDiff ? negDiff : posDiff);
	}	

	return 0;
}
