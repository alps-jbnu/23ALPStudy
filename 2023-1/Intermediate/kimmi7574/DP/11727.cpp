#include <bits/stdc++.h>
using namespace std;

int n;
int d[1005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	//�ʱⰪ
	d[0] = 0;
	d[1] = 1;
	d[2] = 3;

	for (int i = 3; i <= n; i++) {
		d[i] = (d[i - 1] + 2 * d[i - 2]) % 10007;
	}

	cout << d[n];
}