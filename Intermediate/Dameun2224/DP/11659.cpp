#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int d[100005];
int a[100005]; // d[i]까지 더한 합을 저장하는 배열

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> d[i];
	
	a[1] = d[1];
	for (int i = 2; i <= n; i++) a[i] = a[i - 1] + d[i];

	int x, y;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		cout << a[y] - a[x - 1] << '\n';
	}


	return 0;
}
