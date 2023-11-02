#include <iostream>
#include <deque>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	deque<int> DQ;
	int N, M;
	cin >> N >> M;

	for (int i = 1; i <= N; i++) { //N만큼 dq 생성
		DQ.push_back(i);
	}

	int cnt = 0;

	while (M--) {
		int num;
		cin >> num;

		int index = 0;
		for (int i = 0; i < DQ.size(); i++) { //입력된 숫자와 동일한 인덱스를 찾아서
			if (DQ[i] == num) {
				index = i;
				break;
			}
		}

		if (index <= DQ.size() / 2) { //앞에서부터 가는 2번 연산이 빠른 경우 
			for (int i = 0; i < index; i++) { //해당 수가 맨 앞으로 올때까지
				DQ.push_back(DQ.front());  //회전큐이니 프론트를 맨뒤로 옮김
				DQ.pop_front();
				cnt++;
			}
			DQ.pop_front(); 
		}
		else { //뒤에서부터 가는 3번 연산이 빠른 경우
			for (int i = 0; i < DQ.size() - index; i++) { //해당 수가 맨 뒤로 올떄까지
				DQ.push_front(DQ.back()); //백을 맨 앞으로 옮김
				DQ.pop_back();
				cnt++;
			}
			DQ.pop_front();
		}
	}

	cout << cnt;
	
	return 0;
}
