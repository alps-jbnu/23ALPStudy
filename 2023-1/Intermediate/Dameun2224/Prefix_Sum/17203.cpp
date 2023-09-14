#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int n, m;
int num[100005];
int sum[100005];

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		cin >> num[i];

	for (int i = 2; i <= n; i++)
		sum[i] = sum[i - 1] + abs(num[i] - num[i - 1]);

	while (m--) {
		int a, b;
		cin >> a >> b;
		cout << sum[b] - sum[a] << '\n';
	}

	return 0;
}
