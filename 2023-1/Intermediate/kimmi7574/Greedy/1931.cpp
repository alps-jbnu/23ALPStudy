#include <bits/stdc++.h>
using namespace std;

int n;	//회의의 수
pair<int, int> A[100005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int cnt = 0, time = 0;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> A[i].second >> A[i].first;
		/*끝나는 시간이 빠른 순대로 회의 시작을 위해
		  끝나는 시간대로 정렬하기 위해서 끝을 first에 넣어줌*/
	}

	sort(A, A + n);

	for (int i = 0; i < n; i++) {
		if (time <= A[i].second) { //(1, 4) (3, 5) => 4와 3비교인데
			cnt++;				   //위에서 시작과 끝 거꾸로 넣어서 sec와 time비교
			time = A[i].first;    //(4, 1) (5, 3)으로 배열에 저장 but, 윗줄과 똑같이 비교하면 됨.
			//a.fir = 끝나는 시간!!!
		}
	}

	cout << cnt;
}