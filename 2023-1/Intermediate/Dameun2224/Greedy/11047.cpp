#include <iostream>
#include <algorithm>
#include <cmath>
#include <stack>
using namespace std;

int n, m, k, cnt;
stack<int> s;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k; 
	while (n--) {
		cin >> m;
		s.push(m);
	}

	while (!s.empty()) {
		if (k == 0) break;
		int t = s.top();
		s.pop();
		if (k >= t) {
			cnt += k / t;
			k %= t;
		}
	}

	cout << cnt << '\n';

	return 0;
}
