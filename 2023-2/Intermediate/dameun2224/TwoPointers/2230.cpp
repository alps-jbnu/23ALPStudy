#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;

int arr[100005];

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n);

	int st = 0, en = 0, min = INT_MAX;
	for (st = 0; st < n; st++) {
		while(en < n && arr[en] - arr[st] < m) en++;
		if (en == n) break;
		min = (min < arr[en] - arr[st]) ? min : arr[en] - arr[st];
		if (min == m) break;
	}

	cout << min << endl;

	return 0;
}
