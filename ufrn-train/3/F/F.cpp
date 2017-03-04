#include <bits/stdc++.h>

using namespace std;

int main(void) {


    int heights[31];
    int areas[31];
    int S[31];
    int P[31];

    int n;
    int t = 1;
    while (true) {

        cin >> n;

        if (n == 0) break;
        
        for (int i = 0; i < n; ++i) {
            int x, y, z;
            cin >> x >> y >> heights[i];
            areas[i] = x*y;
        }

        S[0] = 1;
        P[0] = -1;
        int maxsum = 1, maxindex = 0;
        for (int i = 1; i < n; ++i) {
            S[i] = 1;
            P[i] = -1;
            for (int j = 0; j < i; ++j) {
                if (areas[i] < areas[j]) {
                    if ( S[i] < S[j] + 1 ) {
                        P[i] = j;
                        S[i] = S[j] + 1;
                    }
                }
            }
            if (maxsum < S[i]) {
                maxsum = S[i];
                maxindex = i;
            }
        }

        int i = maxindex;
        int ans = 0;
        while (i != -1) {
            ans += heights[i];
            i = P[i];
        }

        printf("Case %d: maximum height = %d\n", t, ans);
    
        t++;
    }

    return 0;
}
