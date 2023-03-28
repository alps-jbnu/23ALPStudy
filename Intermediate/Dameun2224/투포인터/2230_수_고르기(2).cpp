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
		if (min == m) break;
		while (1) {
			if (arr[en] - arr[st] >= m) {
				min = (min < arr[en] - arr[st]) ? min : arr[en] - arr[st];
				break;
			}
			else en++;
		}
	}

	cout << min << endl;

	return 0;
}
