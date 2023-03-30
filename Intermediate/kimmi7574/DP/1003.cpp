#include <bits/stdc++.h>
using namespace std;

int n, t;
int d[100];

//피보나치를 memo하는 방법
int fibonacci(int n) {
	if (n <= 1) {
		return d[n];
	}
	if (d[n] != 0)
		return d[n];
	d[n] = fibonacci(n - 1) + fibonacci(n - 2);
	return d[n];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> t;
	
	//초기값
	d[0] = 0;
	d[1] = 1;
	d[2] = 1;

	for (int i = 0; i < t; i++) {
		cin >> n;
		if (n == 0)		//횟수에 대한 초기값
			cout << "1 0" << '\n';
		else
			cout << fibonacci(n-1) << " " << fibonacci(n)<< '\n';
	}
}