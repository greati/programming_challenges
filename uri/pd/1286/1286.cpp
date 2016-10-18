#include <bits/stdc++.h>

using namespace std;

int main(void) {
	
	int n, p;
	vector<pair<int,int> > pizzas;
	int pd[31][21];

	while (true) {
		cin >> n;

		if (n == 0) return 0;

		pizzas.clear();

		for (int j = 0; j < 21; ++j)
			pd[0][j] = 0;
		for (int j = 0; j < 31; ++j)
			pd[j][0] = 0;

		cin >> p;	

		for (int i = 0; i < n; ++i) {
			int time, qtd;
			cin >> time >> qtd;	
			pizzas.push_back(make_pair(time,qtd));
		}

		for (int i = 1; i <= p; ++i) {
			for (int j = 1; j <= n; ++j) {
				pd[i][j] = pd[i][j - 1];
				if (i - pizzas[j-1].second >= 0) {
					pd[i][j] = max(pd[i][j], pd[i - pizzas[j-1].second][j - 1] + pizzas[j-1].first);
				}
			}
		}

		cout << pd[p][n] << " min." << endl;
	}

	return 0;
}
