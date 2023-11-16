/*
	Day: 2023.11.14
	참고 :
*/
#include <iostream>
#include <string>
using namespace std;
int Z(int N, int r, int c) {
	if (N == 0) return 0;
	int half = 1 << (N - 1);	// half: 2^(n-1) // entire: 2^(n-1) * 2^(n-1)
	// 4등분 중
	// 왼쪽 상단
	if (r < half && c < half) {
		return Z(N - 1, r, c);
	}
	// 오른쪽 상단
	if (r < half && c >= half) {
		return half * half + Z(N - 1, r, c - half);
	}
	// 왼쪽 하단
	if (r >= half && c < half) {
		return 2*half * half + Z(N - 1, r-half, c);
	}
	// 오른쪽 하단
	return 3 * half * half + Z(N - 1, r - half, c-half);
}

int main() {
	ios::sync_with_stdio(false);	// 지연시간 줄이기
	cin.tie(NULL);
	cout.tie(NULL);

	int N, r, c;	// r행(세로) c열(가로)
	cin >> N >> r >> c;
	cout << Z(N, r, c);
}
