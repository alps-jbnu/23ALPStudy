/*
	Day: 2023.05.01
	참고 : 재귀 (연습문제2)
*/
#include <iostream>
using namespace std;

void hano(int a, int b, int n) {// n개의 원판을 a기둥에서 b기둥으로 옮기는 방법

	if (n == 1) {
		cout << a << " " << b << '\n';
		return;
	}
	hano(a, 6 - a - b, n - 1);
	cout << a << " " << b << '\n';
	hano(6 - a - b, b, n - 1);
	

}
int main() {
	ios::sync_with_stdio(false);	// 지연시간 줄이기
	cin.tie(NULL);
	cout.tie(NULL);

	int n = 0;
	cin >> n;
	
	cout << (1 << n) - 1 << "\n";	// 비트 연산자 질문
	hano(1, 3, n);
	

}
