#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int t;

    cin >> t;

    for (int i = 1; i <= t; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        cout << "Case " << i << ": ";
        if (a >= b && a <= c || a >= c && a <= b)
            cout << a;
        else if (b >= a && b <= c || b >= c && b <= a)
            cout << b;
        else cout << c;
        cout << endl;
    }

    return 0;
}
