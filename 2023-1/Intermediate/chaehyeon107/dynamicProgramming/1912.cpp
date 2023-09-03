#include <bits/stdc++.h>
using namespace std;

int d[100005], s[100005];
int n;

int main(void) {
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> s[i];
		d[i] = s[i];
	}
	for(int i = 1; i <= n; i++) 
		d[i] = max(d[i], d[i-1] + s[i]);
	cout << *max_element(d+1, d+n+1);
}
