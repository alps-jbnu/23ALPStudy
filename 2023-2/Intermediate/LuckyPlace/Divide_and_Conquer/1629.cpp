#include <iostream>
#include <cmath>
using namespace std;

long long power(long long a, long long b, long long c)
{
	if (b == 0)
		return 1;
	if (b == 1)
		return a % c;

	long long temp = power(a, b / 2, c) % c;
	if (b % 2 == 0)
		return temp * temp % c;
	else
		return temp * temp % c * a % c;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long A, B, C;
	cin >> A >> B >> C;
	cout << power(A, B, C);

	return 0;
}
