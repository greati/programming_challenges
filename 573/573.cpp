#include <bits/stdc++.h>

using namespace std;

int main(void) {

    double h, u, d, f;

    while(scanf("%lf%lf%lf%lf", &h, &u, &d, &f) != EOF) {
        if (h == 0) break;

        double curHeight = 0, curDay = 1, curUp = u, lost = u * (f/100.00);
        while(true) {

            if (curDay > 1)
                curUp -= lost;

            if (curUp >= 0)
                curHeight += curUp;

            if (curHeight > h) {
                cout << "success on day " << curDay << endl;
                break;
            }

            curHeight -= d;

            if (curHeight < 0) { 
                cout << "failure on day " << curDay << endl;
                break;
            }

            ++curDay;
        }
        
    }

    return 0;
}
