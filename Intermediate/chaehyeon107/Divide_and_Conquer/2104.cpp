#include <bits/stdc++.h>
using namespace std;

int num[100005];

long long solve(int l, int r) {
	if (l == r) {
		return (long long)num[l] * num[l];
	}
	else if (l < r) {
		int mid = (l + r) / 2;
		long long score = max(solve(l, mid), solve(mid + 1, r));
		int ml = mid;
		int mr = mid + 1;
		int mn = min(num[ml], num[mr]);
		long long sum = num[ml] + num[mr];
		long long nscore = (long long)sum * mn;
		while (ml > l || mr < r) {
			if (ml > l && (mr == r || num[ml - 1] > num[mr + 1])) {
				mn = min(mn, num[--ml]);
				sum += num[ml];
			}
			else { 
				mn = min(mn, num[++mr]);
				sum += num[mr];
			}
			nscore = max(nscore, (long long)sum * mn);
		}
		score = max(score, nscore);
		return score;
	}
	else {
		return 0;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	cout << solve(0, n - 1);
}
