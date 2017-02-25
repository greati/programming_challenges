#include <bits/stdc++.h>

using namespace std;


int S(int, int, int, int);

int m[26][26];

int main(void) {

    int n;

    cin >> n;

    int sum[26][26][26][26];

    while (n--) {

        string line;
        unsigned int l = 0;
        do {
            cin >> line;
            int j = 0;
            for (char a : line) {
                m[l][j] = a - '0';
                sum[1][1][l][j] = m[l][j];
                j++;
            }
            l++;
        } while (l < line.size());

        int ans = 0;
        for (unsigned int s1 = 1; s1 <= l; ++s1) {
            for (unsigned int s2 = 1; s2 <= l; ++s2) { 
                for (unsigned int i = 0; i <= l - s1; ++i) {
                    for (unsigned int j = 0; j <= l - s2; ++j) {
                        sum[s1][s2][i][j] = sum[s1-1][s2-1][i][j] + S(i, j, s1, s2);
                        // max calculation
                        if (sum[s1][s2][i][j] == (s1*s2) && sum[s1][s2][i][j] > ans)
                           ans = sum[s1][s2][i][j]; 
                    }
                }
            }
        }

        printf("%d\n", ans);

        if (n) printf("\n");
    
    }

    return 0;
}

int S (int i, int j, int s1, int s2) {
    int acc = 0;
    for (int ii = i; ii <= i + s1 - 1; ++ii)
        acc += m[ii][j + s2 - 1]; 
    for (int jj = j; jj <= j + s2 - 1; ++jj)
        acc += m[i + s1 - 1][jj]; 
    acc -= m[i+s1-1][j+s2-1];
    return acc;
}
