#include<iostream>
#include<string>
using namespace std;

int coin[25];
int d[10005];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		fill(d, d + 10005, 0);
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> coin[i];
		}
		int m;
		cin >> m;

		d[0] = 1;
		for (int i = 0; i < n; i++) {
			for (int j = coin[i]; j <= m; j++) {
				d[j] += d[j - coin[i]];
			}
		}

		cout << d[m] << '\n';
	}
}
