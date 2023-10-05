
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
		int temp = 0;
		cin >> temp;
		if (temp == 0) {
			s.pop();
		}
		else s.push(temp);
	}
	int sum = 0;
	//for (int i = 0; i < s.size(); i++){ //왜 안될까?
	while(!s.empty()) {
		sum += s.top();
		s.pop();
	}
	cout << sum << '\n';
}
