#include <bits/stdc++.h>
using namespace std;

int main() {
	stack<pair<long long int,long long int>> s;
	long long int cnt = 0;
	long long int n, input;
	cin >> n;
	cin >> input;
	s.push({ input,1 });
	n--;
	while (n--) {
		cin >> input;
		if (input < s.top().first) {
			//내림차순: 계속 입력받는다
			s.push({ input,1 });
		}
		else if (input == s.top().first) {
			//같은 수: 같은 수 끼리 중첩한다 =>top스택의 second에 ++
			long long int mem = s.top().second;
			s.pop();
			s.push({ input,mem + 1 });
		}
		else if (input > s.top().first) {
			//오름차순: 제거 연산 진행, 마지막 스택에 대한 예외처리 필요
			while (!s.empty()) {//input보다 큰 수가 나오기 전까지 제거
				if (input > s.top().first) {
					if (s.top().second > 1) {//중첩된 항목인지 검사
						long long int n = s.top().second;
						s.pop();
						if (s.size() < 1) {
							cnt = cnt + n + n * (n - 1) / 2;
						}
						else {
							cnt = cnt + 2 * n + n * (n - 1) / 2;
						}
					}//중첩되지 않았다면
					else {
						s.pop();
						if (s.size() < 1) {
							cnt += 1;
						}
						else {
							cnt += 2;
						}
					}
				}
				else {
					break;
				}
			}
			if (s.empty()) {
				s.push({ input,1 });
			}
			else {
				if (input == s.top().first) {
					//같은 수: 같은 수 끼리 중첩한다 =>top스택의 second에 ++
					long long int mem = s.top().second;
					s.pop();
					s.push({ input,mem + 1 });
				}
				else {
					s.push({ input,1 });
				}
			}
		}
	}
	while (!s.empty()) {
		if (s.top().second > 1) {//중첩된 항목인지 검사
			long long int n = s.top().second;
			s.pop();
			if (s.size() < 1) {
				cnt = cnt + n * (n - 1) / 2;
			}
			else {
				cnt = cnt + n + n * (n - 1) / 2;
			}
		}//중첩되지 않았다면
		else {
			s.pop();
			if (s.size() < 1) {
				cnt += 0;
			}
			else {
				cnt += 1;
			}
		}
	}
	cout <<cnt;
}
