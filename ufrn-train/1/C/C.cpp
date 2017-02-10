#include <bits/stdc++.h>

using namespace std;

int main(void) {

    int n, m;

    cin >> n;

    vector<pair<int, int>> segs;

    while (n--) {

        cin >> m;
        
        int l, r;

        segs.clear();

        while (true) {
            cin >> l >> r;

            if (l == 0 and r == 0) break;

            segs.push_back(make_pair(l, r));
        }

        sort(segs.begin(), segs.end());

        int li = 0, seg_max = -1, i = 0;

        vector<int> selectedSegs;

        while (li < m && i < segs.size()) {


            while (segs[i].first <= li && i < segs.size()) {

                if (segs[i].second <= li) { i++; continue;}

                pair<int, int> cur = segs[i];

                int mod_max = (seg_max == -1 ? 0 : abs(segs[seg_max].second - li));
            
                if (abs(segs[i].second - li) > mod_max)
                    seg_max = i;

                ++i;
            }

            if (seg_max == -1) break;   // didn't found

            selectedSegs.push_back(seg_max);

            li = segs[seg_max].second;
            seg_max = -1;
        }
        
        if (li < m) selectedSegs.clear();

        cout << selectedSegs.size() << endl;

        for (auto s : selectedSegs)
            cout << segs[s].first << " " << segs[s].second << endl;

        cout << endl;
    }

    return 0;
}
