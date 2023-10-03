
#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false);	// 지연시간 줄이기
	cin.tie(NULL);
	cout.tie(NULL);

	queue<int> q;
	int N = 0;
	cin >> N;
	
	for (int i = 1; i < N+1; i++) q.push(i);

	for (int i = N; i > 1; i--) {
		q.pop();
		q.push(q.front());
		q.pop();
	}
	cout << q.front();
	return 0;
}
