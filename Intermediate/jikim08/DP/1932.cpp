#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<vector<int>> tri(N);
	int val;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> val;
			tri[i].push_back(val);
		}
	}

	vector<vector<int>> DP(N, vector<int>(N));
	DP[0][0] = tri[0][0];		//초기값 설정

	//각 자리에 들어갈 수 있는 합의 최댓값 저장
	for (int i = 1; i < N; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0) {			//j가 0이면 j-1에 접근이 불가하므로 따로 설정
				DP[i][j] = DP[i - 1][j] + tri[i][j];
				continue;
			}
			DP[i][j] = max(DP[i - 1][j - 1] + tri[i][j], DP[i - 1][j] + tri[i][j]);		//두 값중에 더 큰값이 들어감
		}
	}

	//for (int i = 0; i < N; i++) {
	//	for (int j = 0; j <= i; j++) {
	//		cout << DP[i][j] << ' ';
	//	}
	//	cout << endl;
	//}

	cout << *max_element(DP[N - 1].begin(), DP[N - 1].end());

}
