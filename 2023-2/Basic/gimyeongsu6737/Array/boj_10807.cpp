#include <iostream>
using namespace std;
int num[100];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	int v;
	int cnt = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	cin >> v;
	for (int i = 0; i < n; i++) {
		if (v == num[i]) cnt++;
	}
	cout << cnt;

}