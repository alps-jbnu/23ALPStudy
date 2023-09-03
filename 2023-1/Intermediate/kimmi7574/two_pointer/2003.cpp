#include <bits/stdc++.h>
using namespace std;

int n, m;
int cnt = 0;
int A[10002];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}

	int start = 0;
	int end = 0;
	int sum = A[0];

	while (start <= end && end < n) {
		if (sum < m) {
			sum += A[++end];
		}
		else if (sum == m) {
			cnt++;
			sum += A[++end];
		}
		else if (sum > m) {
			sum -= A[start++];

			if (start > end) {
				end = start;
				sum = A[start];
			}
		}
	}

	cout << cnt;
	return 0;
}