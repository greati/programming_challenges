#include <bits/stdc++.h>

using namespace std;

int main(void) {

    int n;

    int stops[20005];

    cin >> n;

    for (int k = 1; k <= n; ++k) {
        int s;

        cin >> s;
        
        for (int i = 1; i <= s - 1; ++i)
            cin >> stops[i]; 

        int max = 0, max_now = 0, im = 1, jm = 1, it = 1, jt = 1;
        for (int i = 1; i <= s - 1; ++i) {
            if (max_now + stops[i] >= 0) {
                max_now = max_now + stops[i];
                jt = i + 1;
                if (max_now > max || (max_now == max && jt - it > jm - im)) {
                    max = max_now;
                    im = it;
                    jm = jt;
                }
            }
            else { 
                max_now = 0;
                it = i + 1;
            }
        }  
        if (max > 0)    
            cout << "The nicest part of route " << k << " is between stops " << im << " and " << jm << endl;
        else
            cout << "Route " << k << " has no nice parts" << endl;
    }

    return 0;
}
