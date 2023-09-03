#include <iostream>
using namespace std;
int	main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	int flag = 0;
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < flag; k++) {
			cout << " ";
		}
		for (int j = n; j > i; j--) {
			cout << "*";
		}
		flag++;
		cout << '\n';
	}
}
