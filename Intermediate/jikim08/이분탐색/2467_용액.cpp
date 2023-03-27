#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

pair<int,int> B_search(vector<int> sol, int n) {
	int left = 0, right = n - 1;
	int a, b;
	int sum = INT_MAX;

	while (left < right) {
		int tmp = sol[left] + sol[right];

		if (abs(tmp) < abs(sum)) {
			sum = tmp;
			a = sol[left];
			b = sol[right];
		}

		if (tmp == 0) {		//0이면 정답값이므로 리턴
			return { a, b };
		}
		else if (tmp > 0) {		//더한 값이 0보다 크면 right값이 더 큰 값이므로 right를 줄여줘야함
			right--;
		}
		else {
			left++;
		}
	}
	return { a,b };
}

int main() {
	int n;
	cin >> n;
	vector<int> solution(n);
	for (int i = 0; i < n; i++) {
		cin >> solution[i];
	}
	pair<int, int> answer = B_search(solution, n);
	cout << answer.first << ' ' << answer.second;
}
