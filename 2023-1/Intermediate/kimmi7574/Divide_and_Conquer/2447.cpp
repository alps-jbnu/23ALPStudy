#include <bits/stdc++.h>
using namespace std;

int n;

void solve(int i, int j, int n) {
	if ((i / n) % 3 == 1 && (j / n) % 3 == 1) {
		cout << " ";
	}
	else {
		if (n / 3 == 0)
			cout << "*";
		else
			solve(i, j, n / 3);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			solve(i, j, n);
		}
		cout << "\n";
	}

	return 0;
}