#include<bits/stdc++.h>
using namespace std;

int n, m, c;
int arr[100005];

bool Find(int mid) {
	int cnt = 1;
	for (int i = 1, start = 0; i < n; i++) {

		if (i - start < c && arr[i] <= (arr[start] + mid))	continue;

		start = i;
		cnt++;
	}
	if (cnt <= m) return true;
	else return false;
}



int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> c;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	int st = 0;
	int en = 1000000000;
	while (st <= en) {
		int mid = (st + en) / 2;
		if (Find(mid)) {
			en = mid - 1;
		}
		else {
			st = mid + 1;
		}
	}
	cout << st;
 }