#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	deque<int> dq;
	string str;
	int N, X;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> str;

		if (str == "push_front X") {
			cin >> X;
			dq.push_front(X);
		}
		else if (str == "push_back") {
			cin >> X;
			dq.push_back(X);
		}
		else if (str == "pop_front") {
			if (dq.empty()) {
				cout << -1 << '\n';
			}
			else {
				cout << dq.front() << '\n';
				dq.pop_front();
			}
		}
		else if (str == "pop_back") {
			if (dq.empty()) {
				cout << -1 << '\n';
			}
			else {
				cout << dq.back() << '\n';
				dq.pop_back();
			}
		}
		else if (str == "size")
			cout << dq.size() << '\n';
		else if (str == "empty") {
			if (dq.empty())
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
		}
		else if (str == "front") {
			if (dq.empty()) {
				cout << -1 << '\n';
			}
			else {
				cout << dq.front() << '\n';
			}
		}
		else if (str == "back") {
			if (dq.empty()) {
				cout << -1 << '\n';
			}
			else {
				cout << dq.back() << '\n';
			}
		}
	}
}
