/*
	Day: 2023.05.15
	참고 : 백트래킹 (연습문제3)
*/
#include <iostream>
using namespace std;
int N, S; // N: 정수의 갯수 S: 부분수열 중에서 수열 원소의 합이 될 정수
int arr[22];	// arr: 정수들 
int cnt;		// cnt: 조건에 맞는 부분집합의 갯수

void func(int a, int b) {	// a: 부분집합의 원소의 갯수, b: 부분집합 원소의 합
	if (a == N) {		// 원소의 갯수가 다 찼을때
		if (b == S) cnt++;	// 부분 집합 원소의 합이 조건에 달성했때 cnt++
		return;
	}
	func(a + 1, b);				// 
	func(a + 1, b + arr[a]);	// 부분 집합 원소의 합 증가

}
int main() {
	ios::sync_with_stdio(false);	// 지연시간 줄이기
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> S;
	
	for (int i = 0; i < N; i++) { // N개의 정수 입력
		cin >> arr[i];	
	}
	func(0, 0);
	if (S == 0)cnt--;
	cout << cnt;
}
