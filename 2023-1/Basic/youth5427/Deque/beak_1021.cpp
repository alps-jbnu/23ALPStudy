/*
	Day: 2022.03.24
	참고 : deque(양방향 순환 큐)
*/
#include <iostream>
#include <queue>
using namespace std;

int main() {
	deque<int> q;
	int N = 0;	// N : 큐의 크기 >=50
	int M = 0;	// M : 뽑아내려고 하는 수의 갯수 <= N
	int left = 0, right = 0;
	int count = 0; // 최솟값

	cin >> N >> M;

	for (int i = 1; i < N + 1; i++) q.push_back(i);	// 사람 수 만큼 숫자 입력

	while(M--) {
		int point = 0; // 뽑아내려는 수의 위치
		cin >> point;
		
		for (int i = 0; i < N; i++) {
			if (q[i] == point) {
				left = i; right = q.size() - i;	
				// *반복문 돌릴 때마다 deque 사이즈가 변경되기 때문에, right에서 N보단 q.size() 사용!!
				break;
			}
		}
		if (left > right) { 
			count++;
				// *left > right인 경우는 맨 마지막 숫자가 앞으로 와야 하기 때문에 이동횟수를 +1 더 해줘야 한다.
			while (q.back() != point) {
				q.push_front(q.back());
				q.pop_back();
				count++;
			}
			q.pop_back();
		}
		else {
			while (q.front() != point) {
				q.push_back(q.front());
				q.pop_front();
				count++;
			}
			q.pop_front();
		}
	}
	cout << count;
	return 0;
}
