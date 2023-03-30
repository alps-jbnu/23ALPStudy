#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

pair<int, int> arr[1000005];	// 최솟값, 이전 숫자

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	arr[1] = { 0,0 };
	arr[2] = { 1,1 };
	arr[3] = { 1,1 };
	for (int i = 4; i <= n; i++) {
		arr[i] = { arr[i - 1].first + 1,i - 1 };
		if (i % 2 == 0) arr[i] = min(arr[i], { arr[i / 2].first + 1,i / 2 });
		if (i % 3 == 0) arr[i] = min(arr[i], { arr[i / 3].first + 1,i / 3 });
	}

	cout << arr[n].first << '\n';
	int i = n;
	while (n != 0) {
		cout << n << ' ';
		n = arr[n].second;
	}


	return 0;
}
