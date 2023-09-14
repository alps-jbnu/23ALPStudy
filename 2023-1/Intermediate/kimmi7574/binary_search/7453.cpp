#include <bits/stdc++.h>
using namespace std;

int n;
long long cnt = 0;
int A[4002];
int B[4002];
int C[4002];
int D[4002];

int twoCD[16000002];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> A[i] >> B[i] >> C[i] >> D[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			twoCD[i*n + j] = C[i] + D[j];
		}
	}

	sort(twoCD, twoCD + n*n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int key = -1 * (A[i] + B[j]);
			int l = lower_bound(twoCD, twoCD + n * n, key) - twoCD;
			int u = upper_bound(twoCD, twoCD + n * n, key) - twoCD;
			cnt += u - l;
		}
	}

	cout << cnt;

	return 0;
}