#include<iostream>
using namespace std;
long long fun1(long long a, long long b, long long c) {
	if (b == 1) {
		return a % c;
 	}
	long long val = fun1(a, b / 2, c);
	val = val * val % c;
	if (b % 2 == 0) {
		return val;
	}
	return val * a % c;
}
int main() {
	long long A, B, C;
	cin >> A >> B >> C;
	cout << fun1(A, B, C);
}
