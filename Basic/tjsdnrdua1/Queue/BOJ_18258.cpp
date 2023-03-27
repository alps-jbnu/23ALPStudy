#include <iostream>
using namespace std;
const int MX = 2000005;
int dat[MX];
int head = 0; int tail = 0;
void push(int x) {
	dat[tail] = x;
	tail = (tail + 1 + MX) % MX;
}
void pop() { head = (head + 1 + MX) % MX; }
int size() { return ((tail + MX) - head) % MX; }
bool empty() { return !(tail - head); }
int front() { return dat[head]; }
int back() { return dat[tail-1]; }
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	while (N--) {
		string cmd;
		cin >> cmd;
		if (cmd == "push") {
			int add;
			cin >> add;
			push(add);
		}
		else if (cmd == "pop") {
			if (empty()) cout << -1 << '\n';
			else {
				cout << front() << '\n';
				pop();
			}
		}
		else if (cmd == "size") {
			cout << size() << '\n';
		}
		else if (cmd == "empty") cout << empty() << '\n';
		else if (cmd == "front") {
			if (empty()) cout << -1 << '\n';
			else cout << front() << '\n';
		}
		else if (cmd == "back") {
			if (empty()) cout << -1 << '\n';
			else cout << back() << '\n';
		}
	}
}
