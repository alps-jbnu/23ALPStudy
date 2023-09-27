#include <bits/stdc++.h>
using namespace std;
int arr[500001] = { 0, };

int main(void) {
	int n, input;
	stack<pair<int, int>> s;//<탑높이,탑의자리수>
	cin >> n;
	cin >> input;
	s.push({ input,1 });//일단하나 집어넣기
	for (int i = 2; i <= n; i++) {
		cin >> input;
		if (input > s.top().first) {//기존 탑보다 높은 탑이 들어올 경우, 그 탑보다 작은 탑들을 없엔다 6421에5추가?: 65
			while (input > s.top().first) {
				//작은 탑 들을 없애는 과정 작은 탑의 위치에 해당하는 배열에
				int now = s.top().second; s.pop();
				if (s.empty()) break;//예외처리, 스택이 하나 남아있을때 pop한 상태로 다음줄 s.top하면 오류
				arr[now] = s.top().second;//어느 위치의 탑에서 수신받는지(앞꺼는s.top().second으로 안다) 적는다
			}
		}
		s.push({ input,i });//자신보다 작은 앞 숫자들 모두 삭제하고 삽입
	}

	while (!s.empty()) {//남은 내림차순 작업 백준 예제의 경우 for루프가 끝나면 9,7,4 크기의 탑이 남는다 얘네끼리도 수신관계 적어줘야함
		int now = s.top().second; s.pop();
		if (s.empty()) break;
		arr[now] = s.top().second;
	}

	for (int i = 1; i <= n; i++)//답 출력
		cout << arr[i] << ' ';
}
