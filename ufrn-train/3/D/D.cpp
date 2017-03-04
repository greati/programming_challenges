#include <bits/stdc++.h>

using namespace std;

int main(void) {

    string line;

    int n;

    int order[21];
    int student[21];
    int S[21];
    map<int, unordered_set<int>> graph;

    while (getline(cin, line)) {

       if (line == "") break;

       if (line.size() <= 2) {
           stringstream ssn {line};
           ssn >> n;

           getline(cin, line);
           stringstream sso {line};

           for (int i = 1; i <= n; ++i) {
               int o;
               sso >> o;
               order[o] = i;
           }

           graph.clear();

           for (int i = 1; i <= n; ++i) {
               unordered_set<int> s;
               for (int j = i + 1; j <= n; ++j) {
                   s.insert(order[j]);
               }
               graph.insert(make_pair(order[i], s));
           }

       } else {

           stringstream sss {line};
           for (int i = 1; i <= n; ++i) {
               int k;
               sss >> k;
               student[k] = i;
           
           }

           int ans = 0;
           S[1] = 1;
           for (int i = 2; i <= n; ++i) {
               S[i] = 1;
               for (int j = 1; j < i; ++j) {
                   if (graph[student[j]].find(student[i]) != graph[student[j]].end()) {
                       S[i] = max(S[i], S[j] + 1);
                   }
               }
               ans = max(ans, S[i]);
           }
           cout << ans << endl;
       }
    
    }

    return 0;
}
