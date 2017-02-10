#include <bits/stdc++.h>

using namespace std;

vector<int> graph[101];
bool vis[101];

void bfs(const int & f) {
    queue<int> q;
    for (int i = 0; i < graph[f].size(); ++i) {
        q.push(graph[f][i]);
        vis[graph[f][i]] = true;
    }
    while (!q.empty()) {
        int v = q.front();
        for (int j = 0; j < graph[v].size(); ++j) {
            int a = graph[v][j];
            if (!vis[a]) {
                q.push(a);
                vis[a] = true;
            }
        }
        q.pop();
    }
} 

int main(void) {

    int n;

    while (true) {
        cin >> n;

        if (n == 0) break;

        for (int s = 0; s <= n; ++s)
            graph[s].clear();
    
        int i;

        while (true) {
            cin >> i;

            if (i == 0) break;

            int j;

            while (true) {
                cin >> j;

                if (j == 0) break;

                graph[i].push_back(j);
            }
        }

        int k, f;
        vector<int> unreach;

        cin >> k;

        for (int m = 0; m < k; ++m) {
            cin >> f;
            for (int ii = 1; ii <= n; ++ii) vis[ii] = false;
            bfs(f);
            unreach.clear();
            for (int ii = 1; ii <= n; ++ii) 
                if (!vis[ii]) unreach.push_back(ii);
            sort(unreach.begin(), unreach.end()); 
            cout << unreach.size();
            if (unreach.size() > 0) cout << " ";
            for (unsigned int ii = 0; ii < unreach.size(); ++ii) {
                cout << unreach[ii];
                if (ii < (unreach.size() - 1)) 
                    cout << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
