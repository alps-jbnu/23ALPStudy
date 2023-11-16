#include <iostream>
#include <queue>

using namespace std;

int main() {
	queue<int> Q;
	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		Q.push(i);
	}

	int v;
	while (1) {
		v = Q.front(); //제일 앞에 있는 변수 저장
		Q.pop(); //삭제
		if (Q.empty()) {
			break;
		}
		Q.push(Q.front()); //제일 앞에 있는 수 뒤로 보내기
		Q.pop(); //삭제
	}

	cout << v;

	return 0;
}
