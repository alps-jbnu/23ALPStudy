#include <iostream>
#include <deque>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	int l;
	deque<pair<int, int>> dq;
	cin >> n >> l;
	for (int i = 1; i <= n; i++) {
		int num;
		cin >> num;

		while (!dq.empty() && dq.back().second >= num) {
			dq.pop_back();
		}

		if (!dq.empty() && dq.front().first <= i - l) {
			dq.pop_front();
		}

		dq.push_back({ i, num });

		cout << dq.front().second << ' ';

	}
}