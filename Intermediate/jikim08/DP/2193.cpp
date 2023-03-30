#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;

	vector<long long> DP(N+1);          //long long....빡치네

	DP[1] = 1;
	DP[2] = 1;

	for (int i = 3; i <= N; i++) {
		DP[i] = DP[i - 1] + DP[i - 2];    //마지막 수가 0인경우, 마지막 수가 1인 경우(01이 고정이므로 i-2)
	}

	cout << DP[N];

}
