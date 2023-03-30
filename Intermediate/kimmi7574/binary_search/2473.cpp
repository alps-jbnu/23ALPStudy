#include <bits/stdc++.h>
using namespace std;

int N;
long long solution[5000];
long long result = 3000000001;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> solution[i];
	}

	sort(solution, solution + N);

	long long a = 0, b = 0, c = 0;

	for (int i = 0; i < N - 2; i++) { //i로 고정
		int left = i + 1;	//left로 범위 좁혀나가면서 찾기
		int right = N - 1;	//right "

		while (left < right) {
			long long sum = solution[i] + solution[left] + solution[right];
			if (abs(sum) < result) {
				result = abs(sum);
				a = solution[i];
				b = solution[left];
				c = solution[right];
			}

			if (sum < 0)
				left++;
			else
				right--;
		}
	}

	long long result[3] = { a, b, c };
	sort(result, result + 3);
	
	for (int i = 0; i < 3; i++) {
		cout << result[i] << " ";
	}

	return 0;
}