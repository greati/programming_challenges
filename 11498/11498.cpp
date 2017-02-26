#include <bits/stdc++.h>

using namespace std;

int main(void) {

    int k;
    int n, m;

    while (true) {
        cin >> k;

        if (!k) break;

        cin >> n >> m;

        while (k--) {
            int x, y;
            cin >> x >> y;
            if (x == n || y == m) cout << "divisa" << endl;
            else if (x < n && y > m) cout << "NO" << endl;
            else if (x > n && y > m) cout << "NE" << endl;
            else if (x < n && y < m) cout << "SO" << endl;
            else if (x > n && y < m) cout << "SE" << endl;
        }
    }
    return 0;
}
