#include <iostream>
using namespace std;
int arr[129][129];
int white = 0;
int blue = 0;

bool check(int size, int x, int y) {
	int cnt = arr[x][y];
	for (int i = x; i < x + size; i++) {
		for (int j = y; j < y + size; j++) {
			if (cnt != arr[i][j])
				return false;
		}
	}
	return true;
}

void fun(int size, int x, int y) {
	if (check(size, x, y) == true) {
		if (arr[x][y] == 1) {
			blue++;
		}
		else if (arr[x][y] == 0) {
			white++;
		}
		return;
	}

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			fun(size / 2, x + i * size / 2, y + j * size / 2);
		}
	}
}

int main() {
	int n = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];

	fun(n, 0, 0);

	cout << white << '\n' << blue ;
}
