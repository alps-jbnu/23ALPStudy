#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N, M;
	cin >> N;

	vector<long long> Nums(N);		//숫자 카드들
	
	for (int i = 0; i < N; i++) {
		cin >> Nums[i];
	}

	cin >> M;
	vector<long long> QNums(M);		//있는지 물어볼 숫자 카드들

	for (int i = 0; i < M; i++) {
		cin >> QNums[i];
	}

	sort(Nums.begin(), Nums.end());

	for (int i = 0; i < M; i++) {
		if (binary_search(Nums.begin(), Nums.end(), QNums[i])) {
			cout << 1 << ' ';
		}
		else {
			cout << 0 << ' ';
		}
	}

}
