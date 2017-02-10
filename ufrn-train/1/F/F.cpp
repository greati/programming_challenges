#include <bits/stdc++.h>

using namespace std;

int v[10000];

int main(void) {

    int n;

    while (true) {

        cin >> n;

        if (n == 0) break;

        for (int i = 0; i < n; ++i) {
            cin >> v[i]; 
        }
    
        int maxa = 0, max_now = 0;
        for (int i = 0; i < n; ++i) {
            max_now = max(0, max_now + v[i]);
            maxa = max(maxa, max_now);
        }

        if (maxa > 0)
            cout << "The maximum winning streak is " << maxa << "." << std::endl;
        else
            cout << "Losing streak." << endl;
    }


    return 0;
}
