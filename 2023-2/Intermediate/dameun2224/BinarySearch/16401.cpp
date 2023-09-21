#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
* 0 ~ 최대값 까지 이진탐색을 해서
* l[i]/mid 값을 모두 더한 cnt가
* m보다 크거나 같을 때까지 while문을 돌림
*/

using ll = long long;

int n, m;
int l[1000005];

bool solve(int x) {
	if (x == 0) return true;
	ll cnt = 0;
	for (int i = 0; i < n; i++) {
		cnt += l[i] / x;
	}
	return cnt >= m;
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> m >> n;
	for (int i = 0; i < n; i++) cin >> l[i];

	int st = 0;
	int en = *max_element(l, l + n);

	while (st < en) {
		int mid = (st + en + 1) / 2;
		if (solve(mid)) st = mid;
		else en = mid - 1;
	}

	cout << st << "\n";

	return 0;
}
