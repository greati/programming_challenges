#include <bits/stdc++.h>

using namespace std;

int parent[1001];

void find(int u) {
	if (u != parent[u])
		parent[u] = find(parent[u]);
}

int main(void) {


}
