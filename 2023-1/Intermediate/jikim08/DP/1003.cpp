#include <iostream>
#include <vector>
using namespace std;

int main() {
	int T;
	cin >> T;
	for (; T > 0; T--) {
		int N;
		cin >> N;
		vector<int> fibo0(N + 1);
		vector<int> fibo1(N + 1);
		fibo0[0] = 1;
		fibo1[0] = 0;
		fibo0[1] = 0;
		fibo1[1] = 1;

		for (int i = 2; i <= N; i++) {
			fibo0[i] = fibo0[i - 1] + fibo0[i - 2];
			fibo1[i] = fibo1[i - 1] + fibo1[i - 2];
		}

		cout << fibo0[N] << ' ' << fibo1[N] << endl;

	}
}
