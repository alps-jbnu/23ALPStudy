#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	long long Tree, Taketree;
	cin >> Tree >> Taketree;

	vector<long long> Treelen(Tree);
	for (long long i = 0; i < Tree; i++) {
		cin >> Treelen[i];
	}

	long long left = 1;
	long long right = *max_element(Treelen.begin(), Treelen.end());
	long long answer = 0;
	while (left <= right) {
		long long mid = (left + right) / 2;
		long long len = 0;

		for (long long i : Treelen) {		//len은 나무를 mid만큼 자르면 얻을 수 있는 길이
			if (i - mid > 0) {
				len += i - mid;
			}
		}

		if (len >= Taketree) {	//len이 길면 더 높여도 됨
			left = mid + 1;		//left값 수정
			answer = mid;		//mid가 정답일 수 있으므로 저장
		}
		else {					//len이 짧으면 낮춰야함
			right = mid - 1;
		}

	}

	cout << answer;
}
