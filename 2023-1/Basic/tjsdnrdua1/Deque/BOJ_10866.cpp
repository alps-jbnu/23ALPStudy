#include<iostream>
using namespace std;
const int MX = 100005;
int dat[2 * MX + 1];
int head = MX; int tail = MX;

void push_front(int x) {
	dat[--head] = x;
}
void push_back(int x) {
	dat[tail++] = x;
}
void pop_front() {
	head++;
}
void pop_back() {
	tail--;
}
int size() {
	return tail - head;
}
bool empty() {
	return !(tail - head);
}
int front() {
	return dat[head];
}
int back() {
	return dat[tail - 1];
}
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N; cin >> N;
	while (N--) {
		string cmd; cin >> cmd;
		if (cmd == "push_front") {
			int add; cin >> add;
			push_front(add);
		}
		else if (cmd == "push_back") {
			int add; cin >> add;
			push_back(add);
		}
		else if (cmd == "pop_front") {
			if (empty()) cout << -1 << '\n';
			else {
				cout << front() << '\n';
				pop_front();
			}
		}
		else if (cmd == "pop_back") {
			if (empty()) cout << -1 << '\n';
			else {
				cout << back() << '\n';
				pop_back();
			}
		}
		else if (cmd == "size") {
			cout << size() << '\n';
		}
		else if (cmd == "empty") {
			cout << empty() << '\n';
		}
		else if (cmd == "front") {
			if (empty())cout << -1 << '\n';
			else cout << front() << '\n';
		}
		else if (cmd == "back") {
			if (empty())cout << -1 << '\n';
			else cout << back() << '\n';
		}
	}
}
