#include <bits/stdc++.h>

using namespace std;

int graph[102][102];

const int infinity = 10000000;

void floyd_warshall(int n) {
	for (int k = 0; k < n; ++k)
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
}

int main(void) {

	int M, N;

	scanf("%d%d", &N, &M);

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			graph[i][j] = (i == j) ? 0 : infinity; 
	
	for (int i = 0; i < M; ++i) {
		int u,v,w;
		scanf("%d%d%d", &u, &v, &w);
		graph[u][v] = graph[v][u] = w;
	}	

	floyd_warshall(N);

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cout << graph[i][j] << " ";	
		}
		cout << endl;
	}

	cout << "////" << endl;

	floyd_warshall(N);

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cout << graph[i][j] << " ";	
		}
		cout << endl;
	}

	return 0;
}
