#include <iostream>
#include <vector>

using namespace std;

int main() {
	int T;
	cin >> T;
	for (; T > 0; T--) {
		int N;
		cin >> N;

		vector<int> stock(N + 1);
		for (int i = 0; i < N; i++) {
			cin >> stock[i];
		}
		stock[N] = 0;

		long long profit = 0;
		int highest = 0;

		for (int i = N - 1; i >= 0; i--) {
			if (highest > stock[i]) {
				profit += highest - stock[i];
			}
			else if (highest < stock[i]) {
				highest = stock[i];
			}
		}
		
		cout << profit << endl;
	}
}
