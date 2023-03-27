#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int d[15];

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t, n;
	cin >> t;

	d[1] = 1;
	d[2] = 2;
	d[3] = 4;
	for (int i = 4; i < 12; i++) d[i] = d[i - 1] + d[i - 2] + d[i - 3];
	
	for (int i = 0; i < t; i++) {
		cin >> n;
 		cout << d[n] << '\n';
	}

	return 0;
}
