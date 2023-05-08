#include <iostream>
#include <cmath>
using namespace std;

char map[10000][10000];

void makeBlank(int x, int y, int size) {
	for (int i = x; i < x + size; i++) {
		for (int j = y; j < y + size; j++) {
			map[i][j] = ' ';
		}
	}
}

void makestar(int x, int y, int size) {
	if (size == 3) {
		map[x][y] = '*';
		map[x][y+1] = '*';
		map[x][y+2] = '*';
		map[x+1][y] = '*';
		makeBlank(x+1, y+1, 1);
		map[x+1][y+2] = '*';
		map[x+2][y] = '*';
		map[x+2][y+1] = '*';
		map[x+2][y+2] = '*';
	}

	else {
		makestar(x, y, size / 3);
		makestar(x, y + size / 3, size / 3);
		makestar(x, y + size / 3 + size / 3, size / 3);
		makestar(x+size/3, y, size / 3);
		makeBlank(x+size/3, y + size / 3, size / 3);
		makestar(x+size/3, y + size / 3 + size / 3, size / 3);
		makestar(x + size / 3 + size / 3, y, size / 3);
		makestar(x + size / 3 + size / 3, y + size / 3, size / 3);
		makestar(x + size / 3 + size / 3, y + size / 3 + size / 3, size / 3);
	}
}

int main() {
	int n;
	cin >> n;

	makestar(0, 0, n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << map[i][j];
		}
		cout << endl;
	}
}
