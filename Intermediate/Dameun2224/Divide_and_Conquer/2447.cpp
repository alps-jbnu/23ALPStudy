#include <iostream>
using namespace std;

int n;
char map[6600][6600];

void func(int x, int y, int m, int c) {
	if (c == 5) {
		for (int i = x; i < x + m; i++)
			for (int j = y; j < y + m; j++)
				map[i][j] = ' ';
		return;
	}
	if (m == 0) {
		map[x][y] = '*';
		return;
	}
	int mm = m / 3;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			func(x + i * mm, y + j * mm, mm, i * 3 + j + 1);
		}
	}

}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	func(0, 0, n, 1);
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << map[i][j];
		cout << '\n';
	}
			

	return 0;
}
