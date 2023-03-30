#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> num(N);
	
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}

	vector<int> DP(N);

	DP[0] = num[0];

	for (int i = 1; i < N; i++) {
		DP[i] = max(DP[i - 1] + num[i], num[i]);
	}

	cout << *max_element(DP.begin(), DP.end());

}
