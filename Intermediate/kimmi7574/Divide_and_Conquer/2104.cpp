#include <bits/stdc++.h>
using namespace std;

long long A[100001];
int n;
long long result = 0;

long long func(int s, int e) {
	if (s == e)
		return A[s] * A[s];
	int mid = (s + e) / 2;
	result = max(func(s, mid), func(mid + 1, e));
	long long v = A[mid], min = A[mid], l = mid, r = mid;

	while (l > s || r < e) {
		long long p = l > s ? A[l - 1] : -1;
		long long q = r < e ? A[r + 1] : -1;

		if (p >= q) {
			v = v + p;
			if (min > p && p != -1)
				min = p;
			l--;
		}
		else {
			v = v + q;
			if (min > q && q != -1)
				min = q;
			r++;
		}
		result = max(result, v*min);
	}
	return result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> A[i];
	}

	cout << func(1, n);

	return 0;
}