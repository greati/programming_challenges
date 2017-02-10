#include <bits/stdc++.h>

using namespace std;

int main(void) {

    int c = 1;
    while (true) {
        
        int n, d;

        cin >> n >> d;

        if (n == 0 and d == 0) break;

        vector<pair<int, int>> islands;

        bool impossible = false;

        for (int i = 0; i < n; ++i) {
            int a, b;
            cin >> a >> b;
            if (b > d) impossible = true;
            else islands.push_back(make_pair(a, b));
        }

        cout << "Case " << c << ": ";

        if (!impossible) {
            sort(islands.begin(), islands.end()); 

            int i = 0, ans = 0;
            double last_radar = d*d+1;

            pair<int, int> cur;
            while (i < islands.size()) {
                cur = islands[i];
                if(!(d*d >= ((cur.second * cur.second) + ((cur.first - last_radar) * (cur.first - last_radar))))){
                    last_radar = cur.first + sqrt(d*d - cur.second*cur.second); 
                    ans++;
                    ++i;
                } else ++i;
            }
            cout << ans;
        } else cout << "-1";
        cout << endl; 
        c++; 
    }

    return 0;
}
