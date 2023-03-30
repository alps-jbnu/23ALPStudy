#include <bits/stdc++.h>
using namespace std;

int s[1002], d[1002];
int cnt = 0;

int main(void) {
	int n; 
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> s[i];
		d[i] = 1;
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < i; j++) {
			if(s[i] > s[j]) d[i] = max(d[i], d[j] + 1); 
		}
	}
	cout << *max_element(d, d+n);
}
