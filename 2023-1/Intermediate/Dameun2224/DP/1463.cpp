#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int d[1000005];

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int x;
	cin >> x;

	for (int i = 2; i <= x; i++) {
		d[i] = d[i - 1] + 1;
		if (i % 2 == 0) d[i] = min(d[i], d[i / 2] + 1);
		if (i % 3 == 0) d[i] = min(d[i], d[i / 3] + 1);
	}

	cout << d[x] << '\n';

	return 0;
}
