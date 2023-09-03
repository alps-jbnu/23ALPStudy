#include <bits/stdc++.h>
using namespace std;

int n, tmp = 0, ans = 0;
int a[1002];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++) 
		cin >> a[i];
	sort(a, a+n);
	for(int i = 0; i < n; i++) 
		ans += a[i] * (n-i); 
	cout << ans;
} 
