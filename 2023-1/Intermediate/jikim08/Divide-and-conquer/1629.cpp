#include <iostream>
using namespace std;

long long mod(int n1, int n2, int n3) {
	if (n2 == 1) {
		return n1 % n3;
	}
	if (n2 == 0) {
		return 1;
	}
	long long k = mod(n1, n2 / 2, n3) % n3;
	if (n2 % 2 == 0)	return k * k % n3;
	else return k * k % n3 * n1 % n3;
}

int main() {
	int n1, n2, n3;
	cin >> n1 >> n2 >> n3;
	
	cout << mod(n1, n2, n3);
}
