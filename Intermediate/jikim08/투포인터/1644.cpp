#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

vector<int> prime(int N) {
	vector<int> ans;
	vector<bool> seive(N+1, true);

	for (int i = 2; i * i < N+1; i++) {
		if (!seive[i]) continue;
		for (int j = i * i; j < N+1; j += i)
			seive[j] = false;
	}
	for (int i = 2; i <= N; i++) if (seive[i]) ans.push_back(i);
	

	return ans;

}

int main() {
	int N;
	cin >> N;

	vector<int> Prime = prime(N);

	int len = Prime.size();
	int left = 0, right = 0;
	int sum = 2;
	int cnt = 0;

	while (left < len) {
		while (right < len && sum < N) {
			right++;
			if (right >= len)	break;
			sum += Prime[right];
		}
		if (sum == N)	cnt++;	//sum값이 N과 같으면 cnt증가

		sum -= Prime[left];
		left++;
	}

	cout << cnt;
	return 0;
}
