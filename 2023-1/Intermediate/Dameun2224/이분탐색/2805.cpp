#include<iostream>
#include <algorithm>
#include <cmath>
#include <limits.h>
using namespace std;

long long int n, m, mt;
long long int tree[1000005];

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> tree[i];
		mt = max(mt, tree[i]);
	}
		
	long long int st = 0;
	long long int en = mt;
	long long int ans = LLONG_MAX;
	long long int result = 0;
	while (st <= en) {
		long long int mid = (st + en) / 2;
		long long int sum = 0;
		for (int i = 0; i < n; i++) {
			if (tree[i] > mid) sum += tree[i] - mid;
		}
		if (sum < m) en = mid - 1;
		else if (sum > m) {
			ans = min(ans, sum);
			if (ans == sum) result = mid;
			st = mid + 1;
		}
		else {
			result = mid;
			break;
		}
	}

	std::cout << result << '\n';

	return 0;
}
