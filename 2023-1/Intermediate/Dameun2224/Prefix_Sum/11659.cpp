#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int num[100005];
int sum[100005];

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++) cin >> num[i];
	for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + num[i - 1];

	while (m--) {
		int a, b;
		cin >> a >> b;
		cout << sum[b] - sum[a - 1] << '\n';
	}

	return 0;
}
