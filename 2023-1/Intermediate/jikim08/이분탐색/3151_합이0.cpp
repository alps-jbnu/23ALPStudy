#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> ability(N);
	
	for (int i = 0; i < N; i++) {
		cin >> ability[i];
	}

	sort(ability.begin(), ability.end());

	long long count = 0;
	for (int i = 0; i < N-1; i++) {
		for (int j = i+1; j < N; j++) {
			int S = ability[i] + ability[j];
			int left = lower_bound(ability.begin() + (j + 1), ability.end(), S * (-1)) - ability.begin();
			int right = upper_bound(ability.begin() + (j + 1), ability.end(), S * (-1)) - ability.begin();

			count += right - left;
		}
	}

	cout << count;
}
