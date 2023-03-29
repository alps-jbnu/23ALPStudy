#include <bits/stdc++.h>
using namespace std;

int A[10002];
int N;
long long cnt = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	sort(A, A + N);

	for (int i = 0; i < N - 1; i++) {
		for (int j = i + 1; j < N - 1; j++) {
			int target = (A[i] + A[j]) * -1;
			int l = lower_bound(A + j + 1, A + N, target) - A;
			int u = upper_bound(A + j + 1, A + N, target) - A;
			cnt += u - l;
		}
	}
	cout << cnt << '\n';
}