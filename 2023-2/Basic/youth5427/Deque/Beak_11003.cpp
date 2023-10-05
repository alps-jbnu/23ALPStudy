/*
	Day: 2023.09.27
	참고 :
*/

#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);	// 지연시간 줄이기
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0, L=0;
	cin >> N >> L;

	deque<pair<int, int>> s;	// index, 값

	for (int i = 1; i < N + 1; i++) {
		int temp;
		cin >> temp;


		s.push_back({ i, temp });
		int min = s.front().second;

		// 범위 벗어나면 삭제
		if (s.front().first <= i - L) {
			s.pop_front();
		}

		if (i > 2) {
			min = 5000000;
			for (int j = 0; j < 3; j++) {
				if (s[j].second < min)
					min = s[j].second;
			}
		}


		// 맨 앞의 수 출력
		cout << min << " ";
	}

}
