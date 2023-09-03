#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;


long long int n, m, x;
priority_queue<long long int, vector<long long int>, greater<long long int>> pq;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> x;
		pq.push(x);
	}

	while (m--) {
		long long int a = pq.top();
		pq.pop();
		long long int b = pq.top();
		pq.pop();
		pq.push(a + b);
		pq.push(a + b);
	}

	long long int sum = 0;
	while(!pq.empty()) {
		sum += pq.top();
		pq.pop();
	}
	cout << sum << '\n';

	return 0;
}
