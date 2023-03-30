#include <bits/stdc++.h>
using namespace std;

int d0[100];
int d1[100];

int main(void) {
	d0[0] = 1;
	d0[1] = 0;
	d1[0] = 0;
	d1[1] = 1;
	for(int i = 2; i <= 40; i++) {
		d1[i] = d1[i-1] + d1[i-2];
		d0[i] = d0[i-1] + d0[i-2];
	}
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		cout << d0[n] << " " << d1[n] << '\n';  
	}
}
