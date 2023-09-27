#include <iostream>

using namespace std;

int main() {
	int N;
	int count[10] = { 0, };
	cin >> N;

	while (N > 0) {
		count[N % 10]++;
		N /= 10;
	}
	count[6] = (count[6] + count[9] + 1) / 2;

	int max = 0;
	for (int i = 0; i < 9; i++) {
		if (max < count[i]) {
			max = count[i];
		}
	}

	cout << max;

	return 0;
}
