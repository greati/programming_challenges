#include <iostream>

using namespace std;

char image[251][251];

int main(void) {

	while (true) {

		char op = 'I';
		int m, n;
		int x1, x2, y1, y2;
		char color;

		do {
			cin >> op;

			switch (op) {
				case 'I':
					cin >> m >> n;
					initialize(m, n);
					break;
				case 'C':
					initialize(m, n);
					break;
				case 'L':
					cin >> x1 >> y1 >> color;
					image[x1][y1] = color;
					break;
				case 'V':
					cin >> x1 >> y1 >> y2 >> color;
					drawVert(x1,y2,y2,color);
					break;
				case 'H':
					cin >> y1 >> x1 >> x2 >> color;
					drawHoriz(y1,x1,x2,color);
					break;
				case 'K':
					cin >> x1 >> y1 >> x2 >> y2 >> color;
					drawRect(x1,y1,x2,y2,color);
					break;
				case 'F':
					break;
				case 'S':
					string name;
					cin >> name;
					save(name,m,n);
					break;
				case 'X':
					return 0;
					break;
				default:
			}
			
		} while (op != 'S');
	}
	return 0;
}

void initialize(int m, int n){
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
			image[i][j] = 'O';
}

void drawVert(int x, int y1, int y2, char color) {
	for (int i = y1; i < y2; ++i)
		image[x][i] = color;
}

void drawHoriz(int y, int x1, int x2, char color) {
	for (int i = x1; i < x2; ++i)
		image[i][y] = color;
}

void drawRect(int x1, int y1, int x2, int y2, char color){
	for (int i = x1; i < x2; ++i)
		for (int j = y1; j < y2; ++j)
			image[i][j] = color;
}

void save(string name, int m, int n) {
	cout << name << endl;
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
			cout << image[i][j]; 	
	cout << endl;
}

void colourRegion(int x, int y, char color){

}
