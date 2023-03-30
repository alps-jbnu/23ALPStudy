#include<bits/stdc++.h>
using namespace std;

int n, m, l;
pair<int, int> animal[100005];
int gun[100005];
int ans = 0;
bool vis[100005];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> l;
	for (int i = 0; i < n; i++) {
		cin >> gun[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> animal[i].first >> animal[i].second;
	}
	sort(gun, gun + n);

	for (int i = 0; i < m; i++) {
		int L = 0, R = n - 1;
		while (L <= R) {
			int mid = (L + R) / 2;
			int sm = abs(animal[i].first - gun[mid]) + animal[i].second;
			if (sm <= l) {
				++ans;
				break;
			}
			else {
				if (animal[i].first >= gun[mid]) {
					L = mid + 1;
				}
				else {
					R = mid - 1;
				}
			}
		}
	}
	cout << ans;
 }