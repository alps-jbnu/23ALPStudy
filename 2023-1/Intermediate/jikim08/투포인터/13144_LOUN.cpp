#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
	int N;
	cin >> N;

	vector<int> arr(N);
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	vector<bool> check(100001, 0);

	int left = 0, right = 0;
	check[arr[left]] = 1;
	long long cnt = 0;
	while (left < N) {
		while (right < N-1 && !check[arr[right+1]]) {
			right++;
			check[arr[right]] = 1;
		}
		cnt += right - left + 1;
		check[arr[left]] = 0;
		left++;
	}

	cout << cnt;
}
