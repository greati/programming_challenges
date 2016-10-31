#include <bits/stdc++.h>

using namespace std;

struct Point {
	int id, x, y;
	Point(){};
	Point(int _x, int _y, int _id) : x {_x}, y {_y}, id {_id}{}; 
};

double euclidean(Point b1, Point b2) {
	return sqrt((double) ((b2.x - b1.x) * (b2.x - b1.x) + (b2.y - b1.y) * (b2.y - b1.y)));
}

bool reacheable(Point b1, Point b2, Point r) {
	return euclidean(b1,r) + euclidean(b2,r) <= 2 * euclidean(b1,b2);	
}

struct Edge {
	Point p;
	int residual;
	Edge * opposite;
	Edge() {};
	Edge(Point _p) : p {_p}, residual {1}, opposite {nullptr} {};
	Edge(Point _p, int w) : p {_p}, residual {w}, opposite {nullptr} {};
};

vector<Edge> graph[207];
bool vis[207];
int parent[207];
Edge* path[207];

/* Para cada ponto i de bob, guarda
 * um lugar interessante visitado,
 * de forma que visitedPlaces[i]
 * retorna o ponto interessante visitado
 * a partir de i. Com ele, é possível
 * imprimir todos os pontos da rota.
 * **/
Point * visitedPlaces[207];

int s = 205, t = 206;

int flow = 0;

int updateNetwork(int vertex, int minCapacity){
	if (parent[vertex] != -1) {
		Edge * edgeInPath = path[vertex];
		int m = updateNetwork(parent[vertex], min(minCapacity, edgeInPath->residual));			
		edgeInPath->residual = 0;
		if (edgeInPath->opposite != nullptr)
			((edgeInPath->opposite)->residual) = 1;
		return m;
	}
	return minCapacity;
}

int main(void) {

	int L, m, n, _x, _y;

	scanf("%d", &L);

	Point bobs[101];
	Point ralphs[101];

	Point epp {1000,1000, t};
	Edge et {epp};

	Point sp {1000,1000,s};

	queue<int> q;

	while (L--) {

		for (int i = 0; i < 207; ++i) {
			graph[i].clear();
			visitedPlaces[i] = nullptr;
		}

		scanf("%d%d", &n, &m);	
	
		for (int i = 0; i < n; ++i) {
			scanf("%d%d", &_x, &_y);
			Point p {_x, _y, i};
			bobs[i] = p;
			Edge e {p};
			//Edge ep{sp,0};
			//e.opposite = &ep;
			//ep.opposite = &e;
			graph[s].push_back(e);
			//graph[i].push_back(ep);
		}	
	
		for (int i = 0; i < m; ++i) {
			scanf("%d%d", &_x, &_y);
			Point p {_x, _y, n + i};
			ralphs[i] = p;
			Edge e {p};
			graph[p.id].push_back(et);
		}

		for (int i = 0; i < n - 1; ++i) {
			Point b1 = bobs[i];	
			Point b2 = bobs[i + 1];	
			for (int j = 0; j < m; ++j) {
				if (reacheable(b1,b2,ralphs[j])) {
					Edge e {ralphs[j]};
					Edge ep {bobs[i], 0};
					e.opposite = &ep;
					ep.opposite = &e;
					graph[i].push_back(e);
					graph[n + j].push_back(ep);
				}
			}
		}
		
		/*for (int i = 0; i < n + m; ++i) {
			cout << i << " -> ";
			for (int j = 0; j < graph[i].size(); ++j) {
				cout << graph[i][j].p.id << " ";	
			}
			cout << endl;
		}*/
	
		flow = 0;
		
		do {
			for (int i = 0; i < 207; ++i) {
				vis[i] = false;
				parent[i] = -1;
			}
			q.push(s);
			vis[s] = true;
			while (!q.empty()) {
				int cur = q.front();
				for (int i = 0; i < graph[cur].size(); ++i) {
					Edge * e = &graph[cur][i];
					if ((e->residual) == 1 && !vis[e->p.id]) {
						q.push(e->p.id);
						vis[e->p.id] = true;	
						path[e->p.id] = e;
						parent[e->p.id] = cur;
					}
				}	
				q.pop();
			}			
			if(vis[t]) {
				flow += updateNetwork(t,1<<30);
				visitedPlaces[parent[path[parent[t]]->p.id]] = &ralphs[path[parent[t] - n]->p.id];
			}
		} while (vis[t]);	

		printf("%d\n", n + flow);
		for (int i = 0; i < n; ++i) {
			printf(i != (n-1) ? "%d %d " : "%d %d", bobs[i].x, bobs[i].y);
			if (visitedPlaces[i] != nullptr) {
				printf("%d %d ", visitedPlaces[i]->x, visitedPlaces[i]->y);
			}
		}
		printf("\n\n");
		
	}	
}
