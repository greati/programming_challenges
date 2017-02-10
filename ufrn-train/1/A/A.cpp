#include <bits/stdc++.h>

using namespace std;

int main(void) {
    
    int C, S, s;

    s = 1;
    while (cin >> C) {
        cin >> S;

        int A = 0;
        if (S < 2*C) 
            A = 2*C - S;

        list<int> v;

        for (int i = 0; i < A; ++i) v.push_back(0);
    
        double sum = 0.0;

        int a;
        for (int i = 0; i < S; ++i) {
            cin >> a;
            sum += a + 0.0;
            v.push_back(a);
        }

        sum /= C;

        v.sort();

        double imb = 0.0;
        int c = 0;
        cout << "Set #" << s << endl;
        while (!v.empty()) {
           cout << " " << c << ":";
        
           if (v.front() != 0) {
               cout << " " << v.front();
               if (v.back() != 0) cout << " ";
           }
           if (v.back() != 0) { 
               if (v.front() == 0) cout << " ";
               cout << v.back();
           }
           cout << endl;
           imb += std::abs(v.back() + v.front() - sum);
           if (!v.empty())
               v.pop_back(); 
           if (!v.empty())
               v.pop_front(); 
           c++;
        }
        printf("IMBALANCE = %.5f\n", imb);
        cout << endl;
        s++;
    }

    return 0;
}
