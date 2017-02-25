#include <bits/stdc++.h>

using namespace std;

int n, m;
int nums[1001][1001];

long long S (int, int, int);

int main(void) {

    long long sum[1001][1001];
    int t = 0;

    while (scanf("%d %d", &n, &m) != EOF) {
       if (t++) printf("\n");
       // Read and set sums of size 1
       for (int i = 0; i < n; ++i) {
           for (int j = 0; j < n; ++j) {
               scanf("%d", &nums[n-i-1][j]);
               sum[n-i-1][j] = nums[n-i-1][j];
           }
       }

       // Sums for size >= 2
       for (int s = 2; s <= m; ++s) {
           for (int i = 0; i <= n - s; ++i) {
               for (int j = 0; j <= n - s; ++j) {
                   sum[i][j] = sum[i][j] + S(i, j, s);
               }
           }
       }

       long long total = 0;
       for (int i = n-m; i >= 0; --i) {
           for (int j = 0; j <= n - m; ++j) {
               total += sum[i][j];
               printf("%lld\n", sum[i][j]);
           }
       }
       printf("%lld\n", total);
    
    }

    return 0;
}

long long S(int i, int j, int s) {
    long long acc = 0;
    for (int ii = i; ii <= i + s - 1; ++ii)
        acc += nums[ii][j + s - 1];
    for (int jj = j; jj <= j + s - 1; ++jj)
        acc += nums[i + s - 1][jj];
    acc -= nums[i+s-1][j+s-1];
    return acc;
}
