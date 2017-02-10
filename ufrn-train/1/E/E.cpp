#include <bits/stdc++.h>

using namespace std;

long long p[101][101];

long long v[101];

int main(void) {
    
    while (cin >> v[0]) {
    
        long long maxa = v[0];

        int i, c = 1;
        while (true) {
            cin >> i;
            if (i == -999999) break;
            v[c] = i;
            maxa = std::max<long long>(i, maxa);
            ++c;
        }

        for (int i = 0; i < c - 1; ++i) 
            p[i][i] = v[i];

        for (int i = 0; i < c; ++i) {
            for (int j = i + 1; j < c; ++j) {
                p[i][j] = p[i][j-1] * v[j];
                maxa = std::max<long long>(p[i][j], maxa);
            }
        }

        cout << maxa << endl;
    
    }

    return 0;
}
