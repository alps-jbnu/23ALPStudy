#include <bits/stdc++.h>
using namespace std;

string arr[64];
int n;

bool isSame(int x, int y, int n) {
	for (int i = x; i < x + n; i++) {
		for (int j = y; j < y + n; j++) {
			if (arr[x][y] != arr[i][j])
				return false;
		}
	}
	return true;
}

void solve(int x, int y, int n) {
	if (isSame(x, y, n)) {
		cout << arr[x][y];
		return;
	}

	cout << "(";
	int div = n / 2;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			solve(x + div * i, y + div * j, div);
		}
	}
	cout << ")";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	solve(0, 0, n);

	return 0;
}