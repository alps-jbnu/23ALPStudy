#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> time(N);

	for (int i = 0; i < N; i++) {
		cin >> time[i];
	}

	sort(time.begin(), time.end());

	int ans = 0;
	int T = 0;
	for (int i = 0; i < N; i++) {
		T += time[i];
		ans += T;
	}

	cout << ans;

}
