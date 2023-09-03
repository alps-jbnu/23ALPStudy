/*

	Day: 2023.03.27
	참고 : 스택(stack)

*/

#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);	// 지연시간 줄이기
	cin.tie(NULL);
	cout.tie(NULL);
	int N = 0;
	cin >> N;
	stack<int> s;
	
	for (int i = 0; i < N; i++) {
		string A;
		cin >> A;
		if (A == "push") {
			int temp = 0;
			cin >> temp;
			s.push(temp);
		}
		else if (A == "pop") {
			if (s.empty()) cout << -1 << '\n';
			else {
				cout << s.top() << '\n';
				s.pop();
			}
		}
		else if (A == "size") {
			cout << s.size() << '\n';
		}
		else if (A == "empty") {
			cout << s.empty() << '\n';
		}
		else {
			if (s.empty()) { cout << -1 << '\n'; }
			
			else cout << s.top() << '\n';
		}
	}
}