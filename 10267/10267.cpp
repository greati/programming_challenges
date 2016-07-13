#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

const char VISITED = '0';

char image[255][255];

int delta[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};

int m, n;
int x1, x2, y1, y2;
char op = 'I';
char color;
string name;

void initialize(int m, int n){
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			image[i][j] = 'O';
}

void drawVert(int x, int y1, int y2, char color) {
	if (y1 > y2)
		swap(y1,y2);
	for (int i = y1; i <= y2; ++i)
		image[i][x] = color;
}

void drawHoriz(int x1, int x2, int y, char color) {
	if (x1 > x2)
		swap(x1,x2);
	for (int i = x1; i <= x2; ++i)
		image[y][i] = color;
}

void drawRect(int x1, int y1, int x2, int y2, char color){
	for (int i = y1; i <= y2; ++i)
		for (int j = x1; j <= x2; ++j)
			image[i][j] = color;
}

void save(string name, int m, int n) {
	cout << name << endl;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			putchar(image[i][j]); 
		}	
		printf("\n");
	}
}

void colourRegion(int x, int y, char colorOriginal, char newColor){
	if (colorOriginal == newColor)
		return;
	if (image[y][x] == colorOriginal) {
		image[y][x] = newColor;
		for (int i = 0; i < 4; ++i) {
			int xx = x + delta[i][0];
			int yy = y + delta[i][1];
			colourRegion(xx, yy, colorOriginal, newColor);
		}
	}
}

int main(void) {
	
	while (true) {

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
					image[y1][x1] = color;
					break;
				case 'V':
					cin >> x1 >> y1 >> y2 >> color;
					drawVert(x1, y1, y2, color);
					break;
				case 'H':
					cin >> y1 >> x1 >> x2 >> color;
					drawHoriz(y1, x1, x2, color);
					break;
				case 'K':
					cin >> x1 >> y1 >> x2 >> y2 >> color;
					drawRect(x1, y1, x2, y2, color);
					break;
				case 'F':
					cin >> x1 >> y1 >> color;
					colourRegion(x1, y1, image[y1][x1], color);
					break;
				case 'S':
					cin >> name;
					save(name, m, n);
					break;
				case 'X':
					return 0;
				default:
					continue;
			}
			
		} while (op != 'S');
	}
	return 0;
}

