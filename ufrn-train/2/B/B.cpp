#include <bits/stdc++.h>

using namespace std;

int sum[101][101][101][101];
int m[101][101];

int S(int, int, int, int);

int main(void) {

    int n;

    scanf("%d", &n);

    // Input
    for (int i = 0; i < n; ++i) 
        for (int j = 0; j < n; ++j) {
            scanf("%d", &m[i][j]);
            sum[1][1][i][j] = m[i][j];
        }
   
    // Calculate
    int ans = INT_MIN;
    for (int s1 = 1; s1 <= n; ++s1) {
        for (int s2 = 1; s2 <= n; ++s2) {
            for (int i = 0; i <= n - s1; ++i) {
                for (int j = 0; j <= n - s2; ++j) {
                    sum[s1][s2][i][j] = sum[s1-1][s2-1][i][j] + S(i, j, s1, s2); 
                    ans = max(ans, sum[s1][s2][i][j]);
                }
            }
        }
    }

    printf("%d\n", ans);

    return 0;
}

int S (int i, int j, int s1, int s2) {
    int acc = 0;
    for (int ii = i; ii <= i + s1 - 1; ++ii) 
        acc += m[ii][j + s2 - 1];
    for (int jj = j; jj <= j + s2 - 1; ++jj) 
        acc += m[i + s1 - 1][jj];
    acc -= m[i + s1 - 1][j + s2 - 1];
    return acc;
}
