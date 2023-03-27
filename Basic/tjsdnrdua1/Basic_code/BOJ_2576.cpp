#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int arr[7] = {};
	int sum = 0;
	int min = 0;
	for (int i = 0; i < 7; i++) {
		cin >> arr[i];
		if (arr[i] % 2 != 0)
			sum += arr[i];
	}
	for (int i = 0; i < 7; i++) {
		if (arr[i] % 2 != 0) {
			min = arr[i];
			break;
		}
	}
	for (int i = 1; i < 7; i++) {
		if (arr[i] < min && arr[i] % 2 != 0)
			min = arr[i];
	}
	if (sum == 0) cout << -1;
	else
		cout << sum << '\n' << min;
}
