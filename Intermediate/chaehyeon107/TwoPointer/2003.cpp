#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10002];
int st = 0, en = 0, cnt = 0; 

int main(void) {
	cin >> n >> m;
	for(int i = 0; i < n; i++) 
		cin >> arr[i];
	int subtotal = arr[en];
	for(st = 0; st < n; st++) {
		while(en < n) {
			if(subtotal < m) {
				en++;
				subtotal += arr[en];
			}
			if(subtotal >= m) {
				if(subtotal == m) cnt++;
				break;
			}
		}
		subtotal -= arr[st];
	}
	cout <<cnt;
}
