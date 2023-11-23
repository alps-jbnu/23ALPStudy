#include<iostream>
#include<string>
using namespace std;

int arr[2005];
int d[2005][2005];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		d[i][i] = 1;
		if (arr[i - 1] == arr[i]) {
			d[i - 1][i] = 1;
		}
	}
	for (int i = 2; i < n; i++) {
		for (int j = 1; j <= n - i; j++) {
			if (arr[j] == arr[i + j] && d[j + 1][i + j - 1] == 1) {
				d[j][i + j] = 1;
			}
		}
	}
	int m;
	cin >> m;
	while (m--) {
		int i, j;
		cin >> i >> j;
		cout << d[i][j] << '\n';
	}
}
