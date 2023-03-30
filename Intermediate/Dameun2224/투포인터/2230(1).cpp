#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;

int arr[100005];

int main(void) {
	int x, n, m, min;
	min = INT_MAX;

	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n);

	for (int i = 0; i < n; i++) {
		x = arr[i];
		int j = lower_bound(arr, arr + n, x + m) - arr;
		// 찾으려는 값을 찾지 못한 경우 n 이상의 인덱스 리턴
		if (j >= n) continue;
		min = (min < arr[j] - x) ? min : arr[j] - x;
	}

	cout << min << '\n';

	return 0;
}
