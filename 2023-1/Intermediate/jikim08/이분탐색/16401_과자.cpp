#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int nep, snack;

	cin >> nep >> snack;

	vector<int> snackLen(snack);
	for (int i = 0; i < snack; i++) {
		cin >> snackLen[i];
	}

	int left = 1;
	int right = *max_element(snackLen.begin(), snackLen.end());
	int mid = 0;
	int answer = 0;
	while (left <= right) {
		mid = (left + right) / 2;
		int count = 0;
		for (int i : snackLen) {		//mid값을 길이로 나누면 몇명에게 줄수 있는지 확인
			count += i / mid;
		}

		if (count >= nep) {		//조카 수보다 많이 줄 수 있으면
			left = mid + 1;		//더 길어도 되므로 left수정
			answer = mid;		//정답일 수 있는 값이므로 저장
		}
		else {		//조카 수보다 적게 줄 수 있으면
			right = mid - 1;	//더 짧아야 하므로 right수정
		}
	}

	cout << answer;

}
