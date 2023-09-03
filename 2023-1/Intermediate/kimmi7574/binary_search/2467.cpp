#include <bits/stdc++.h>
using namespace std;

int n;	//전체 용액의 수
int solution[100002];
int resA, resB;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> solution[i];
	}

	int left = 0;
	int right = n - 1;

	int sum = abs(solution[left] + solution[right]);
	resA = solution[left];
	resB = solution[right];

	while (left < right) {
		int tmp = solution[left] + solution[right];
		if (abs(tmp) < sum) {	// 0에 가까워져야 하니까(작아져야함) tmp가 sum보다 작으면
			sum = abs(tmp);	//sum에 tmp값을 넣어줌
			resA = solution[left];
			resB = solution[right];
		}

		if (tmp < 0)
			left++;
		else
			right--;
	}

	cout << resA << " " << resB << "\n";

	return 0;
}