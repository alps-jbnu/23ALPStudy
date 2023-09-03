#include <iostream>
using namespace std;

long long int func(long long int a, long long int b, long long int c) {
	if (b == 1) return a % c;
	long long int val = func(a, b / 2, c);
	val = val * val % c;
	if (b % 2 == 0) return val;
	else if (b % 2 == 1) return val * a % c;
}

int main(void) {
	long long int a, b, c;
	cin >> a >> b >> c;

	cout << func(a, b, c) << '\n';

	return 0;
}
