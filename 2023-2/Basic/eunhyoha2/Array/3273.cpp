#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int n, x;
	cin >> n;
	int num[100000];
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	cin >> x;
	sort(num, num + n);

	int left = 0;
	int right = n - 1;
	int count = 0;
	while (left < right) {
		if (num[left] + num[right] == x) {
			count++;
			left++;
			right--;
		}
		else if (num[left] + num[right] > x) {
			right--;
		}
		else {
			left++;
		}
	}

	cout << count;

	return 0;
}
