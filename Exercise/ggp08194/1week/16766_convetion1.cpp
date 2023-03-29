#include <bits/stdc++.h>

using namespace std;

int n, m, c;
int arr[100005];

bool func(int x) {
	int st = 0;
	int bus = 0;
	for (int i = 0; i < n; i++) {
		if (i - st < c) {
			if (arr[i] - arr[st] > x) {
				st = i;
				i--;
				bus++;
			}
		}
		else {
			st = i;
			i--;
			bus++;
		}
		if (i!=n-1 && bus == m) {
			return 0;
		}
	}
	return 1;
}


int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> m >> c;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + n);

	int st = 0;
	int en;
	if (n < 100000)	en = arr[n - 1] - arr[0];

	while (st <= en) {
		int mid = (st + en) / 2;
		if (func(mid)) {
			en = mid-1;
		}
		else
			st = mid+1;
	}
	cout << st;
	
	
}