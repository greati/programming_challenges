#include <bits/stdc++.h>

using namespace std;

struct Pos {
	int x, y;
	int h0;
	int distance;
	Pos(){};
	Pos (int xx, int yy, int hh) : x{xx}, y{yy}, h0{hh} {};
};

Pos tab[60][60];

int main(void) {

	int n, m;

	scanf("%d %d", &n, &m);	

	Pos nil {-1,-1,-1};

	// Cercamento
	for (int i = 0; i < m + 2; ++i) {
		tab[0][i] = nil; 
		tab[n + 1][i] = nil;
	}
	for (int i = 0; i < n + 2; ++i) {
		tab[i][0] = nil; 
		tab[i][m + 1] = nil;
	}
	
	// Leitura
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			Pos p;
			p.distance = INT_MAX;
			p.x = i; p.y = j;
			scanf("%d", &p.h0);
			tab[i][j] = p;
		}
	} 	

	int delta[4][2] = {{0,1},{0,-1},{-1,0},{1,0}};

	queue<Pos> q; 

	tab[1][1].distance = 0;
	q.push(tab[1][1]);

	int ans = INT_MAX;

	while (!q.empty()) {
		
		Pos cur = q.front();

		if (cur.x == n and cur.y == m) {
			ans = min(ans, cur.distance);
			q.pop();
			continue;
		}

		int curH = (cur.h0 + cur.distance) % 10;

		for (int i = 0; i < 4; ++i) {
			int xx = cur.x + delta[i][0];
			int yy = cur.y + delta[i][1];		
			Pos neib = tab[xx][yy];
			if (neib.x != -1) { // evita que saia do tabuleiro
				int neibH = (neib.h0 + cur.distance) % 10;
				if (neibH <= curH + 1) {
					// se devo substituir o caminho
					if (neib.distance > cur.distance + 1) {
						tab[xx][yy].distance = cur.distance + 1;
						q.push(tab[xx][yy]);
					} 	
				} else {
					int tempoEspera = 9 - neibH + 1;
					if (neib.distance > cur.distance + 1 + tempoEspera) {
						tab[xx][yy].distance = cur.distance + 1 + tempoEspera;
						q.push(tab[xx][yy]);
					}
				}
			}
		}	
		q.pop();
	}
	
	printf("%d\n", ans); 

	return 0;
}
