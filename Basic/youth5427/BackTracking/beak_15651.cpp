/*
	Day: 2023.05.22
	참고 : 백트래킹
*/
#include <iostream>
using namespace std;
int n, m;
int arr[9] = { -1 };
bool isused[10] = { false };// index으로 찾아가기 때문에 하나 더 선언(9->10)

void func(int k) {
	if (k == m) {		// m개를 모두 택했으면
		for (int i = 0; i < m; i++) {	// arr에 기록한 수 출력
			cout << arr[i] << ' ';
		}
		cout << "\n";
		return;
	}


	for (int i = 1; i <= n; i++) {	// 1부터 n까지 수에 대해
		//if (!isused[i]) {// 숫자 i가 사용되지 않았다면
			arr[k] = i;	// arr에 i를 입력
			//isused[i] = 1;// 숫자 i가 사용됨을 표시
			func(k + 1);// 출력 또는 다음수 정하로 귀납!
			//isused[i] = 0;// 사용됨을 해제하고 다음 i를 확인!
		//}
	}
}
int main() {
	ios::sync_with_stdio(false);	// 지연시간 줄이기
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	func(0);

}
