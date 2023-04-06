#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
	int N, S;

	cin >> N >> S;
	vector<int> arr(N);
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	int len = INT_MAX;
	int left = 0, right = 0;
	int sum = arr[left];

	while (right < N) {
		if (sum >= S) {			//sum값이 S이상인 값인 경우
			if (len > right - left)	//부분합의 길이만 비교
				len = right - left;	//더 짧으면 갱신

			sum -= arr[left];	//left포인터를 옮기는 과정
			left++;
		}

		else {		//sum값이 S미만인 경우
			right++;	//right값을 키워줌
			if (right < N)
				sum += arr[right];
		}
	}

	if (len == INT_MAX)	len = -1;

	std::cout << len + 1;

}
