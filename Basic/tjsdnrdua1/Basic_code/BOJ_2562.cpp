#include<iostream>
using namespace std;

int n, max_elem, max_idx;
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 1; i < 10; i++) {
		cin >> n;
		if (n > max_elem) {
			max_elem = n;
			max_idx = i;
		}
	}
	cout << max_elem << '\n' << max_idx;
}
