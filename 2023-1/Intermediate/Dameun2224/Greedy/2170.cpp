#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

/*
* pair로 vector에 받아서 오름차순 정렬
*/

int n, a, b;
vector<pair< int, int >> v;
int mn, mx, sum;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		v.push_back({ a,b });
	}
	sort(v.begin(), v.end());

	mn = v[0].first;
	mx = v[0].second;

	for (int i = 1; i < n; i++) {
		if (v[i].first > mx) {
			sum += mx - mn;
			mn = v[i].first;
			mx = v[i].second;
		}
		else mx = max(mx, v[i].second);
	}

	sum += mx - mn;
	cout << sum << '\n';

	return 0;
}
