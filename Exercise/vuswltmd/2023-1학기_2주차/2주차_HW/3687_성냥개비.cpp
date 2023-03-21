#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int T;
int num[10] = {0, 0, 1, 7, 4, 2, 0, 8, 10, 18};
long long min_DP[105];

void min_calculate() {
	for (int i = 1; i <= 9; i++) {
		min_DP[i] = num[i];
	}
	min_DP[6] = 6;

	for (int i = 10; i <= 100; i++) {
		min_DP[i] = 9999999999999999;
		for (int j = 2; j < 8; j++) {
			min_DP[i] = min(min_DP[i], min_DP[i - j] * 10 + num[j]);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> T;

	while (T--) {

		min_calculate();
		int matchstick;
		cin >> matchstick;

		cout << min_DP[matchstick] << ' ';

		// ÃÖ´ë(È¦¼ö, Â¦¼ö ³ª´©¾î¼­)
		while (matchstick) {
			if (matchstick % 2 != 0) {
				cout << 7;
				matchstick -= 3;
			}
			else {
				cout << 1;
				matchstick -= 2;
			}
		}
		cout << "\n";
	}
}


