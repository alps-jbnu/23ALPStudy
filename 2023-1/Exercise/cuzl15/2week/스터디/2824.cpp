#include<bits/stdc++.h>
using namespace std;

vector<int> prime;
bool vis[40000];
map<int, int> a, b;

void make(int num, char ch) {
	if (ch == 'a') {
		for (auto o : prime) {
			if (num % o == 0) {
				a[o]++;
				make(num / o, 'a');
				return;
			}
		}
		if (num != 1)	a[num]++;
	}
	else {
		for (auto o : prime) {
			if (num % o == 0) {
				b[o]++;
				make(num / o, 'b');
				return;
			}
		}
		if (num != 1)	b[num]++;
	}
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	long long ans = 1;
	bool big = false;
	for (int i = 2; i < 40000; i++) { //에라토스테네스의 체
		if (vis[i]) continue;
		prime.push_back(i);
		for (int j = 2 * i; j < 40000; j += i) {
			vis[j] = true;
		}
	}
	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		make(num, 'a');
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		int num;
		cin >> num;
		make(num, 'b');
	}
	for (auto o : a) {
		if (!b[o.first]) continue;
		int cnt = min(o.second, b[o.first]);

		while (cnt--) {

			ans *= o.first;
			if (ans >= 1000000000) {
				ans %= 1000000000;
				big = 1;
			}
		}
	}
	if (big) {
		int id = 0;
		long long tmp = ans;
		for (int i = 0; i < 9; i++) {
			if (tmp != 0) {
				id++;
				tmp /= 10;
			}
			else
			{
				break;
			}
		}
		for (int i = 0; i < 9 - id; i++) {
			cout << '0';
		}
		if (id != 0)
			cout << ans;
	}
	else {
		cout << ans;
	}
 }