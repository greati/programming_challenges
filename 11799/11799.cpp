#include <bits/stdc++.h>

using namespace std;

int main(void) {

    int t;

    cin >> t;

    for (int i = 0; i < t; ++i) {
        
        int n;

        cin >> n;

        int ans = 0;
        for (int j = 0; j < n; ++j) {
            int v;
            cin >> v;
            ans = max(ans, v);
        }

        cout << "Case " << i + 1 << ": " << ans << endl;
    
    }

    return 0;
}
