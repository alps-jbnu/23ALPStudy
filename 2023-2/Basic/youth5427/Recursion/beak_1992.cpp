/*
	Day: 2023.11.13
	참고 :
*/
#include <iostream>
#include <string>
using namespace std;
int arr[64][64];
void tree(int n, int y, int x) {	
	if (n == 1) {
		cout << arr[y][x];
		return;
	}
	bool zero = true, one = true;
	for (int i = y; i < y + n; i++) {
		for (int j = x; j < x + n; j++) {
			// arr 숫자에 따라 0 또는 1을 판단.
			if (arr[i][j])
				zero = false;
			else
				one = false;
		}
	}
	// 해당 부분이 작동해야 하기 때문에 bool을 true로 초기화
	if (zero) {
		cout << 0;
	}
	else if (one) {
		cout << 1;
	}
	else {
		cout << "(";
		tree(n / 2, y, x); //왼쪽 위
		tree(n / 2, y, x + n / 2); //오른쪽 위
		tree(n / 2, y + n / 2, x); //왼쪽 아래
		tree(n / 2, y + n / 2, x + n / 2); //오른쪽 아래
		cout << ")";
	}
	return;
}

int main() {
	ios::sync_with_stdio(false);	// 지연시간 줄이기
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0;
	cin >> N;
	// 숫자를 바로 cin으로 받으면 연속 입력이 안됨.
	// ex. 100010101(x)
	//for (int i = 0; i < N; i++) {
	//	for (int j = 0; j < N; j++) {
	//		cin >> arr[i][j];		// i: y축, j: x축
	//	}
	//}
	for (int i = 0; i < N; i++) {
		string temp;
		cin >> temp;
		for (int j = 0; j < N; j++) {
			arr[i][j] = temp[j] - '0';
		}
	}

	tree(N, 0, 0);
}
