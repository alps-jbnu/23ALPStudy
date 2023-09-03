#include <bits/stdc++.h>
using namespace std;

long long func(long long a, long long b, long long k) {
	if(b == 1) return a % k;
	long long val = func(a, b/2, k);
	val = val * val % k;
	if(b%2 == 0) return val; //b가 짝수 
	return val * a % k; 
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long a, b, c;
	cin >> a >> b >> c;
	cout << func(a, b, c);
}
