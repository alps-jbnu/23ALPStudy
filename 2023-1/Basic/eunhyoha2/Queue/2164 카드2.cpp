#include <iostream>
#include <queue>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	queue<int> q;
	int N;
	cin >> N;
	
	for (int i = 1; i <= N; i++) { //주어진 조건 N이 1부터임
		q.push(i);
	}

	while (q.size() > 1) {
		q.pop();
		q.push(q.front());
		q.pop();
	}
	cout << q.front();

	return 0;
}