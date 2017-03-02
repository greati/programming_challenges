#include <bits/stdc++.h>

using namespace std;

int main(void) {

    int n, p, t = 1;

    while (true) {

        scanf("%d %d", &n, &p);
        if (n == 0 && p == 0) break;

        unordered_set<string> reqs;
        for (int i = 0; i < n; ++i) {
            string r;
            std::getline(cin, r);
            reqs.insert(r);
            cout << r << endl;
        }

        vector<tuple<int, double, int, string>> props;
        for (int i = 0; i < p; ++i) {
            string pro;
            std::getline(cin, pro);
            double price;
            cin >> price;
            int qtd;
            cin >> qtd;
            props.push_back(make_tuple(qtd, price, i, pro));
            for (int k = 0; k < qtd; ++k) {
                string a;
                std::getline(cin, a);
            }
        }
        sort(props.begin(), props.end());
        cout << "RPF #" << t << endl;
        cout << get<3>(props[0]) << endl;
        t++;
    }

    return 0;
}
