#include <iostream>
using namespace std;
int	main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = n; j > i; j--) {
			cout << "*";
		}
		cout << '\n';
	}
}
