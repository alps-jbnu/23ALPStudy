#include <iostream>
using namespace std;

int n, r, c;

/*
* 0  1  4  5 
* 2  3  6  7
* 8  9  12 13
* 10 11 14 15
*/

// m == 1, 2, 3, ... , 15
int func(int x, int y, int m) {
	if (m == 0) return 0;
	if (x == c && y == r) return 0;
	int mm = 1 << (m - 1);
	int num = mm * mm;	// == 2^m * 2^m / 4;
	if (r < x + mm) {
		if (c < y + mm) return func(x, y, m - 1);
		else return num + func(x, y + mm, m - 1);
	}
	else {
		if (c < y + mm) return 2 * num + func(x + mm, y, m - 1);
		else return 3 * num + func(x + mm, y + mm, m - 1);
	}
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> r >> c;

	cout << func(0, 0, n) << '\n';

	return 0;
}
