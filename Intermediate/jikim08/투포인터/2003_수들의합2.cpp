#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;

	vector<int> arr(N);
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	int left = 0, right = 0;
	int sum = arr[0];
	int cnt = 0;
	while (left < N) {
		while (right < N && sum < M) {
			right++;
			if (right >= N)		break;
			sum += arr[right];
		}

		if (sum == M) {
			cnt++;
		}
		sum -= arr[left];
		left++;
	}

	cout << cnt;
}
