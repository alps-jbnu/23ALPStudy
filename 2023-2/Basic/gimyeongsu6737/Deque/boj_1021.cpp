#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

void first(deque<int>& dq) {
	dq.pop_front();
}

void second(deque<int>& dq) {
	dq.push_back(dq.front());
	dq.pop_front();
}

void third(deque<int>& dq) {
	dq.push_front(dq.back());
	dq.pop_back();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int cnt = 0;
	int n;
	int m;
	deque<int> dq;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		dq.push_back(i);
	}

	while (m > 0) {
		
		m--;
		int k;
		cin >> k;
		int idx = find(dq.begin(), dq.end(), k) - dq.begin();
		while (dq.front() != k) {
			if (idx <= dq.size() / 2) {
				second(dq);
				cnt++;
			}
			else {
				third(dq);
				cnt++;
			}
		}
		first(dq);

		
	}
	cout << cnt;
}