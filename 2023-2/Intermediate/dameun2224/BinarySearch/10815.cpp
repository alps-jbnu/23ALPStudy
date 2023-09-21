#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, k;
int a[500005];

int bs(int t) {
	int st = 0;
	int en = n - 1;

	while (st <= en) {
		int mid = (st + en) / 2;
		if (a[mid] < t)st = mid + 1;
		else if (a[mid] > t) en = mid - 1;
		else return 1;
	}

	return 0;
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);

	cin >> m;
	while (m--) {
		cin >> k;
		cout << bs(k) << ' ';
	}

	return 0;
}
