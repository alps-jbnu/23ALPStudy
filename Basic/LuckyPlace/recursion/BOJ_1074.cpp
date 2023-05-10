#include <iostream>
using namespace std;

int visit(int n, int r, int c)
{
	if (n == 0)
		return 0;
	int half = 1 << (n - 1);			// ����(2^(n-1))
	if (r < half && c < half)
		return visit(n - 1, r, c);
	if (r < half && c >= half)
		return half * half + visit(n - 1, r, c - half);
	if (r >= half && c < half)
		return 2 * half * half + visit(n - 1, r - half, c);
	if (r >= half && c >= half)
		return 3 * half * half + visit(n - 1, r - half, c - half);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,r,c;
	cin >> n >> r >> c;
	cout << visit(n, r, c);
	return 0;
}
