#include <bits/stdc++.h>
using namespace std;

long long a, b, c, k;

long long power(long long a, long long b) {
	if (b == 0)
		return 1;
	else if (b == 1)
		return a % c;

	k = power(a, b / 2) % c;
	if (b % 2 == 0)
		return k * k % c;
	return k * k % c * a % c;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> a >> b >> c;
	cout << power(a, b);
}