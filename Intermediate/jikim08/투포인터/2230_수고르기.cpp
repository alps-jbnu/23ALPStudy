#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
	int len, Min;
	cin >> len >> Min;

	vector<int> arr(len);
	for (int i = 0; i < len; i++) {
		cin >> arr[i];
	}

	int left = 0, right = 0;
	sort(arr.begin(), arr.end());
	int ans = INT_MAX;
	while (left <= right) {
		int sub = arr[right] - arr[left];

		if (sub > Min) {
			left++;
			if(ans > sub)
				ans = sub;
		}
		else if (sub < Min) {
			right++;
			if (right >= len) {
				break;
			}
		}
		else if (sub == Min) {
			ans = Min;
			break;
		}
	}

	cout << ans;
}
