#include <bits/stdc++.h>

using namespace std;

int main(void) {

    int t;

    cin >> t;

    bool marked[1002];
    while (t--) {
    
        int n;
        cin >> n;

        vector<pair<double, int>> jobs;

        for (int i = 0; i < n; ++i) {
            int a, b;
            cin >> a >> b;
            jobs.push_back(make_pair((b + 0.0)/a, n - i));
        }

        sort(jobs.rbegin(), jobs.rend());

        for (int i = 0; i < jobs.size(); ++i) {
            printf("%d", -(jobs[i].second - n) + 1);
            if (i < jobs.size() - 1) printf(" ");
        }
        printf("\n");
        if (t > 0) printf("\n");
    
    }

    return 0;
}
