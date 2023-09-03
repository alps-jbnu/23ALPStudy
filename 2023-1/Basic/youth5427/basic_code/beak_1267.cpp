/*
	Day: 2023.03.11
	참고 :
*/
#include <iostream>
using namespace std;

int main() {
	int num = 0, time = 0;
	cin >> num;				// num: 통화한 횟수

	int Y = 0, M = 0;		// [Y: 영식, M: 민식] 요금 계산
	for (int i = 0; i < num; i++) {
		cin >> time;		// 통화 시간 입력
		Y += (time / 30 + 1) * 10;
		M += (time / 60 + 1) * 15;
	}
	if (Y < M) cout << "Y " << Y << endl;
	else if(Y == M) cout << "Y " << "M " << Y << endl;
	else cout << "M " << M << endl;
}