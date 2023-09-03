#include <iostream>
#include <deque>
using namespace std;

int main(int argc, char** argv) {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	deque<int> dq;
	int N, M; //큐의 크기N, 뽑아내려는 개수M
	int left, right;
	int cnt = 0;
	
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		dq.push_back(i);
	}
	while (M--) {
		int num;
		cin >> num; //뽑을 수의 위치 입력 받기

		for (int i = 0; i < dq.size(); i++) {
			if (dq[i] == num) { //덱 원소의 위치가 입력받은 위치와 같다면
				left = i;
				right = dq.size() - i; //이동 횟수가 적은 방향 찾기
				break;
			}
		}
		if (left <= right) {
			while (1) {
				if (dq.front() == num) //주어진 수가 프론트가 될 때까지
					break;

				dq.push_back(dq.front());
				dq.pop_front(); // 왼쪽으로 한 칸
				cnt++; // 카운트 하며 반복
			}
			dq.pop_front();
		}
		else {
			cnt++;
			while (1) {
				if (dq.back() == num)
					break;

				dq.push_front(dq.back());
				dq.pop_back();
				cnt++;
			}
			dq.pop_back();
		}
	}
	cout << cnt;

	return 0;
}