#include <iostream>
using namespace std;
int	main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	int flag = 1;
	for (int i = 0; i < n; i++) {
		for (int j = n; j > i + 1; j--) {
			cout << " ";
		}
		for (int k = 0; k < flag; k++) {
			cout << "*";
		}
		
		flag = 2 * (i + 2) - 1;
		cout << '\n';
	}
}
