#include <bits/stdc++.h>

using namespace std;

int main(void) {

	int ncases;

	vector<pair<int,int> > proj;

	int pd[101][51];

	cin >> ncases;

	while (ncases--) {
		
		proj.clear();

		int n;

		cin >> n;

		for (int i = 0; i < n; ++i) {
			int power, weight;
			cin >> power >> weight;
			proj.push_back(make_pair(power,weight));
		}

		int k;

		cin >> k;

		int r;

		cin >> r;

		for (int i = 0; i <= n; ++i)
			pd[0][i] = 0;	
		for (int i = 0; i <= k; ++i)
			pd[i][0] = 0;	
		
		for (int i = 1; i <= k; ++i) { 
			for (int j = 1; j <= n; ++j) {
				pd[i][j] = pd[i][j-1];
				if (i - proj[j-1].second >= 0)
					pd[i][j] = max(pd[i][j], pd[i - proj[j-1].second][j-1] + proj[j-1].first);
			}
		}
		
		
		if (pd[k][n] >= r)
			cout << "Missao completada com sucesso\n";
		else
			cout << "Falha na missao\n";
	}	

	return 0;
}
