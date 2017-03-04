#include <bits/stdc++.h>

using namespace std;

int main(void) {

    int t;

    cin >> t;


    for (int i = 0; i < t; ++i) {
        int n;
        string s;
        cin >> n >> s;

        int ans = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '.') {
                ans++;
                i += 2;
            }
        }

        printf("Case %d: %d\n", i+1, ans);
    }
    
    return 0;
}
