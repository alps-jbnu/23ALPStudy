/*
	Day: 2022.03.06
	참고 : queue(큐)
*/
#include <iostream>
#include <queue>
using namespace std;

int main() {
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
