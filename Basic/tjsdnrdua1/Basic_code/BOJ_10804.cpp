#include<iostream>
#include<algorithm>
using namespace std;
int a[21];
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 1; i < 21; i++) a[i] = i;
	int tc = 10;
	while (tc--) {
		int i; int f;
		cin >> i >> f;
		reverse(a + i, a + f + 1);
	}
	for (int i = 1; i < 21; i++) cout << a[i]<<" ";
}
