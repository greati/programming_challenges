#include <iostream>
#include <set>
#include <cmath>

using namespace std;

int main(void) {

	int n;
	int values[3002];
	set<int> s;

	while(cin >> n) {
		s.clear();
		for (int i = 0; i < n; ++i) {
			cin >> values[i];
			if (i > 0) {
				int diff = abs(values[i] - values[i - 1]);
				if (diff >= 1 && diff <= (n - 1)) 
					s.insert(diff);
			}
		}
		cout << (s.size() == (n-1) ? "Jolly" : "Not jolly") << endl;
	}
	return 0;
}
