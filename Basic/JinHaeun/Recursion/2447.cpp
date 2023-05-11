#include <bits/stdc++.h>
using namespace std;

int n;

void star(int n, int x, int y) {
	if((x/n)%3==1 && (y/n)%3==1) cout << " ";
	else if(n/3 == 0) cout << "*";
	else star(n/3, x, y);

}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			star(n, i, j);
		}
		cout << '\n';
	}
}
