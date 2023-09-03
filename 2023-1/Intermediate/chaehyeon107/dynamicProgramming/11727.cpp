#include <bits/stdc++.h>
using namespace std;

int d[1002];
int mod = 10007;
 
int main(void) {
	int n;
	cin >> n;
	d[0] = 0;
	d[1] = 1;
	d[2] = 3;
	for(int i = 3; i <= n; i++)
		d[i] = (d[i-1] + d[i-2] * 2) % mod;
	cout << d[n];
} 
