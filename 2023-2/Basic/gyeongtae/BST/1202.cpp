#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int a, b, c, d;
	cin >> a >> b;
	vector <pair<int, int>> v(a);

	for (int i = 0;i < a;i++) {
		cin >> v[i].first >> v[i].second;
	}
	vector <int> v2(b);
	for (int i = 0;i < b;i++) {
		cin >> v2[i];
	}
	sort(v2.begin(), v2.end());
	sort(v.begin(), v.end());
	long long sum = 0;
	priority_queue<int> pq;
	int j = 0;
	for (int i = 0;i < b;++i) {
		while (j < a && v[j].first <= v2[i]) {
			pq.push(v[j++].second);
		}
		if (!pq.empty()) {
			sum += pq.top();
			pq.pop();
		}
	}

	cout << sum;
}
