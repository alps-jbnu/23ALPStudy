#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int a[500005], b[500005];
vector<int> v;

int bs(int t) {
	int st = 0;
	int en = m - 1;

	while (st <= en) {
		int mid = (st + en) / 2;
		if (b[mid] < t) st = mid + 1;
		else if (b[mid] > t) en = mid - 1;
		else return 0;
	}

	v.push_back(t);
	return 1;
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < m; i++) cin >> b[i];
	sort(a, a + n);
	sort(b, b + m);
	
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += bs(a[i]);
	}

	cout << sum << '\n';
	for (int e : v) cout << e << ' ';

	return 0;
}
