#include<iostream>
#include <algorithm>
#include <math.h>
#include <limits.h>
#include <stack>
#include <queue>
using namespace std;

#define X first
#define Y second

int n, k, ans;
int a[1000005];

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];

	for (int i = n; i >= 1; i--) {
		int cnt = k / a[i];
		ans += cnt;
		k -= cnt * a[i];
	}

	cout << ans << '\n';

	return 0;
}
