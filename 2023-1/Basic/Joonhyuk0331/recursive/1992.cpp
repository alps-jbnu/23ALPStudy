#include <iostream>
#include <string.h>
using namespace std;
int arr[65][65];

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
		if (arr[x][y] == '1') {
			cout << 1;
		}
		else if (arr[x][y] == '0') {
			cout << 0;
		}
		return;
	}
	else{
		cout << '(';
	}

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			fun(size / 2, x + i * size / 2, y + j * size / 2);
		}
	}
	cout << ')';
}

int main() {
	int n = 0;
	cin >> n;

	
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < n; j++) {
			arr[i][j] = s[j];
		}
	}

	fun(n, 0, 0);
}
