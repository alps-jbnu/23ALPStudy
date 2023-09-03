/*
	Day: 2023.05.10
	참고 : 재귀
*/
#include <iostream>
using namespace std;
int arr[128][128];
int count1[2];	// 0, 1 의 갯수
bool check(int a, int b, int N) {
	for (int i = a; i < a + N; i++) {
		for (int j = b; j < b + N; j++) {
			if (arr[a][b] != arr[i][j])
				return false;
		}
	}
	return true;
}

void Recu(int a, int b, int N) {
	if (check(a, b, N)) {
		count1[arr[a][b]]++;
		return;
	}
	int c = N / 2;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			Recu(a + (c * i), b +( c * j), c);
		}
	}

}
int main() {
	ios::sync_with_stdio(false);	// 지연시간 줄이기
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}
	Recu(0, 0, N);
	for (int i = 0; i < 2; i++) {
		cout << count1[i] << '\n';
	}
}
