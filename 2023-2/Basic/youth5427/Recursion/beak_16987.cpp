/*
	Day: 2023.11.13
	참고 : 
*/
#include <iostream>
#include <math.h>
using namespace std;
int S[300], W[300];	// 내구도, 무게
int N;	// 갯수
int cnt=0;	// 카운트
int mx=0;		// 최대치
void Egg(int a) {// a번째 달걀
	if (a == N) {
		mx = max(cnt, mx);
		return;
	}
	// 내구도가 0이하라면 
	if (S[a] < 1 || cnt == N - 1) {	//cnt == N - 1 ??
		Egg(a + 1);
		return;
	}
	for (int i = 0; i < N; i++) {
		if (i == a || S[i] <= 0) continue;	// 재귀로 다음거 칠려 했는데 없으면 넘어감.
		S[a] -= W[i];
		S[i] -= W[a];
		if (S[a] <= 0) cnt++;
		if (S[i] <= 0) cnt++;
		Egg(a + 1);
		if (S[a] <= 0) cnt--;
		if (S[i] <= 0) cnt--;
		S[a] += W[i];
		S[i] += W[a];
	}
	

}

int main() {
	ios::sync_with_stdio(false);	// 지연시간 줄이기
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	
	for (int i = 0; i < N; i++) {
		cin >> S[i] >> W[i];
	}
	Egg(0);
	cout << mx;

}
