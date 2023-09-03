/*

	Day: 2022.03.22	
	참고 : queue(큐), 선입선출

*/

#include <iostream>
#include <queue>

using namespace std;

int main() {

	queue<int> q;

	int N = 0;	// N명의 사람

	int K = 0;	// 양의 정수 K 번째 사람이 사라짐.

	cin >> N >> K;



	for (int i = 1; i < N + 1; i++) q.push(i);	// 사람 수 만큼 숫자 입력

	cout << "<";

	while (q.size() != 0) {
		for (int i = 1; i < K; i++) {			// 앞에 K명 뒤로 옯기고 삭제
			q.push(q.front());
			q.pop();
		}

		cout << q.front();						// 사라질 사람 출력
		q.pop();								// K번째 사람 삭제
		if (q.size() != 0)
			cout << ", ";
	}
	cout << ">";

	return 0;

}