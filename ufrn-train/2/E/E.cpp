#include <bits/stdc++.h>

using namespace std;

int main(void) {

    double n, l, w;

    while (scanf("%lf %lf %lf", &n, &l, &w) != EOF) {

        vector<pair<double, double>> segments;

        for (int i = 0; i < n; ++i) {
            double p, r;
            scanf("%lf %lf", &p, &r);
            if (r*r - (w*w)/4 >= 0) {
                double rd = sqrt(r*r - (w*w)/4);
                //cout << "rd = sqrt de " << r*r << " menos " << (w*w)/4 << "=" << r*r - (w*w)/4 << endl;
                //cout << "w = " << w << "//p = " << p << "//rd = " << rd << ":" << p - rd << "," << p + rd << endl;
                segments.push_back(make_pair(p - rd, p + rd));
            }
        }

        sort(segments.begin(), segments.end());

        double max_size = 0;
        double inf = 0;
        int qtd = 0;
        int i = 0;
        int largest = -1;
        while (i < segments.size() && inf < l) {
            max_size = 0; largest = -1;
            while (i < segments.size() && segments[i].first <= inf) {
                if (segments[i].second <= inf) {++i; continue;}
                
                if (i < segments.size() && segments[i].second - inf > max_size) {
                    largest = i;
                    max_size = segments[largest].second - inf;
                }
                ++i;
            }
            if (largest == -1) break;           // Not found
            inf = segments[largest].second; 
            qtd++;
        }

        if (inf < l) printf("-1\n");
        else printf("%d\n", qtd);
    }

    return 0;
}
