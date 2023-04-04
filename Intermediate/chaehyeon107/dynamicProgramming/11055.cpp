#include <bits/stdc++.h>
using namespace std;

int d[1002], s[1002];
 
int main(void) {
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> s[i];
		d[i] = s[i];
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < i; j++) {
			if(s[i] > s[j]) d[i] = max(d[j] + s[i], d[i]);
		}
	}
	cout << *max_element(d, d+n);
}
