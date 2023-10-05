/*
	Day: 2023.09.27
	참고 : 실패
*/

#include <iostream>
#include <stack>

using namespace std;

int main() {
	ios::sync_with_stdio(false);	// 지연시간 줄이기
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n = 0;
	cin >> n;

	stack<pair<int, int>> s;	// 사람 키, 스택쌓인 사람들중 가장 큰 키
	int high = 0; // 키차이
	int count = 0; // 서로 볼 수 있는 쌍 수

	for(int i = 0; i < n; i++) {
		int h = 0;
		cin >> h;
		while (!s.empty() && s.top().second <= h) {// 스택이 비지 않고, 새로 입력된수가 기존보다 더 큰 경우
			
			
			s.pop();
		}
		if (!s.empty()) {
			count++;
		}
			
		s.push({h, high});
		
	}
	cout << high;
}
