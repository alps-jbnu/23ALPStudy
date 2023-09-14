#include <bits/stdc++.h>
using namespace std;

int arr[2200][2200];
int result[3]; //[0]:-1의 개수, [1]:0의 개수, [2]:1의 개수
int n;

bool isSame(int x, int y, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[x][y] != arr[x + i][y + j])
				return false;
		}
	}
	return true;
}

void paper(int x, int y, int n) {
	if (isSame(x, y, n)) {
		int paperNum = arr[x][y];
		result[paperNum + 1]++;
		return;
	}

	int div = n / 3;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			paper(x + div * i, y + div * j, div);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	paper(0, 0, n);

	for (int i = 0; i < 3; i++) {
		cout << result[i] << "\n";
	}

	return 0;
}