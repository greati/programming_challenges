#include <bits/stdc++.h>

using namespace std;

int main (void) {

    int n, b, h, w;

    while (scanf("%d%d%d%d", &n, &b, &h, &w) != EOF) {

        vector<pair<int, vector<int>>> hotels;
        for (int i = 0; i < h; ++i) {
            int p;
            scanf("%d", &p);
            vector<int> beds;
            for (int j = 0; j < w; ++j) {
                int b;
                scanf("%d", &b);
                beds.push_back(b);
            }
            hotels.push_back(make_pair(p, beds));
        }

        sort(hotels.begin(), hotels.end());

        bool found = false;
        for (const auto & h : hotels) {
            if (h.first * n > b) {
                printf("stay home\n");
                break;
            }
            for (const auto & bed : h.second) {
                if (bed >= n) {
                    int amount = h.first * n;
                    if (amount > b)
                        printf("stay home\n");
                    else
                        printf("%d\n", amount);
                    found = true;
                    break;
                }
            } 
            if (found) break;
        }
    
    }


    return 0;
}
