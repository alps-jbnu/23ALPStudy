#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
using namespace std;
using ll = long long;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n, goal, cnt = 0;
	cin >> n;
	vector<ll>v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	cin >> goal;

	sort(v.begin(), v.end());

	ll start = 0, end = n - 1;
	while (start < end) {
		ll val = v[start] + v[end];
		if (val == goal) {
			cnt++;
			start++;
			end--;
		}
		else if (val < goal)
			start++;
		else
			end--;

	}
	cout << cnt;
	return 0;
}
