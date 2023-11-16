#include <iostream>
#include <cmath>
using namespace std;

int func(int n, int r, int c)
{
	if (n == 0)
		return 0;
	int n_half = pow(2, n-1);
	int square = n_half * n_half;
	if (r < n_half && c < n_half)
		return func(n - 1, r, c);
	else if (r < n_half && c >= n_half)
		return 1 * square + func(n - 1, r, c - n_half);
	else if (r >= n_half && c < n_half)
		return 2 * square + func(n - 1, r - n_half, c);
	else if(r >= n_half && c >= n_half)
		return 3 * square + func(n - 1, r - n_half, c - n_half);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	int n, r, c;
	cin >> n >> r >> c;
	cout << func(n, r, c);
	return 0;
}
