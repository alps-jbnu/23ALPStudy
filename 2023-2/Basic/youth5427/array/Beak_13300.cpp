/*
	Day: 2023.09.19
	참고 : 머리좀 써라
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);	// 지연시간 줄이기
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0; int K = 0;
	cin >> N >> K;
	int S, Y;

	vector<vector<int>> s(2, vector<int>(7)); // [성별][학년]

	int count = 0;	// 방 갯수
	for (int i = 0; i < N; i++) {
		cin >> S >> Y;
		s[S][Y]++;

		if (s[S][Y] == K) {	// 한 방이 할당되면 초기화
			s[S][Y] = 0;
			count++;
		}
	}
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j <= 6; ++j) {
			if (s[i][j] > 0) count++;
		}
	}

	cout << count;
}
