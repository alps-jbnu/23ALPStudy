#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int n;
int a[1005];

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);

	int sum = 0;
	for (int i = 0; i < n; i++) 
		for (int j = 0; j <= i; j++) 
			sum += a[j];

	cout << sum << '\n';

	return 0;
}
