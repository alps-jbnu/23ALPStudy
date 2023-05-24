#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, k;
	cin >> n >> k;

	queue<int>q;
	for (int i = 1; i <= n; i++) {
		q.push(i); //1~n을 담은 큐 만들기
	}
	cout << "<";

	while (q.size() > 1) {
		for (int i = 1; i < k; i++) {
			int tmp = q.front();
			q.pop(); //k-1번째까지 pop
			q.push(tmp); //뒤로 push
		}
		cout << q.front() << ", "; //맨 앞으로 온 k 출력
		q.pop();
	}
	cout << q.front() << ">\n"; //마지막 출력
}