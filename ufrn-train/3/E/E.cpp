#include <bits/stdc++.h>

using namespace std;

int main(void) {

    int first;

    vector<int> heights;

    int t = 1;

    while (true) {
        
        cin >> first;

        if (first == -1) break;
        
        if (t > 1) printf("\n");

        heights.clear();

        heights.push_back(first);

        int h;

        while (true) {
            cin >> h;
            
            if (h == -1) break;

            heights.push_back(h);
        }

        //reverse(heights.begin(), heights.end());

        int * S = new int[heights.size()];

        S[0] = 1;
        int ans = 1;
        for (int i = 1; i < heights.size(); ++i) {
            S[i] = 1;
            for (int j = 0; j < i; ++j) {
                if (heights[i] <= heights[j])
                    S[i] = max(S[i], S[j] + 1);
            }
            ans = max(ans, S[i]);
        }
        
        printf("Test #%d:\n  maximum possible interceptions: %d\n", t, ans);
        
        ++t;

        delete [] S;
    }

    return 0;
}
