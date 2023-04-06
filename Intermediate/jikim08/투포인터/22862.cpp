#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	
	int len, K;
	cin >> len >> K;
	vector<int> set(len);
	for (int i = 0; i < len; i++) {
		cin >> set[i];
	}

	int left = 0, right = 0;					//투 포인터
	int length = 0;					//수열의 길이
	int odd = 0;					//현재 범위의 홀수 개수
	if (set[left] % 2)	odd++;		//초기값 설정

	if (len == 1) {					//질문 게시판에 올라온 내용. 1 1 2가 입력되면 1이 출력되어야함.
		if (set[0] % 2)	cout << 0;
		else	cout << 1;
		return 0;
	}

	while (left < len) {
		while (right < len && odd <= K) {
			right++;
			if (right >= len)	break;
			if (set[right] % 2)		odd++;
			length = length < right - left - odd + 1 ? right - left - odd + 1 : length;
		}
		if (set[left] % 2)	odd--;
		left++;
	}

	cout << length;

}
