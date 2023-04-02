#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;

	vector<int> DP(N+1);

	DP[1] = 1;
	DP[2] = 3;
	for (int i = 3; i <= N; i++) {
		DP[i] = DP[i - 1] + DP[i - 2] * 2;		//2*1타일이 세로로 하나 고정인 경우 + 1*2타일 두개가 같이 고정인 경우 + 2*2타일 하나가 고정인 경우
		if (DP[i] > 10007)	DP[i] %= 10007;
	}

	cout << DP[N];

}
