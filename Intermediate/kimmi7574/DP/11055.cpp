#include <bits/stdc++.h>
using namespace std;

int n, max_sum;
int a[1005];
int d[1005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	
	for (int i = 1; i <= n; i++) {
		d[i] = a[i];
		for (int j = 1; j < i; j++) {
			if (a[i] > a[j])
				d[i] = max(d[j] + a[i], d[i]);
		}
		max_sum = max(max_sum, d[i]);
	}

	cout << max_sum;
}
