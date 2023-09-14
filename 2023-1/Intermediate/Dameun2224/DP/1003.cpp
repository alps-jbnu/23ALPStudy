#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

pair<int, int> arr[45];	// 0 출력 합, 1 출력 합

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t, n;
	cin >> t;

	arr[0] = { 1,0 };
	arr[1] = { 0,1 };

	for (int i = 2; i <= 40; i++) {
		arr[i].first = arr[i - 1].first + arr[i - 2].first;
		arr[i].second = arr[i - 1].second + arr[i - 2].second;
	}

	while (t--) {
		cin >> n;
		cout << arr[n].first << ' ' << arr[n].second << '\n';
	}

	return 0;
}
