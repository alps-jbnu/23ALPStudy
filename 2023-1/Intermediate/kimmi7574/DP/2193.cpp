#include <bits/stdc++.h>
using namespace std;

int n;
long long d[95];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	//�ʱⰪ
	d[1] = 1;
	d[2] = 1;

	for (int i = 3; i <= n; i++) {
		d[i] = d[i - 1] + d[i - 2];
	}

	cout << d[n];
}